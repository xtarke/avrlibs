/*
 * main_lcd_i2c.c
 *
 *  Created on: Mar 27, 2018
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */

#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include "display/lcd_i2c.h"
#include "avr_usart.h"


#include "avr_twi_master.h"

int main(){
	uint8_t i = 0;
	FILE *lcd_stream = inic_stream_i2c();
	FILE *usart_stream = get_usart_stream();

	/* Debug */
	USART_Init(B9600);

	/* Inicializa modo líder */
	TWI_Master_Initialise();
	sei();

	/* Inicializa LCD através do expansor de E/S */
	inic_LCD_4bits_i2c();

	for(;;) {
		cmd_LCD_i2c(0x80,0);
		fprintf(lcd_stream, "teste: %03d", i++);

		_delay_ms(1000);
	}


}
