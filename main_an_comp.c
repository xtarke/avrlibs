/*
 * main_an_comp.c
 *
 *  Created on: Mar 27, 2018
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */


#include <avr/interrupt.h>
#include "avr_gpio.h"
#include "avr_adc.h"
#include "bits.h"

int main(){

	/* PB0 como saída */
	GPIO_B->DDR = SET(PB0);
	/* Comparadores como entrada e pull ups */
	GPIO_D->DDR = 0;
	GPIO_D->PORT = 0xff;

	/* Desliga LED */
	GPIO_ClrBit(GPIO_B,PB0);

	/* Desabilita as entradas digitais nos pinos AIN0 e AIN1 */
	ADCS->DIDr1.BITS.ADC0 = 1;
	ADCS->DIDr1.BITS.ADC1 = 1;

	/* Habilita IRQ mudança de estado */
	ANCOMP_IRQS->BITS.AC_IE = 1;

	sei();

	while(1);
}

ISR(ANALOG_COMP_vect)
{
   	if(tst_bit(ACSR,ACO))
   		GPIO_SetBit(GPIO_B,PB0);
	else
		GPIO_ClrBit(GPIO_B,PB0);
}
