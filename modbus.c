/*
 * modbus.c
 *
 *  Created on: Nov 1, 2018
 *      Author: xtarke
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#include "lib/avr_usart.h"
#include "display/lcd.h"


uint16_t CRC16_2(uint8_t *buf, int len)
{
  uint32_t crc = 0xFFFF;
  int i;

  for (i = 0; i < len; i++)
  {
    crc ^= (uint16_t)buf[i];          // XOR byte into least sig. byte of crc

    for (int i = 8; i != 0; i--) {    // Loop over each bit
      if ((crc & 0x0001) != 0) {      // If the LSB is set
        crc >>= 1;                    // Shift right and XOR 0xA001
        crc ^= 0xA001;
      }
      else                            // Else LSB is not set
        crc >>= 1;                    // Just shift right
    }
  }
  // Note, this number has low and high bytes swapped, so use it accordingly (or swap bytes)
  return crc;
}





int main(){
	uint8_t pkg[8] = {0x15, 0x01, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00};
	uint8_t rx_pkg[16],i;
	uint16_t data = 0;
	uint16_t crc;

	FILE *lcd_stream;

	/* Inicializa hardware da USART */
	USART_Init(B9600);

	lcd_stream = inic_stream();

	inic_LCD_4bits();


	while (1){
		pkg[1] = 0x01;
		pkg[2] = 0x00;
		pkg[3] = 0x05;
		pkg[4] = data >> 8;
		pkg[5] = data & 0xff;

		crc = CRC16_2(pkg,6);

		pkg[6] = crc >> 8;
		pkg[7] = crc & 0xff;

		for (i=0; i < 8; i++)
			USART_tx(pkg[i]);

		for (i=0; i < 8;i++)
			rx_pkg[i] = USART_rx();

		data++;
		_delay_ms(1000);

		pkg[1] = 0x02;
		pkg[2] = 0x00;
		pkg[3] = 0x01;
		pkg[4] = 0x00;
		pkg[5] = 0x04;

		crc = CRC16_2(pkg,6);

		pkg[6] = crc >> 8;
		pkg[7] = crc & 0xff;

		for (i=0; i < 8; i++)
			USART_tx(pkg[i]);

		for (i=0; i < 14;i++)
			rx_pkg[i] = USART_rx();

		_delay_ms(1000);


		fprintf(lcd_stream,"%d   %d   %d", rx_pkg[5], rx_pkg[7], rx_pkg[9]);
		cmd_LCD(0xc0,0);
		fprintf(lcd_stream,"%d", rx_pkg[11]);

		cmd_LCD(0x80,0);


	}


	return 0;
}
