#ifndef _LCD_H
#define _LCD_H

#ifndef F_CPU
	#define F_CPU 16000000UL
#endif

#include <util/delay.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>

#include "bits.h"
#include "avr_gpio.h"


//Definições para facilitar a troca dos pinos do hardware e facilitar a re-programação

#define NIBBLE_DADOS	0		//0 para via de dados do LCD nos 4 LSBs do PORT empregado (Px0-D4, Px1-D5, Px2-D6, Px3-D7)
								//1 para via de dados do LCD nos 4 MSBs do PORT empregado (Px4-D4, Px5-D5, Px6-D6, Px7-D7) 
#define DADOS_LCD	GPIO_B

#define CONTR_LCD		GPIO_B
#define E    			PB4     //pino de habilitação do LCD (enable)
#define RS   			PB5     //pino para informar se o dado é uma instrução ou caractere

/* Inicialização de hardware e stream */
void inic_LCD_4bits();
FILE * inic_stream();

/* Comandos e escrita estática */
void cmd_LCD(uint8_t c, uint8_t cd);
void escreve_LCD(char *c);
void escreve_LCD_Flash(const char *c);

int lcd_putchar(char c, FILE *fp);


#endif
