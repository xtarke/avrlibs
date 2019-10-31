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

#include <avr/sleep.h>

volatile struct uart_status_struct {
    uint8_t *rx_data;   /*!< Pointer to store received data */
    uint8_t rx_count;   /*!< Number of bytes to receive  */
    uint8_t rx_complete; /*!< True if all bytes are received */

    uint8_t *tx_data;   /*!< Data to send */
    uint8_t tx_count;   /*!< Number of bytes to send  */


} uart_state;

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


void uart1_rx_pkg(uint8_t *data, uint8_t size){
    /* Decrement size and data pointer since transmission start here */
    uart_state.rx_complete = 0;
	uart_state.rx_count = size;
    uart_state.rx_data = data;
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

uint8_t is_rx_complete(){
	return uart_state.rx_complete;
}


ISR(USART_RX_vect){
	/* Get data from hardware */
	uint8_t data = USART_0->UDR_;
	/* Byte counter */
	static uint8_t bytes = 0;

	/* Read received data */
	uart_state.rx_data[bytes++] = data;

	/* Wake up CPU only when a package is received */
	if (uart_state.rx_count == bytes) {
		bytes = 0;
		uart_state.rx_complete = 1;
	}

}

ISR(USART_TX_vect){




}
