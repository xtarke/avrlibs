/*
 * main_lcd_i2c.c
 *
 *  Created on: Mar 27, 2018
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */

#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include "display/lcd_i2c.h"
#include "avr_usart.h"
#include "avr_twi_master.h"

/* Detalhes: veja em https://datasheets.maximintegrated.com/en/ds/DS1307.pdf */
#define DS1307_RD_ADDR 0xD1	/* 1101 0001(R/W) -> Read Address */
#define DS1307_WR_ADDR 0xD0	/* 1101 0000(R/W) -> Write Address */

int main(){
	FILE *usart_stream = get_usart_stream();

	/* Debug */
	USART_Init(B9600);

	/* Inicializa modo líder */
	TWI_Master_Initialise();
	sei();

	/* Vetor para dados do I2C */
	uint8_t packge[8] = {0};

	/* Detalhes:
	 * https://datasheets.maximintegrated.com/en/ds/DS1307.pdf */

	for(;;) {
		/* Configura Ponteiro do DS1307 em 0x00 pois ele é *
		 * automaticamente incrementado a cada leitura     */
		packge[0] = DS1307_WR_ADDR;	/* Endereço I2C de escrita */
		packge[1] = 0x00;			/* Endereço inicial da SRAM do RTC: segundos, minutos */
		TWI_Start_Transceiver_With_Data(packge,2);

		/* Obtém Hora, minuto e segundo */
		packge[0] = DS1307_RD_ADDR;
		packge[1] = 0x00;
		/* msgSize deve ser a quantidade de dados que se deseja *
		 * receber mais 1 (byte inicial do endereço pois o clock
		 * deve ser enviado pelo líder do barramento i2c  
         */
		TWI_Start_Transceiver_With_Data(packge,4);

		/* Copia os dados recebidos para um buffer */
		TWI_Get_Data_From_Transceiver(packge,4);

		/* i=1 pois packge[0] contém o endereço I2C */
		for (uint8_t i=1; i < 4; i++)
			fprintf(usart_stream,"%x\n\r", packge[i]);

		_delay_ms(1000);
	}

}
