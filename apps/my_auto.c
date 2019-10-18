/*
 * auto_car.c
 *
 *  Created on: Sep 20, 2019
 *      Author: Renan Augusto Starke
 */


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "avr_gpio.h"
#include "avr_usart.h"
#include "bits.h"


#define MOTOR_PORT	GPIO_B
#define PWM1	PB0
#define PWM1N	PB1
#define PWM2	PB2
#define PWM2N	PB3

volatile uint8_t cmd = 0;

int main(){


	GPIO_B->DDR = 0xff;

	/* Clear all outputs */
	GPIO_B->PORT = 0x00;

	USART_Init(B9600);

	sei();

	while (1){

		GPIO_B->PORT = 0x00;

		/* Move Back */
		if (cmd == 'B'){
			GPIO_ClrBit(MOTOR_PORT,PWM1);
			GPIO_ClrBit(MOTOR_PORT,PWM2);

			GPIO_SetBit(MOTOR_PORT,PWM1N);
			GPIO_SetBit(MOTOR_PORT,PWM2N);
		}

		/* Move Front */
		if ((cmd == 'F') && (!GPIO_PortTstBit(MOTOR_PORT,PWM1N))){
			GPIO_ClrBit(MOTOR_PORT,PWM1N);
			GPIO_ClrBit(MOTOR_PORT,PWM2N);

			GPIO_SetBit(MOTOR_PORT,PWM1);
			GPIO_SetBit(MOTOR_PORT,PWM2);
		}

		/* Move Left */
		if ((cmd == 'L') && (!GPIO_PortTstBit(MOTOR_PORT,PWM1N))){
			GPIO_ClrBit(MOTOR_PORT,PWM1N);
			GPIO_ClrBit(MOTOR_PORT,PWM2);

			GPIO_SetBit(MOTOR_PORT,PWM1);
			GPIO_SetBit(MOTOR_PORT,PWM2N);
		}

		/* Move Right */
		if ((cmd == 'R') && (!GPIO_PortTstBit(MOTOR_PORT,PWM1N))){
			GPIO_ClrBit(MOTOR_PORT,PWM1);
			GPIO_ClrBit(MOTOR_PORT,PWM2N);

			GPIO_SetBit(MOTOR_PORT,PWM1N);
			GPIO_SetBit(MOTOR_PORT,PWM2);
		}

		if (cmd == 'S'){
			GPIO_B->PORT = 0x00;
		}

	}
	return 0;
}



ISR(USART_RX_vect){

	cmd = USART_0->UDR_;

	USART_tx('o');
	USART_tx('k');


}


