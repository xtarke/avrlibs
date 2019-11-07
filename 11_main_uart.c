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
	uint8_t data[8] = {0xaa, 0xbb, 0xcc, 0xdd};

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
		if (!is_rx_complete()){
			uart1_rx_pkg_with_irq(data, 4);
			/* Dorme */
			sleep_mode();
		}
		else{
			/* Envia o recebido */
			uart1_tx_pkg_with_irq(data, 4);

			/* Programa o próximo recebimento */
			uart1_rx_pkg_with_irq(data, 4);
		}

		/* Pisca LED */
		CPL_BIT(PORTB, PB5);
	}
}
