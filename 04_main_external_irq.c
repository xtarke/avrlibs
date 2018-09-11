/*
 * main.c
 *
 *  Created on: Mar 9, 2018
 *      Author: Renan Augusto Starke
 */

#include <avr/io.h>
#include <util/delay.h>
/* Cabeçalhos e vetores de interrupções */
#include <avr/interrupt.h>

#include "bits.h"
#include "lib/avr_gpio.h"

/* Modificador volátil: variável alterada fora
 * do fluxo contínuo de operação                */
volatile uint8_t led = 0;

ISR(INT0_vect)
{
	led = 1;
}

ISR(INT1_vect)
{
	led = 0;
}


/* PCINT deve-se testar qual pino gerou a IRQ */
ISR(PCINT1_vect)
{
	if(!TST_BIT(PINC,PC0))
		led = 2;
	else if(!TST_BIT(PINC,PC1))
		led = 4;
	else if(!TST_BIT(PINC,PC2))
		led = 8;
}

int main(){

	/* Todos como saída */
	GPIO_B->DDR = (0xff);

	/* PC0 a PC2 como entrada e pull ups */
	GPIO_C->DDR = ~((1 << PC0) | (1 << PC1) | (1 << PC2));
	GPIO_C->PORT = ~((1 << PC0) | (1 << PC1) | (1 << PC2));

	/* PINOS PD2 e PD3 como entrada e pull ups */
	GPIO_D->DDR  = ~((1 << PD2) | (1 << PD3));   /* DDRD  = ~((1 << PD2) | (1 << PD3)).  */
	GPIO_D->PORT = (1 << PD2) | (1 << PD3);  /* PORTD = (1 << PD2) | (1 << PD3) */

	/* Configuração IRQ externas: INT0 e INT1 na borda de descida */
	EICRA = (1 << ISC01) | (1 << ISC11);
	/* Habilita IRQ do periférico */
	EIMSK = (1 << INT1)  | (1 << INT0);

	/* Configura modo */
	PCICR = 1 << PCIE1;
	/* Habilita IRQ do periférico */
	PCMSK1 = (1 << PCINT10) | (1 << PCINT9) | (1 << PCINT8);

	/* Habilita IRQ global */
	sei();

	for (;;){
		GPIO_B->PORT = led;
	}
}



