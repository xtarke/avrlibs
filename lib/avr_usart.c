/*
 * avr_usart.c
 *
 *  Created on: Mar 27, 2018
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */

#include <stdio.h>
#include <avr/interrupt.h>
#include "avr_usart.h"
#include "bits.h"

static int usart_putchar(char c, FILE *fp);

/* Stream init for printf  */
FILE usart_str = FDEV_SETUP_STREAM(usart_putchar, NULL, _FDEV_SETUP_WRITE);

/* Return stream pointer  */
FILE * get_usart_stream(){
	return &usart_str;
}

void USART_Init(uint16_t bauds){

	USART_0->UBRR_H = (uint8_t) (bauds >> 8);
	USART_0->UBRR_L = bauds;

	/* Disable double speed  */
	USART_0->UCSR_A = 0;
	/* Enable TX and RX */
	USART_0->UCSR_B = SET(RXEN0) | SET(TXEN0) | SET(RXCIE0);
	/* Asynchronous mode:
	 * - 8 data bits
	 * - 1 stop bit
	 * - no parity 	 */
	USART_0->UCSR_C = SET(UCSZ01) | SET(UCSZ00);
}


/* Send one byte: busy waiting */
void USART_tx(uint8_t data) {

	/* Wait until hardware is ready */
	while (!(USART_0->UCSR_A & (1 << UDRE0)));

	USART_0->UDR_ = data;
}

/* Receive one byte: busy waiting */
uint8_t USART_rx() {

	/* Wait until something arrive  */
	while (!(USART_0->UCSR_A & (1 << RXC0)));

	return USART_0->UDR_;
}


static int usart_putchar(char c, FILE *fp){
	USART_tx(c);

	return 0;
}


//ISR(USART_RX_vect){
//
//
//
//
//}
//
//ISR(USART_TX_vect){
//
//
//
//
//}
