/*
 * avr_gpio.h
 *
 *  Created on: April 24, 2018
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */

#ifndef LIB_AVR_ADC_H_
#define LIB_AVR_ADC_H_

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
	_IO ADCLow;
	_IO ADCHigh;

	_IO ADC_SRA;	/*!< ADC Control and Status Register A */
	_IO ADC_SRB;	/*!< ADC Control and Status Register B */
	_IO AD_MUX;		/*!< Mux Register */

	_IO reserved;

	union {
		_IO MASK;
		struct {
			_IO ADC0:1;
			_IO ADC1:1;
			_IO ADC2:1;
			_IO ADC3:1;
			_IO ADC4:1;
			_IO ADC5:1;
		} BITS;
	} DIDr0;	/* Digital Input Disable Register 0 */
				/* When this bit is written logic one,
				 * the digital input buffer on the
				 * corresponding ADC pin is disabled. */

	union {
		_IO MASK;
		struct {
			_IO ADC0:1;
			_IO ADC1:1;
			_IO ADC2:1;
			_IO ADC3:1;
			_IO ADC4:1;
			_IO ADC5:1;
		} BITS;
	} DIDr1;	/* Digital Input Disable Register 1 */
				/* When this bit is written logic one,
				 * the digital input buffer on the
				 * corresponding ADC pin is disabled. */

} ADC_Type;

typedef	union {
		_IO MASK;
		struct {
			_IO ACIS_0:1;	/*!< Analog Comparator Interrupt Mode Select  0 */
			_IO ACIS_1:1;	/*!< Analog Comparator Interrupt Mode Select 1 */
			_IO AC_IC:1;	/*!< Analog Comparator Input Capture Enable */
			_IO AC_IE:1;  	/*!< Analog Comparator Interrupt Enable */
			_IO AC_I:1;     /*!< Analog Comparator Interrupt Flag */
			_IO AC_O:1;     /*!< Analog Comparator Output */
			_IO AC_BG:1; 	/*!< Analog Comparator Bandgap Select */
			_IO AC_D:1;		/*!< Analog Comparator Disable */
		} BITS;
	} ACSr_IRQ_Type;					/*!< Analog Comparator Control and Status Register */

#define ADCS ((ADC_Type *) &ADCL)
#define ANCOMP_IRQS  ((ACSr_IRQ_Type *) &ACSR)


#endif /* LIB_AVR_ADC_H_ */
