/*
 * 02_main_simple_lcd.c
 *
 *  Created on: Aug 28, 2018
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */

#include <avr/io.h>
#include <util/delay.h>

#include <stdio.h>

#include "avr_gpio.h"
#include "display/lcd.h"


int main(){

	uint8_t x = 0;

	FILE *lcd_stream = inic_stream();
	inic_LCD_4bits();

	while (1){
		/* Vai para primeira linha/coluna */
		cmd_LCD(0x80,0);
		/* Imprime msg */
		fprintf(lcd_stream,"%d", x++);

		_delay_ms(1000);
	}
}
