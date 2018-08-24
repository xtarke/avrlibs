/*
 * avr_gpio.h
 *
 *  Created on: Mar 9, 2018
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */

#ifndef LIB_AVR_GPIO_H_
#define LIB_AVR_GPIO_H_

#include <avr/io.h>
#include <stdint.h>

#ifndef _IO
	#define _IO volatile uint8_t
#endif

#ifndef _IO16
	#define _IO16 volatile uint16_t
#endif

typedef struct
{
  _IO PIN;		/*!< Read the current state of a INPUT port. */
  _IO DDR;		/*!< Specifies the operating mode for the selected pins. */
  _IO PORT;		/*!< Specifies the pull ups or output state of a OUPUT port.. */
} GPIOx_Type;

#define GPIO_B ((GPIOx_Type *) &PINB)
#define GPIO_C ((GPIOx_Type *) &PINC)
#define GPIO_D ((GPIOx_Type *) &PIND)

#define GPIO_SetBit(GPIO_x, bit) (GPIO_x->PORT |= (1<<bit))
#define GPIO_ClrBit(GPIO_x, bit) (GPIO_x->PORT &= ~(1<<bit))
#define GPIO_CplBit(GPIO_x, bit) (GPIO_x->PORT ^= (1<<bit))
#define GPIO_PortTstBit(GPIO_x, bit) (GPIO_x->PORT &(1<<bit))
#define GPIO_PinTstBit(GPIO_x, bit) (GPIO_x->PIN &(1<<bit))

#endif /* LIB_AVR_GPIO_H_ */

