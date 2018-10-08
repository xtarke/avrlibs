/*
 * main_an_comp.c
 *
 *  Created on: Oct 08, 2018
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */


#include <util/delay.h>
#include <avr/interrupt.h>
#include "avr_gpio.h"
#include "avr_adc.h"
#include "bits.h"

#include "avr_usart.h"

volatile uint16_t valor_adc = 0;

void adc_init(){

	/* Ref externa no pino AVCC com capacitor de 100n em VREF.
	 * Habiltiação apenas no Canal 0 */
	ADCS->AD_MUX = SET(REFS0);
	/* Habilita AD:
	 * Conversão contínua
	 * IRQ ativo
	 * Prescaler de 128 */
	ADCS->ADC_SRA = SET(ADEN)  |	//ADC Enable
					SET(ADSC)  | 	// ADC Start conversion
					SET(ADATE) |	// ADC Auto Trigger
					SET(ADPS0) | SET(ADPS1) | SET(ADPS2) | //ADPS[0..2] AD Prescaler selection
					SET(ADIE); 		//AD IRQ ENABLE

	/* Desabilita hardware digital de PC0 */
	ADCS->DIDr0.BITS.ADC0 = 1;

}

int main(){

	/* Obtem o stream de depuração */
	FILE *debug = get_usart_stream();

	/* Inicializa hardware da USART */
	USART_Init(B9600);

	/* Inicializa o converor AD */
	adc_init();

	/* Ativa todos IRQs */
	sei();

	/* Exbibe no terminal o valor do AD.
	 * A conversão é realizada conforme o prescaler
	 */
	while(1){
		fprintf(debug, "%d\r", valor_adc);
		_delay_ms(500);
	}

}

ISR(ADC_vect)
{
	/* Lê o valor do conversor AD na interrupção:
	 * ADC é de 10 bits, logo valor_adc deve ser
	 * de 16 bits
	 */
	valor_adc = ADC;

}

