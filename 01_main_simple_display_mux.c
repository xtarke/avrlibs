/*
 * 01_main_simple_display.c
 *
 *  Created on: Aug 16, 2018
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */


/* Bibliotecas C e AVR */
#include <avr/io.h>
#include <util/delay.h>

/* Bibliotecas customizadas */
#include "lib/avr_gpio.h"
#include "lib/bits.h"
#include "display/led_display_simple_mux.h"


int main(){
	/* Configura hardware do projeto */
	displaysInit(2);

	while (1){
		displaysWrite(0x75);
	}

	return 0;

}
