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
#include "avr_timer.h"
#include "bits.h"

#include "avr_usart.h"

volatile uint16_t valor_adc = 0;


/**
  * @brief  Configura hardware do timer0 para IRQ em overflow.
  * @param	Nenhum
  *
  * @retval Nenhum.
  */
void timer0_hardware_init(){

	/* Acesso indireto por struct e bit field: com avr_timer.h */
	TIMER_0->TCCRA = 0;
	TIMER_0->TCCRB = SET(CS02) | SET(CS00);
	TIMER_IRQS->TC0.BITS.TOIE = 1;
}




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

	/* Auto trigger in timer0 overflow */
	ADCS->ADC_SRB = SET(ADTS2);

	/* Desabilita hardware digital de PC0 */
	ADCS->DIDr0.BITS.ADC0 = 1;

}

int main(){

	/* PORTB como saída */
	GPIO_B->DDR = 0xff;

	/* Obtem o stream de depuração */
	FILE *debug = get_usart_stream();

	/* Inicializa hardware da USART */
	USART_Init(B9600);

	/* Inicializa o converor AD */
	adc_init();

	timer0_hardware_init();

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

	GPIO_CplBit(GPIO_B, 1);
}



/* Quando habilitado IRQ de overflow no timer 0*/
ISR(TIMER0_OVF_vect){
	GPIO_CplBit(GPIO_B, 0);
}


