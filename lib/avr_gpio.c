/*
 * avr_gpio.c
 *
 *  Created on: Mar 9, 2018
 *      Author: Renan Augusto Starke
 */

#include <stdint.h>
#include "avr_gpio.h"


/* Inicializa pinos por refência da porta *
 * usando o "esqueleto" GPIOx_Type  *
 */
void GPIO_Init(GPIOx_Type *GPIO_x,  GPIO_Init_t*  InitStruct){
	if (InitStruct->GPIO_Mode)
		GPIO_x->DDR |= InitStruct->GPIO_Pins;
	else
		GPIO_x->DDR &= ~(InitStruct->GPIO_Pins);

	GPIO_x->PORT |= InitStruct->GPIO_Pullups;
}

