/*
 * led_display_simple_mux.h
 *
 *  Created on: Mar 20, 2018
 *      Author: Renan Starke
 */

#ifndef DISPLAY_DISPLAYSIMPLEMUX_H_
#define DISPLAY_DISPLAYSIMPLEMUX_H_

#define COM_ANODO
//#define COM_CATODO

#define DISPLAY_DATA_PORT GPIO_D
#define DISPLAY_MUX_PORT GPIO_B

void displaysInit(uint8_t displays);
void displaysWrite(uint8_t hexValue);

#endif /* DISPLAY_DISPLAYSIMPLEMUX_H_ */
