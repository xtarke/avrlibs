/*
 * displaySimpleMux.h
 *
 *  Created on: Mar 20, 2018
 *      Author: Renan Starke
 */

#ifndef DISPLAY_DISPLAYSIMPLEMUX_H_
#define DISPLAY_DISPLAYSIMPLEMUX_H_

#include "../lib/avr_gpio.h"

void displaysInit(GPIOx_Type *DataPort, GPIOx_Type *MuxPort, uint8_t n);
void displaysWrite(uint8_t hexValue);

#endif /* DISPLAY_DISPLAYSIMPLEMUX_H_ */
