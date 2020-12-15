/*
 * auto_car.c
 *
 *  Created on: Sep 20, 2019
 *      Author: Renan Augusto Starke
 */


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

#include "avr_gpio.h"
#include "avr_usart.h"
#include "bits.h"


#define MOTOR_PORT_D	GPIO_D
#define MOTOR_PORT_B	GPIO_B
#define PWM1	PD6			/* Arduino D6:  PD6 */
#define PWM1N	PD5			/* Arduino D5:  PD5 */
#define PWM2	PB3			/* Arduino D11: PB3 */
#define PWM2N	PD3			/* Arduino D3:  PD3 */

volatile uint8_t cmd = 0;

int main(){

	char data[8] = {0};

	/* Port init */
	GPIO_D->DDR = 0xff;
	GPIO_B->DDR = 0xff;

	/* Clear all outputs */
	GPIO_B->PORT = 0x00;

	USART_Init(B9600);

	sei();

	while (1){

		uart1_rx_pkg_with_irq((uint8_t *)data,1);

		/* Ativa o modo IDle */
		set_sleep_mode(SLEEP_MODE_IDLE);
		/* Dorme: acorda apenas quando ocorre uma IRQ */
		sleep_mode();

		cmd = data[0];

		/* Move Back */
		if (cmd == 'B'){
			GPIO_ClrBit(MOTOR_PORT_D,PWM1);
			GPIO_ClrBit(MOTOR_PORT_B,PWM2);

			GPIO_SetBit(MOTOR_PORT_D,PWM1N);
			GPIO_SetBit(MOTOR_PORT_D,PWM2N);

			uart1_tx_pkg_with_irq((uint8_t *)"BACK", sizeof("BACK"));
		}

		/* Move Front */
		if (cmd == 'F'){
			GPIO_ClrBit(MOTOR_PORT_D,PWM1N);
			GPIO_ClrBit(MOTOR_PORT_D,PWM2N);

			GPIO_SetBit(MOTOR_PORT_D,PWM1);
			GPIO_SetBit(MOTOR_PORT_B,PWM2);

			uart1_tx_pkg_with_irq((uint8_t *)"FRONT", sizeof("FRONT"));
		}

		/* Move Left */
		if (cmd == 'L'){
			GPIO_ClrBit(MOTOR_PORT_D,PWM1N);
			GPIO_ClrBit(MOTOR_PORT_B,PWM2);
			GPIO_SetBit(MOTOR_PORT_D,PWM2N);

			GPIO_SetBit(MOTOR_PORT_D,PWM1);

			uart1_tx_pkg_with_irq((uint8_t *)"LEFT", sizeof("LEFT"));
		}

		/* Move Right */
		if (cmd == 'R'){
			GPIO_ClrBit(MOTOR_PORT_D,PWM1);
			GPIO_ClrBit(MOTOR_PORT_D,PWM2N);
			GPIO_SetBit(MOTOR_PORT_D,PWM1N);

			GPIO_SetBit(MOTOR_PORT_B,PWM2);

			uart1_tx_pkg_with_irq((uint8_t *)"RIGHT", sizeof("RIGHT"));
		}

		if (cmd == 'S'){
			GPIO_ClrBit(MOTOR_PORT_D,PWM1);
			GPIO_ClrBit(MOTOR_PORT_B,PWM2);

			GPIO_ClrBit(MOTOR_PORT_D,PWM1N);
			GPIO_ClrBit(MOTOR_PORT_D,PWM2N);

			uart1_tx_pkg_with_irq((uint8_t *)"STOP", sizeof("STOP"));
		}

		/* Wait a little */
		_delay_ms(100);

		CPL_BIT(PORTB, PB5);


	}
	return 0;
}
