/*
 * avr_spi.c
 *
 *  Created on: May 22, 2018
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "bits.h"
#include "avr_gpio.h"
#include "avr_spi.h"

#define SS PB2
#define MOSI PB3
#define MISO PB4
#define SCK PB5

/*\ Inicialização do SPÌ */
void SPI_MasterInit(void)
{
	/* Configura direção das portas */
	GPIO_B->DDR = (1 << SS) | (1 << MOSI) | (1 << SCK);

	/* Ativa SPI em modo mestre
	 * clock = F_CPU / 16  */
	SPI->SP_CR.MASK = SET(SPE) | SET(MSTR) | SET(SPR0)  | SET(DORD);
	/* Diretamente:
	SPCR = (1 << SPE)|(1 << MSTR)|(1 << SPR0); */
}

uint8_t SPI_Transmit(uint8_t byte){

	/* Configura dado no registrado de hardware */
	//SPI->SP_DR = byte;
	/* Diretamente: */
	SPDR = byte;

	/* Aguarada transmissão */
	while (!SPI->SP_SR.SP_IF);
	/* Diretamente: */
	//while(!(SPSR & (1<<SPIF)));

	/* retorna se algum dado for lido */
	return SPI->SP_DR;
}

uint8_t SPI_SlaveReceive(uint8_t byte)
{
	// Uma recepção de SPI deve ativar o clock
	// logo, enviamos outro dado ou qualquer coisa
	return SPI_Transmit(byte);
}

