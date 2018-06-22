/*
 * main.c
 *
 *  Created on: Oct 25, 2016
 *      Author: xtarke
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "bits.h"
#include "avr_i2c.h"

// definido pela NXP (olhar no datasheet)
#define RTC_ADDR 0xD0


int main(){

	uint8_t byte;
	DDRD = 0xff;

	DDRC = (1 << PC4) | (1<<PC5);

	i2c_init();
	sei();

	//0xd0 e' o endereco do RTC
	i2c_write(0x00, 0x00, RTC_ADDR);
	i2c_write(0x07, 0b00010000, RTC_ADDR);

	_delay_ms(100);

	while (1){

		byte = i2c_read(0x00, RTC_ADDR);

		cpl_bit(PORTD, 4);

		_delay_ms(100);
	}
	return 0;
}
