/*
 * main.c
 *
 *  Created on: Mar 9, 2018
 *      Author: Renan Augusto Starke
 */

#include <avr/io.h>
#include <util/delay.h>

#include "lib/avr_gpio.h"
#include "lib/avr_timer.h"


#include "display/displayTimerMux.h"
#include "bits.h"


int main(){
	uint8_t valor = 0;

	/* Inicialização do display mutiplexado:
	 *  PORTD como barramento de dados
	 *  PORTB como portas de multiplexação.
	 *  2 displays                      	 */
	displaysInit(GPIO_D, GPIO_B, 2);

	/* Incialização do botão como entrada no PORTC, PC0 *
	 * Acesso direto ao registrador. Igual a:
	 *
	 * DDRC = 0x01;		<- Pino 0 como entrada
	 * PORTC = 0x01;    <- Pull up pino 0 ativado 	 */
	GPIO_C->DDR = 0x01;
	GPIO_C->PORT = 0x01;

	/* Configuração do PORTC via gpio_init()
	 * Preenche a estrutura e depois inicializa pela
	 * função */
	GPIO_Init_t port;
	port.GPIO_Mode = GPIO_IN;
	port.GPIO_Pins = (1 << PC0);
	port.GPIO_Pullups = (1 << PC0);
	GPIO_Init(GPIO_C, &port);


	TIMER_1->ICR = 5;


	for (;;){

		/* Verifica se botão foi pressionado */
		if (!tst_bit(PINC,0)) {
			valor++;

			/* Aguarda botão ser solto */
			while (!tst_bit(PINC,0));
		}

		/* Atualiza display */
		displaysWrite(valor);
	}
}


