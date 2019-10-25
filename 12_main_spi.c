/*
 * main_spi.c
 *
 *  Created on: May 22, 2018
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */
#include <stdio.h>

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "avr_usart.h"
#include "avr_spi.h"
#include "bits.h"

#define SS PB2

int main(){

	uint8_t seg,min,hora;

	FILE *usart = get_usart_stream();
	USART_Init(B9600);

	SPI_MasterInit();

	while (1){

		//Borda no escravo
		set_bit(PORTB, SS);
		_delay_ms(10);
		clr_bit(PORTB, SS);

		//Trasmite, comando 0x00
		//leitura dos segundosdo RTC
		SPI_Transmit(0x00);
		seg = SPI_SlaveReceive(0x01);
		min = SPI_SlaveReceive(0x02);
		hora = SPI_SlaveReceive(0x03);

		fprintf(usart, "%.2x:%.2x:%.2x\n\r", hora,min,seg);

		_delay_ms(500);
	}
	return 0;
}
