/*
 * sht21.c
 *
 *
 *  sht21 example!
 *
 *  Created on: Mar 27, 2018
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */

#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include "lib/avr_usart.h"
#include "lib/avr_twi_master.h"

int main(){
	uint8_t i = 0;

	uint8_t i2c_pkg[8];
	uint8_t i2c_pkg_[8];

	FILE *usart_stream = get_usart_stream();


	stdout = usart_stream;

	/* Debug */
	USART_Init(B9600);

	/* Inicializa modo líder */
	TWI_Master_Initialise();
	sei();

	i2c_pkg[0] = 0x80;
	i2c_pkg[1] = 0xf3; //   1110’0011
	i2c_pkg[2] = 0x81;

	for(;;) {
		i2c_pkg[0] = 0x80;
		TWI_Start_Transceiver_With_Data(i2c_pkg,2);
		_delay_ms(100);

		//while(TWI_Transceiver_Busy());

		i2c_pkg[0] = 0x81;
		TWI_Start_Transceiver_With_Data(i2c_pkg,4);

		TWI_Get_Data_From_Transceiver(i2c_pkg_,8);

//		for(i=0; i < 8; i++)
//			//fprintf(usart_stream, "%x-\n\r", i2c_pkg_[i]);
//			printf("%x-\n\r", i2c_pkg_[i]);


		uint16_t data = i2c_pkg_[1] << 8 |  i2c_pkg_[2];


		int32_t long_data = (int32_t)data * 17575;
		long_data = long_data >> 16;
		long_data = long_data - 4685;


		//fprintf(usart_stream, "[%d  -  %ld ] \n\r", data, long_data);
		printf("[%d  -  %ld ] \n\r", data, long_data);



		_delay_ms(1000);
	}
