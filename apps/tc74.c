/*
 * tc74.c
 *
 *  Created on: Mar 27, 2018
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 *
 *      I2C Tiny Serial Digital Thermal Sensor
 *
 */

#include <avr/interrupt.h>

#include "tc74.h"
#include <avr_timer.h>
#include <avr_i2c.h>


volatile int8_t measure_window[8] = {0};
volatile int8_t current_temp = 0;
volatile uint8_t acq_flag = 0;
volatile int16_t sum = 0;

/* Sensor and temperature measure initialization */
void tc74_init(){

	/* Timer 1 overflow initialization
	 * IRQ @ 262 ms: temperature acquisition trigger
	 *
	 * Prescaller: 64	Overflow enable  (TIMER1_OVF_vect)	 */
	TIMER_1->TCCRB = (1<<CS11) | (1<<CS10);
	TIMER_IRQS->TC1.BITS.TOIE = 1;
}


uint8_t perform_temp_measure(){

	static int8_t temp = 0;

	if (acq_flag){
		current_temp =  i2c_read(0x00, TC74_I2C_ADDR);

		temp = sum >> 3;

		acq_flag = 0;
	}

	return temp;
}


ISR(TIMER1_OVF_vect)
{
	static uint8_t i = 0;

	sum -= measure_window[i];
	measure_window[i] = current_temp;
	sum += current_temp;

	i++;
	i = i & 0x7;

	acq_flag = 1;
}


















