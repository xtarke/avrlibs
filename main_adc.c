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
	/* AD como entrada e pull ups */
	GPIO_C->DDR = 0;
	GPIO_C->PORT = 0xFE;

	/* Ref interna de 1V1, Canal 0 */
	ADCS->AD_MUX = SET(REFS0) | SET(REFS0);
	/* Habilita AD:
	 * Conversão contínua
	 * IRQ
	 * Prescaler = 128  */
	ADCS->ADC_SRA = SET(ADEN) | SET(ADSC) | SET(ADATE) |
			SET(ADPS0) | SET(ADPS1) | SET(ADPS2) | SET(ADIE);

	/* Desabilita parte digital de PC0 */
	ADCS->DIDr0.BITS.ADC0 = 1;

	sei();

	while(1);

}

ISR(ADC_vect)
{


}

