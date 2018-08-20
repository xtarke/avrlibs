/*
 * leddisplay.h
 *
 *  Created on: Aug 20, 2018
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */

#ifndef DISPLAY_LEDDISPLAY_H_
#define DISPLAY_LEDDISPLAY_H_

#define COM_ANODO
//#define COM_CATODO

#define DISPLAY_PORT GPIO_B

/**
  * @brief  Configura hardware.
  * @param	Nenhum
  *
  * @retval Nenhum.
  */
void display_init();

/**
  * @brief  Escrevre no display de 7 segmentos.
  * @param	data: valor sem decimal sem conversão. Dados
  * 			são convertidos internamente.
  *
  * @retval Nenhum.
  */
void display_write(uint8_t data);

#endif /* DISPLAY_LEDDISPLAY_H_ */
