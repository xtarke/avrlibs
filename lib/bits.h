/*
 * bits.h
 *
 *  Created on: Sep 9, 2016
 *      Author: xtarke
 */

#ifndef BITS_H_
#define BITS_H_

#define	set_bit(y,bit)	(y|=(1<<bit))
#define	clr_bit(y,bit)	(y&=~(1<<bit))
#define cpl_bit(y,bit) 	(y^=(1<<bit))
#define tst_bit(y,bit) 	(y&(1<<bit))

#endif /* BITS_H_ */
