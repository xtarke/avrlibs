/*
 * avr_timer.h
 *
 *  Created on: Mar 27, 2018
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */

#ifndef LIB_AVR_TIMER_H_
#define LIB_AVR_TIMER_H_

#include <stdint.h>
#include <avr/io.h>

#ifndef _IO
#define _IO volatile uint8_t
#endif

#ifndef _IO16
#define _IO16 volatile uint16_t
#endif

typedef struct
{
  _IO TCCRA;	/*!< Config Register A */
  _IO TCCRB;	/*!< Config Register B */
  _IO TCCRC;	/*!< Config Register C */
  _IO unused;
  _IO16 TCNT;	/*!< Counter Register */
  _IO16 ICR;	/*!< Input Capture Register */
  _IO16 OCRA;	/*!< Compare Register: channel A */
  _IO16 OCRB;	/*!< Compare Register: channel B */
} TIMER16_Type;

typedef struct
{
  _IO TCCRA;	/*!< Config Register A */
  _IO TCCRB;	/*!< Config Register B */
  _IO TCNT;		/*!< Counter Register */
  _IO OCRA;		/*!< Compare Register: channel A */
  _IO OCRB;		/*!< Compare Register: channel B */
} TIMER8_Type;

typedef struct {
	union {
		_IO MASK;
		struct {
			_IO TOIE:1;		/*!< Overflow IRQ enable */
			_IO OCIEA:1;	/*!< Compare IRQ: channel A */
			_IO OCIEB:1;	/*!< Compare IRQ: channel B */
		} BITS;
	} TC0;

	union {
		_IO MASK;
		struct {
			_IO TOIE:1;		/*!< Overflow IRQ enable */
			_IO OCIEA:1;	/*!< Compare IRQ: channel A enable */
			_IO OCIEB:1;	/*!< Compare IRQ: channel B enable */
			_IO _unused:2;
			_IO ICIE:1;		/*!< Capture IRQ enable  */
		} BITS;
	} TC1;

	union {
		_IO MASK;
		struct {
			_IO TOIE:1;		/*!< Overflow IRQ enable */
			_IO OCIEA:1;	/*!< Compare IRQ: channel A */
			_IO OCIEB:1;	/*!< Compare IRQ: channel B */
		} BITS;
	} TC2;
}TIMERS_IRQ_Type;

#define TIMER_0 ((TIMER8_Type *) &TCCR0A)
#define TIMER_1 ((TIMER16_Type *) &TCCR1A)
#define TIMER_2 ((TIMER8_Type *) &TCCR2A)
#define TIMER_IRQS ((TIMERS_IRQ_Type *) &TIMSK0)

#endif /* LIB_AVR_TIMER_H_ */
