/*
 * avr_i2c.h
 *
 *  Created on: May 30, 2018
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <util/twi.h>
#include <string.h>

#include "bits.h"
#include "avr_i2c.h"

#define START_BIT() 		TWCR |= (1<<TWSTA)
#define STOP_BIT()			TWCR |= (1<<TWSTO)
#define CLR_START_BIT()		TWCR &= ~(1<<TWSTA)

struct i2c {
	uint8_t w_r_flag;
	uint8_t done;
	uint8_t rd_wr_addr;
	uint8_t wr_data;
	uint8_t rd_data;
	uint8_t step;
	uint8_t errors;
	uint8_t device_addr;
};

volatile struct i2c i2c_status;


void i2c_init(){
	//Ajuste da frequência de trabalho - SCL = F_CPU/(16+2.TWBR.Prescaler)
	TWBR = 18;
	TWSR |= 0x01;							//prescaler =  16;
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWIE);	//habilita o TWI e a interrupção

	SET_BIT(PORTD,1);

	memset((void *)&i2c_status, 0, sizeof(i2c_status));
}


void i2c_write(uint8_t addr, uint8_t data, uint8_t i2c_addr){

	i2c_status.w_r_flag = 1;
	i2c_status.rd_wr_addr = addr;
	i2c_status.wr_data = data;
	i2c_status.device_addr = i2c_addr;

	i2c_status.done = 0;

	START_BIT();

	//TWCR |= (1<<TWSTA);

	i2c_status.step = 1;
	i2c_status.errors = 0x0a;

	while (i2c_status.done == 0);

}

uint8_t i2c_read(uint8_t addr, uint8_t i2c_addr)
{
	//passa variaveis da função para as váriaveis globais alteradas na ISR

	i2c_status.w_r_flag = 0;		//1 para escrita 0 para leitura
	i2c_status.rd_wr_addr = addr;
	i2c_status.device_addr = i2c_addr;

	i2c_status.done = 0;	//trava do sistema até a conclusão da transmissão

	START_BIT();		//envia o Start bit. Passo (1)

	i2c_status.step = 1;
	i2c_status.errors = 0xff;

	while (i2c_status.done == 0); //se for crítica a espera, o programa principal pode gerenciar esta operação

	return i2c_status.rd_data;
}


ISR(TWI_vect)//Rotina de interrupção da TWI
{
	static uint8_t write_done;

	switch (TWSR & 0xF8)	//lê o código de resultado da TWI e executa a próxima ação
	{
		/*LEITURA E ESCRITA
		PASSO 2 <start condition transmitted>. Passo (1) concluído, executa passo (2)*/
		case (TW_START):

			if (i2c_status.w_r_flag)
				TWDR = i2c_status.device_addr | 0x01;			//envia endereço do dispositivo e o bit de escrita
			else
				TWDR = i2c_status.device_addr;

			CLR_START_BIT();		//limpa o start bit
			i2c_status.step = 2;
			break;

		/*LEITURA E ESCRITA
		PASSO 3 <SLA+W transmitted, ACK received>. Passo (2) concluído, executa passo (3)*/
		case (TW_MT_SLA_ACK):
			TWDR = i2c_status.rd_wr_addr;	//envia o endereço de escrita ou leitura
			i2c_status.step = 3;
			write_done = 0;			//inicializa variavel para uso na escrita, PASSO 4
			break;

		/*LEITURA E ESCRITA
		PASSO 4 <data transmitted, ACK received>. Passo (3) concluído, executa passo (4).
				 Passo (4) concluído, executa passo (5) (só na escrita). O passo (4) para uma leitura é o reínicio*/
		case (TW_MT_DATA_ACK):
			if(write_done)			//se o passo (4) foi concluído executa o passo (5), escrita
			{
				STOP_BIT();
				i2c_status.done = 1; //avisa que operação foi concluida
				break;
			}
			if(i2c_status.w_r_flag)	//envia um único dado quando for operação de escrita e depois um stop_bit()
			{
				TWDR = i2c_status.wr_data;	//dado para escrita no endereço de escrita
				write_done = 1;	//avisa que é o último dado a ser escrito
			}
			else
				START_BIT();		//envia reínicio (só para operação de leitura)

			i2c_status.step = 4;
			break;

		/*LEITURA
		PASSO 5 <repeated start condition transmitted>. Passo (4) concluído, executa o passo (5)*/
		case (TW_REP_START):
			TWDR  = i2c_status.device_addr | 0x01;			//Envia endereço e read bit (4)
			CLR_START_BIT();		//limpa start bit
			i2c_status.step = 5;
			break;

		/*LEITURA
		PASSO 6 <SLA+R transmitted, ACK received>. Passo (5) concluído, prepara para a executação do NACK*/
		case (TW_MR_SLA_ACK) :
			TWCR &=~(1<<TWEA);		//enviará um NACK após a recepção do dado
			i2c_status.step = 6;
			break;

		/*LEITURA
		PASSO 7 <data received, NACK returned>. Passo (6) concluído, NACK recebido, executa passo (7)*/
		case (TW_MR_DATA_NACK):
			i2c_status.rd_data = TWDR;		//dado lido
			STOP_BIT();
			i2c_status.done = 1;		//avisa que operação foi concluida
			break;

 		/*TRATAMENTO DOS POSSÍVEIS ERROS
		 Quando um erro acontece a operação errada é repetida até funcionar ou até
		 que o contador para o número máximo de tentavas chegue a zero*/

		default:
				i2c_status.errors--;

				switch(i2c_status.step)
				{
						case(1): START_BIT(); break;
						case(2): TWDR = i2c_status.device_addr; break;
						case(3): TWDR = i2c_status.rd_wr_addr; break;
						case(4):
							if(i2c_status.w_r_flag)
								TWDR = i2c_status.wr_data;
							else
								START_BIT();	//reínicio
							break;
						case(5): TWDR  = i2c_status.device_addr | 0x01; 	break;
						case(6): TWCR &=~(1<<TWEA); break;
				}
				if(i2c_status.errors == 0)//para saber se houve estouro na contagem ou insucesso na correção dos erros, basta ler cont_max_erro.
				{
					STOP_BIT();
					i2c_status.done = 1;			//libera o sistema
				}

	}

	TWCR |= (1<<TWINT); //limpa flag de interrupção
}

