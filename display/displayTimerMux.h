/*
 * displayTimerMux.h
 *
 *  Created on: Mar 27, 2018
 *      Author: xtarke
 */

#ifndef DISPLAY_DISPLAYTIMERMUX_H_
#define DISPLAY_DISPLAYTIMERMUX_H_

#include "../lib/avr_gpio.h"

void displaysInit(GPIOx_Type *DataPort, GPIOx_Type *MuxPort, uint8_t n);
void displaysWrite(uint8_t hexValue);


#endif /* DISPLAY_DISPLAYTIMERMUX_H_ */
