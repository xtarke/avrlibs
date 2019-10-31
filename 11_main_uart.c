/*
 * 11_main_uart.c
 *
 *  Created on: Aug 30, 2018
 *      Author: Renan Augusto Starke
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include "bits.h"

#include "avr_usart.h"


int main(){
	uint8_t x = 0;
	uint8_t data[8] = {0};

	DDRB = (1 << PB5);

	/* Obtem o stream de depuração */
	FILE *debug = get_usart_stream();

	/* Inicializa hardware da USART */
	USART_Init(B9600);

	sei();

	/* Ativa o modo IDle */
	set_sleep_mode(SLEEP_MODE_IDLE);


	while (1){
		/* Pára o main até receber os dado da USART */
		if (!is_rx_complete())
			uart1_rx_pkg(data, 4);
		else{
			/* Envia o recebido */
			for (x=0; x < 4; x++)
				USART_tx(data[x]);

			uart1_rx_pkg(data, 4);
		}
		/* Dorme: acorda apenas quando ocorre uma IRQ
		 * Nesse caso da UART */
		sleep_mode();

		/* Pisca LED */
		CPL_BIT(PORTB, PB5);
	}
}
