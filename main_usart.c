/*
 * main_usart.c
 *
 *  Created on: Mar 27, 2018
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */

#include <stdio.h>
#include "util/delay.h"
#include "avr_usart.h"

int main(){

	FILE *usart = get_usart_stream();
	USART_Init(B9600);


	for(;;){

		fprintf(usart, "Hello World\n\r");

		_delay_ms(1000);


	}
}
