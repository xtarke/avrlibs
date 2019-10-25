/*
 * crono.c
 *
 *  Created on: Apr 12, 2018
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */

#include <avr/interrupt.h>
#include <string.h>

#include "avr_extirq.h"
#include "avr_timer.h"
#include "../display/LCD.h"

enum CRONO_STATUS {RESET, COUNTING, STOP};

struct time_t {
	uint16_t ff;
	uint8_t ss;
	uint8_t mm;
	uint8_t hh;
};

struct crono_t {
	struct time_t time;
	uint8_t status;
};

volatile struct crono_t crono_status;
volatile struct time_t split;

FILE *lcdFile;

static inline void start_timer_1(){
	set_bit(TIMER_1->TCCRB , CS10);
}

static inline void stop_timer_1(){
	clr_bit(TIMER_1->TCCRB , CS10);
}

static inline void reset_crono(){
	memset((void *)&crono_status.time, 0, sizeof(struct time_t));

}

void crono_init(){

	/* Configure INT0 and INT1 for buttons: level change *
	 * INT0: start stop reset
	 * INT1: split */
	GPIO_D->DDR |= ~((1 << PD2) | (1 << PD3));
	GPIO_D->PORT |= (1 << PD2) | (1 << PD3);
	EXT_IRQ->INT0_INT1.EI_CRA = (1 << ISC11) | (1 << ISC01);
	EXT_IRQ_EI_MASK->EIMASK.MASK = (1 << INT0) | (1 << INT1);

	/* Configure timer */
	/* PRES = 1 *
	F_CPU = 16M
	TOP = 16000 *
	T=> 1ms */
	TIMER_1->OCRA = 16000 - 1;
	TIMER_1->TCCRB = (1 << WGM12);
	TIMER_IRQS->TC1.BITS.OCIEA = 1;

	/* Init time values */
	crono_status.time.ff = 0;
	crono_status.time.ss = 0;
	crono_status.time.mm = 0;
	crono_status.time.hh = 0;
	crono_status.status = RESET;

	/* Inicializa display LCD   *
	 * e configuracao dos pinos *
	 * do MCC conforme LCD.h    */
	inic_LCD_4bits();
	lcdFile = inic_stream();

	fprintf(lcdFile, "Cronometro");
	_delay_ms(1000);
	cmd_LCD(0x01,0);
}

void crono_refresh(){

	cmd_LCD(0x82,0);
	fprintf(lcdFile, "%.2d:%.2d:%.2d:%.3d",
			crono_status.time.hh,
			crono_status.time.mm,
			crono_status.time.ss,
			crono_status.time.ff);

	cmd_LCD(0xc2,0);

	fprintf(lcdFile, "%.2d:%.2d:%.2d:%.3d",
			split.hh,
			split.mm,
			split.ss,
			split.ff);
}


ISR(INT0_vect){

	switch (crono_status.status){
		case RESET:
			start_timer_1();
			crono_status.status = COUNTING;
			break;

		case COUNTING:
			stop_timer_1();
			crono_status.status = STOP;
			break;

		case STOP:
			reset_crono();
			crono_status.status = RESET;
			break;

		default:
			break;
	}
}

ISR(INT1_vect){
	split = crono_status.time;
}

ISR(TIMER1_COMPA_vect){

	crono_status.time.ff++;

	if (crono_status.time.ff > 999){
		crono_status.time.ff = 0;
		crono_status.time.ss++;
	}

	if (crono_status.time.ss > 59){
		crono_status.time.ss = 0;
		crono_status.time.mm++;
	}

	if (crono_status.time.mm > 59){
		crono_status.time.mm = 0;
		crono_status.time.hh++;
	}
}

