/*
 * main_pwm.c
 *
 *  Created on: Apr 12, 2018
 *      Author: Renan Augusto Starke
 *      Insituto Federal de Santa Catarina
 */

#include <avr/io.h>
#include <util/delay.h>
#include "bits.h"
#include "avr_timer.h"
#include "avr_gpio.h"

/**
  * @brief  Configura hardware do timer0 em modo PWM.
  * @param	Nenhum
  *
  * @retval Nenhum.
  */
void timer0_pwm_hardware_init(){

	/* PD5: pino OC0B como saída */
	GPIO_D->DDR |= SET(PD5);

	/* Table 15-6.  Compare Output Mode, Fast PWM Mode */
	/* COM0B1   COM0B0  Desc:
	    0       0       Normal port operation, OC0B disconnected.
	    0       1       Reserved
	    1       0       Clear OC0B on Compare Match, set OC0B at BOTTOM (non-inverting mode)
	    1       1       Set OC0B on Compare Match, clear OC0B at BOTTOM (inverting mode).*/

	/* WGM02, WGM01 WGM00 setados: modo PWM rápido com TOP em OCRA */
	TIMER_0->TCCRA = SET(WGM01) | SET(WGM00) | SET(COM0B1);
	TIMER_0->TCCRB = SET(WGM02) | SET(CS00);

	/* OCRA define frequência do PWM */
	TIMER_0->OCRA = 200;

	/* OCRB define razão cíclica:  OCRB / OCRA */
	TIMER_0->OCRB = 150;
}

/**
  * @brief  Altera a razão cíclica do PWM
  * @param	dutty: valor de 8 bits menor que frequência configurada do PWM
  *
  * @retval Nenhum.
  */
inline void set_dutty(uint8_t dutty){

	if (dutty <= TIMER_0->OCRA)
		TIMER_0->OCRB = dutty;
}


int main(){

	uint8_t valor_pwm = 1;

	/* Configura timer em modo PWM */
	timer0_pwm_hardware_init();

	/* Exeplo: aumenta em 10 a razão cíclica do PWM a cada 100ms */
	while (1){
		set_dutty(valor_pwm);
		valor_pwm+=10;
		_delay_ms(100);
	}
	
	return 0;
}
