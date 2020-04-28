/*
 * 10_main_low_power_modes.c
 *
 *  Created on: Oct 25, 2019
 *      Author: Renan Augusto Starke
 *
 *      baseado em: https://microchipdeveloper.com/8avr:avrsleep
 *
 */

#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>

#include <util/delay.h>

#include "bits.h"

volatile uint8_t WDT_flag = 0;

void WDT_interrupt_enable(void)
{
	/* Watchdog pode operar como um temporizador
	 * WDT possui um oscilador próprio de 128kHz
	 * Abaixo configura-se uma IRQ a cada 2s
	 */

	WDTCSR |= (1<<WDCE) | (1<<WDE);
	/* Configura temporizador do Watchdog para gerar uma
	 * interrupção:
	 */
	WDTCSR = (1<< WDIE) | (1<<WDP2) | (1<<WDP1) | (1<<WDP0);
}


int main(void)
{
	DDRB = (1 << PB5);

	/* Configura interrupção Watchdog Timer */
	WDT_interrupt_enable();

	/* Habilitação geral */
	sei();

    while (1)
    {
		/* O AVR possui os seguintes modos de economia de energia:
		 *
		 * Idle: Desliga apenas a CPU
		 * Power-down: seguintes eventos acordam a CPU
		 * 	- External Reset
		 * 	- Watchdog System Reset
		 * 	- Watchdog Interrupt
		 * 	- Brown-out Reset
		 * 	- 2-wire Serial Interface address match
		 * 	- External level interrupt on INT
    	 * 	- Pin change interrupt
		 * Power-save: Apenas Timer/Counter2 é ativado. Acorda com IRQ.
		 * Stanby: Igual ao power-save, mas oscilador é mantido ligado.
		 * Extended Stanby: idêntico ao Standby.
		 */

    	/* Ativa o modo IDle */
		set_sleep_mode(SLEEP_MODE_IDLE);
		/* Dorme: acorda apenas quando ocorre uma IRQ */
		sleep_mode();

		/* Pisca LED */
		CPL_BIT(PORTB, PB5);
    }
}

ISR(WDT_vect)
{
	WDT_flag = 1;
}

