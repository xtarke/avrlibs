/*
 * main_fsm.c
 *
 *  Created on: June 8, 2018
 *      Author: Renan Augusto Starke
 *      Insituto Federal de Santa Catarina
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "avr_gpio.h"
#include "avr_timer.h"
#include "bits.h"


void f_stateA(void);
void f_stateB(void);
void f_stateC(void);
void f_stateD(void);


/* Definição dos estados */
typedef enum {
	STATE_A,
	STATE_B,
	STATE_C,
	STATE_D,
	NUM_STATES
} state_t;

/* Definição da estrutura mantenedora do vetor de estados */
typedef struct {
	state_t myState;
	void (*func)(void);
}fsm_t;

/* Mapeamento entre estado e funções */
fsm_t myFSM[] = {
	{ STATE_A, f_stateA },
	{ STATE_B, f_stateB },
	{ STATE_C, f_stateC },
	{ STATE_D, f_stateD },

};

/* Estado atual */
volatile state_t curr_state = STATE_A;

int main(){

	GPIO_D->DDR = 0xff;

	/* Prescaller */
	TIMER_0->TCCRB = SET(CS02) | SET(CS00);
	/* OVerflow enable */
	TIMER_IRQS->TC0.BITS.TOIE = 1;


	sei();

	for(;;){
		(*myFSM[curr_state].func)();
	}

	return 0;
}


ISR(TIMER0_OVF_vect)
{
	static uint8_t i = 0;

	/* Dummy sync state transition */
	switch (curr_state) {
		case STATE_A:
			if (i > 10){
				i = 0;
				curr_state = STATE_C;
			}

			break;

		case STATE_B:
			if (i > 50){
				i = 0;
				curr_state = STATE_D;
			}
			break;

		case STATE_C:
			if (i > 50){
				i = 0;
				curr_state = STATE_B;
			}
			break;

		case STATE_D:
			if (i > 50){
				i = 0;
				curr_state = STATE_A;
			}
			break;

		default:
			break;
	}

	i++;
}



void f_stateA(void){
	GPIO_SetBit(GPIO_D,0);
}

void f_stateB(void){
	GPIO_D->PORT = 0x05;
}

void f_stateC(void){
	GPIO_D->PORT = 0x80;
}

void f_stateD(void){
	GPIO_D->PORT = 0x00;
}
