/*
 * displaySimpleMux.c
 *
 *  Created on: Mar 20, 2018
 *      Author: xtarke
 */

#include <stdint.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "../lib/avr_gpio.h"

/* Esqueleto da estrutura para guardar as configurações */
typedef struct displays {
	GPIOx_Type *dataPort;
	GPIOx_Type *muxPort;
	uint8_t n;
	uint8_t muxMask;
} displays_t;

/* Instância da struct para manter as configurações */
displays_t displays;

/* Tabela de convsersão em flash */
const unsigned char convTable[] PROGMEM = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02,
		0x78, 0x00, 0x18, 0x08, 0x03, 0x46, 0x21, 0x06, 0x0E};

/* Inicialização das portas e configurações do display de 7 segmentos */
void displaysInit(GPIOx_Type *DataPort, GPIOx_Type *MuxPort, uint8_t n){

	GPIO_Init_t ports;

	/* segmento A está no LSB */
	ports.GPIO_Pins = 0b01111111;
	ports.GPIO_Mode = GPIO_OUT;
	ports.GPIO_Pullups = 0;
	GPIO_Init(DataPort, &ports);

	/* Ativação do mux no LSB */
	ports.GPIO_Pins = n + 1;
	GPIO_Init(MuxPort, &ports);

	/* Guarda configurações */
	displays.dataPort = DataPort;
	displays.muxPort = MuxPort;
	displays.n = n;
	displays.muxMask = ~(n + 1);
}

/* Very simple display Mux     *
 *                             *
 * Mux hardware pins should be *
 * inverted                    */
void displaysWrite(uint8_t hexValue){

	uint8_t i;
	uint8_t data = hexValue;

	for (i = 0; i < displays.n; i++){

		/* Máscaras para pegar somente um dígito */
		data = (0x0f & hexValue);
		data = pgm_read_byte(&convTable[data]);

		/* Liga os segmentos através da estrutura
		 * de configuração inicializada em displaysInit
		 * Portas são passadas por referência 	 */
		displays.dataPort->PORT = data;
		GPIO_SetBit(displays.muxPort, i);

		/* Obtém próximo dígito  */
		hexValue = hexValue >> 4;
		_delay_ms(10);

		/* Desliga os displays */
		displays.muxPort->PORT &=  displays.muxMask;
	}
}






