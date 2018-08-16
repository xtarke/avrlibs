/*
 * 01_main_simple_gpio.c
 *
 *  Created on: Aug 16, 2018
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */


/* Bibliotecas C e AVR */
#include <avr/io.h>
#include <util/delay.h>

/* Bibliotecas customizadas */
#include "lib/avr_gpio.h"
#include "lib/bits.h"

#define LED_PORT GPIO_B
#define LED_PIN	PB0

#define BTN_PORT GPIO_B
#define BTN_PIN PB1

/**
  * @brief  Configura hardware.
  * @param	Nenhum
  *
  * @retval Nenhum.
  */
void hardware_init(){

	/* Acesso direto: PB0 como saída demais como entrada
	 * como no assembly */
	DDRB = 0b00000001;
	/* Pull ups */
	PORTB = 0b00000010;

	/* OU */

	/* Acesso por struct:
	 * Vantagem da estrutura: agrupamento
	 * dos registradores do periférico */
	GPIO_B->DDR = 0b00000001;
	GPIO_B->PORT = 0b00000010;

	/* OU */

	/* Melhor documentação: macros */
	LED_PORT->DDR = SET(LED_PIN);
	BTN_PORT->PORT = SET(BTN_PIN);
}


int main(){
	/* Configura hardware do projeto */
	hardware_init();

	/* Pisca LED: set/clear + delay */
	while(1){
		SET_BIT(PORTB, LED_PIN);
		_delay_ms(1000);
		CLR_BIT(PORTB,LED_PIN);
		_delay_ms(1000);
	}

	/*  OU   */

	while (1){
		GPIO_SetBit(LED_PORT, LED_PIN);
		_delay_ms(1000);
		GPIO_ClrBit(LED_PORT, LED_PIN);
		_delay_ms(1000);
	}

	return 0;

}
