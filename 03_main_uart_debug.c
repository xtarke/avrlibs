/*
 * 03_main_uart_debug.c
 *
 *  Created on: Aug 30, 2018
 *      Author: xtarke
 */

#include <avr/io.h>
#include <util/delay.h>

#include "avr_usart.h"


int main(){

	uint8_t x = 0;

	/* Obtem o stream de depuração */
	FILE *debug = get_usart_stream();

	/* Inicializa hardware da USART */
	USART_Init(B9600);


	/* Mensagem incial: terminal do Proteus
	 * utiliza final de linha com '\r' */
	fprintf(debug,"Teste de debug\n\r");

	while (1){

		fprintf(debug, "%d\n\r", x);
		x++;

		_delay_ms(1000);
	}
}
