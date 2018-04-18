/*
 * avr_extirq.h
 *
 *  Created on: Mar 28, 2018
 *      Author: xtarke
 */

#ifndef LIB_AVR_EXTIRQ_H_
#define LIB_AVR_EXTIRQ_H_

#ifndef _IO
#define _IO volatile uint8_t
#define _IO16 volatile uint16_t
#endif

#include <avr/io.h>

/* Two types of External IRQs:        *
 * INT0 and INT1 pins: EICRA Register *
 * PCINTx pins: PCICR Register        */
typedef struct {
  union {
  		_IO PCI_CR;
  		struct {
  			_IO PCIE_0:1;	/*!< Pin Change Group 1 (PORTB) Activated:PCIE0 */
  			_IO PCIE_1:1;	/*!< Pin Change Group 2 (PORTC) Activated PCIE1 */
  			_IO PCIE_2:1;	/*!< Pin Change Group 3 (PORTC) Activated PCIE2 */
  		} BITS;
  	} PC_INT;

	union {
		_IO EI_CRA;
		struct {
			/*!< ISCx1 ISCx0   Description  */
			/*!<  0      0		The low level of INTx generates an interrupt request. */
			/*!<  0	     1		Any logical change on INTx generates an interrupt request. */
			/*!<  1      0		The falling edge of INTx generates an interrupt request. */
			/*!<  1	     1      The rising edge of INTx generates an interrupt request.	 */
			_IO ISC_00:1;
			_IO ISC_01:1;
			_IO ISC_10:1;
			_IO ISC_11:1;
		} BITS;
	} INT0_INT1;

} EXTCONFIG_Type;

typedef struct {
	union {
		_IO MASK;
		struct {
			_IO PCINT_0:1;	/*!< Pin Change IRQ (PB0) enable  */
			_IO PCINT_1:1;	/*!< Pin Change IRQ (PB1) enable  */
			_IO PCINT_2:1;	/*!< Pin Change IRQ (PB2) enable  */
			_IO PCINT_3:1;	/*!< Pin Change IRQ (PB3) enable  */
			_IO PCINT_4:1;	/*!< Pin Change IRQ (PB4) enable  */
			_IO PCINT_5:1;	/*!< Pin Change IRQ (PB5) enable  */
			_IO PCINT_6:1;	/*!< Pin Change IRQ (PB6) enable  */
			_IO PCINT_7:1;	/*!< Pin Change IRQ (PB7) enable  */
		} BITS;
	} PCMASK0;

	union {
		_IO MASK;
		struct {
			_IO PCINT_8:1;	/*!< Pin Change IRQ (PC0) enable  */
			_IO PCINT_9:1;	/*!< Pin Change IRQ (PC1) enable  */
			_IO PCINT_10:1;	/*!< Pin Change IRQ (PC2) enable  */
			_IO PCINT_11:1;	/*!< Pin Change IRQ (PC3) enable  */
			_IO PCINT_12:1;	/*!< Pin Change IRQ (PC4) enable  */
			_IO PCINT_13:1;	/*!< Pin Change IRQ (PC5) enable  */
			_IO PCINT_14:1;	/*!< Pin Change IRQ (PC6) enable  */

		} BITS;
	} PCMASK1;

	union {
		_IO MASK;
		struct {
			_IO PCINT_16:1;	/*!< Pin Change IRQ (PD0) enable  */
			_IO PCINT_17:1;	/*!< Pin Change IRQ (PD1) enable  */
			_IO PCINT_18:1;	/*!< Pin Change IRQ (PD2) enable  */
			_IO PCINT_19:1;	/*!< Pin Change IRQ (PD3) enable  */
			_IO PCINT_20:1;	/*!< Pin Change IRQ (PD4) enable  */
			_IO PCINT_21:1;	/*!< Pin Change IRQ (PD5) enable  */
			_IO PCINT_22:1;	/*!< Pin Change IRQ (PD6) enable  */
			_IO PCINT_23:1;	/*!< Pin Change IRQ (PD6) enable  */
		} BITS;
	} PCMASK2;
}EXT_PC_IRQ_Type;

typedef struct {
	union {
		_IO MASK;
		struct {
			_IO INT_0:1;	/*!< External IRQ (INT0) PD2 enable  */
			_IO INT_1:1;	/*!< External IRQ (INT1) PD3 enable  */
		} BITS;
	} EIMASK;
}EXT_EI_IRQ_Type;

#define EXT_IRQ ((EXTCONFIG_Type *) &PCICR)
#define EXT_IRQ_PCINT_MASK ((EXT_PC_IRQ_Type *) &PCMSK0)
#define EXT_IRQ_EI_MASK ((EXT_EI_IRQ_Type *) &EIMSK)


#endif /* LIB_AVR_EXTIRQ_H_ */
