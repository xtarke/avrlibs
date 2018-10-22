/*
 * main_sin_table.c
 *
 *  Created on: Apr 12, 2018
 *      Author: Renan Augusto Starke
 *      Insituto Federal de Santa Catarina
 */

#include <avr/io.h>
#include "bits.h"
#include "avr_timer.h"
#include "avr_gpio.h"
#include "avr_adc.h"

#include <avr/interrupt.h>

#include <avr/pgmspace.h>
#include <util/delay.h>

#include <stdio.h>

const uint8_t seno[] PROGMEM = { 94,87,81,75,69,63,57,52,46,41,36,32,27,23,19,16,12,
		10,7,5,3,2,1,0,0,0,1,2,3,5,7,10,12,16,19,23,27,32,36,41,46,52,57,63,69,75,81,
		87,94,100,106,113,119,125,131,137,143,148,154,159,164,168,173,177,181,184,188,
		190,193,195,197,198,199,200,200,200,199,198,197,195,193,190,188,184,181,177,173,
		168,164,159,154,148,143,137,131,125,119,113,106,100 };

volatile uint16_t ad_data = 0;

int main(){
	uint8_t i = 0;

	/* AD como entrada e pull ups */
	GPIO_C->DDR = 0;
	GPIO_C->PORT = 0xFE;

	/* Ref AVCC, Canal 0 */
	ADCS->AD_MUX =  SET(REFS0);
	/* Habilita AD:
	 * Conversão contínua
	 * IRQ
	 * Prescaler = 128  */
	ADCS->ADC_SRA = SET(ADEN) | SET(ADSC) | SET(ADATE) |
			SET(ADPS0) | SET(ADPS1) | SET(ADPS2) | SET(ADIE);

	/* Desabilita parte digital de PC0 */
	ADCS->DIDr0.BITS.ADC0 = 1;

	GPIO_D->DDR = SET(PD5);

	TIMER_0->TCCRA = SET(WGM01) | SET(WGM00) | SET(COM0B1);
	TIMER_0->TCCRB = 0b00001001;

	/* Contagem máxima */
	TIMER_0->OCRA = 200;
	TIMER_0->OCRB = 0;

	sei();

	for (;;){
		uint8_t data = pgm_read_byte(&seno[i++]);
		TIMER_0->OCRB = data;

		if (i > 99)
			i = 0;

		/* Função de atraso com par. variável */
		_delay_loop_2(ad_data);
	}

}

ISR(ADC_vect)
{
	ad_data =  ADC;

}

