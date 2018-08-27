/*
 * led_display_simple_mux.c
 *
 *  Created on: Mar 20, 2018
 *      Author: xtarke
 */

#include <stdint.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "../lib/avr_gpio.h"

#include "led_display_simple_mux.h"

/* Esqueleto da estrutura para guardar as configurações */
typedef struct displays {
	uint8_t total;
	uint8_t mask;
} displays_t;

/* Instância da struct para manter as configurações */
displays_t displays_info;

/* Tabela de conversão em flash */
const uint8_t convTable[] PROGMEM = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02,
		0x78, 0x00, 0x18, 0x08, 0x03, 0x46, 0x21, 0x06, 0x0E};

/* Tabela de conversão em flash: Catodo comum */
#ifdef COM_CATODO
const uint8_t convTable[] PROGMEM = { ...  };
#endif


void displaysInit(uint8_t displays){

	uint8_t mask = (2 << displays) - 1;

	/* Variáveis de controle */
	displays_info.total = displays;
	displays_info.mask = mask;

	/* Todos os pinos como saída */
	DISPLAY_DATA_PORT->DDR = 0xff;
	DISPLAY_MUX_PORT->DDR = mask;

	displays_info.mask = ~mask;
}




void displaysWrite(uint8_t hexValue){

	uint8_t i;
	uint8_t data = hexValue;

	for (i = 0; i < displays_info.total; i++){

		/* Máscaras para pegar somente um dígito */
		data = (0x0f & hexValue);
		data = pgm_read_byte(&convTable[data]);

		/* Liga os segmentos através da estrutura
		 * de configuração inicializada em displaysInit
		 * Portas são passadas por referência 	 */
		DISPLAY_DATA_PORT->PORT = data;
		GPIO_SetBit(DISPLAY_MUX_PORT, i);

		/* Obtém próximo dígito  */
		hexValue = hexValue >> 4;
		_delay_ms(10);

		/* Desliga os displays */
		DISPLAY_MUX_PORT->PORT &=  displays_info.mask;
	}
}
