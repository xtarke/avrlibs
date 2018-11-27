/*
 * lcd_i2c.c
 *
 *  Created on: Mar 27, 2018
 *      Author: Renan Augusto Starke
 *
 *      Adaptado de AVR e Arduino: Técnicas de Projeto, 2a ed. - 2012.
 *      Instituto Federal de Santa Catarina
 */

#include "lcd_i2c.h"
#include "avr_twi_master.h"

/* Vetor local para frame I2C */
uint8_t twiBuffer[2];

#define PULSO_ENABLE() SET_BIT(twiBuffer[1], E_I2C);  TWI_Start_Transceiver_With_Data( twiBuffer, 2 ); CLR_BIT(twiBuffer[1], E_I2C); TWI_Start_Transceiver_With_Data( twiBuffer, 2 );

/* Stream para utilizacao do fprintf */
FILE lcd_str_i2c = FDEV_SETUP_STREAM(lcd_putchar_i2c, NULL, _FDEV_SETUP_WRITE);
volatile uint8_t data_i2c = 0;

/* Retorna stream local para utilizacao de fprintf */
FILE *inic_stream_i2c(){
	return &lcd_str_i2c;
}

/**
  * @brief  Envia um dado estático para o display: caractere ou comando.
  * @param c: valor do comando.
  * @param cd: 0 para comando. 1 para caractere.
  *
  * @retval Nenhum
  */
void cmd_LCD_i2c(uint8_t c, uint8_t cd)				//c é o dado  e cd indica se é instrução ou caractere
{
	if(cd==0)
		CLR_BIT(twiBuffer[1], RS_I2C);
	else
		SET_BIT(twiBuffer[1], RS_I2C);

	//primeiro nibble de dados - 4 MSB
	#if (NIBBLE_DADOS_I2C)								//compila código para os pinos de dados do LCD nos 4 MSB do PORT
		twiBuffer[1] = (twiBuffer[1] & 0x0F)|(0xF0 & c);
	#else											//compila código para os pinos de dados do LCD nos 4 LSB do PORT
		data_i2c = (data_i2c & 0xF0)|(c>>4);
	#endif
	
	PULSO_ENABLE();

	//segundo nibble de dados - 4 LSB
	#if (NIBBLE_DADOS_I2C)								//compila código para os pinos de dados do LCD nos 4 MSB do PORT
		twiBuffer[1] = (twiBuffer[1] & 0x0F) | (0xF0 & (c<<4));
	#else											//compila código para os pinos de dados do LCD nos 4 LSB do PORT
		data_i2c = (data_i2c & 0xF0) | (0x0F & c);
	#endif
	
	PULSO_ENABLE();
	
	if((cd==0) && (c<4))				//se for instrução de retorno ou limpeza espera LCD estar pronto
		_delay_ms(2);
}

/**
  * @brief  Configura hardware: verificar lcd.h para mapa de pinos e nible de dados.
  * @param	Nenhum
  *
  * @retval Nenhum.
  */
void inic_LCD_4bits_i2c()		//sequência ditada pelo fabricando do circuito integrado HD44780
{
	twiBuffer[0] = PCF_ADDR;
	twiBuffer[1] = 0;

	/* Configura pinos de controle */
	SET_BIT(twiBuffer[1], RS_I2C);
	SET_BIT(twiBuffer[1], E_I2C);

	/* Configure pinos de dados */
	#if (NIBBLE_DADOS_I2C)
		data_i2c |=  0xF0;
	#else
		data_i2c |=  0x0F;
	#endif

	TWI_Start_Transceiver_With_Data( twiBuffer, 2 );

	//i2c_write(data_i2c, data_i2c, PCF_ADDR);

	CLR_BIT(twiBuffer[1], RS_I2C);	//RS em zero indicando que o dado para o LCD será uma instrução
	CLR_BIT(twiBuffer[1], E_I2C);	//pino de habilitação em zero

	TWI_Start_Transceiver_With_Data( twiBuffer, 2 );

	_delay_ms(20);	 		//tempo para estabilizar a tensão do LCD, após VCC ultrapassar 4.5 V (na prática pode
						//ser maior).
	//interface de 8 bits						
	#if (NIBBLE_DADOS_I2C)
		twiBuffer[1] = (twiBuffer[1] & 0x0F) | 0x30;
	#else		
		data_i2c = (data_i2c & 0xF0) | 0x03;
	#endif						
							
	PULSO_ENABLE();			//habilitação respeitando os tempos de resposta do LCD
	_delay_ms(5);		
	PULSO_ENABLE();
	_delay_us(200);
	PULSO_ENABLE();	/*até aqui ainda é uma interface de 8 bits.
					Muitos programadores desprezam os comandos acima, respeitando apenas o tempo de
					estabilização da tensão (geralmente funciona). Se o LCD não for inicializado primeiro no 
					modo de 8 bits, haverá problemas se o microcontrolador for inicializado e o display já o tiver sido.*/
	
	//interface de 4 bits, deve ser enviado duas vezes (a outra está abaixo)
	#if (NIBBLE_DADOS_I2C)
		twiBuffer[1] = (twiBuffer[1] & 0x0F) | 0x20;
	#else		
		data_i2c = (data_i2c & 0xF0) | 0x02;
	#endif

	PULSO_ENABLE();
   	cmd_LCD_i2c(0x28,0); 		//interface de 4 bits 2 linhas (aqui se habilita as 2 linhas)
							//são enviados os 2 nibbles (0x2 e 0x8)
   	cmd_LCD_i2c(0x08,0);		//desliga o display
   	cmd_LCD_i2c(0x01,0);		//limpa todo o display
   	cmd_LCD_i2c(0x0C,0);		//mensagem aparente cursor inativo não piscando
   	cmd_LCD_i2c(0x80,0);		//inicializa cursor na primeira posição a esquerda - 1a linha
}

/**
  * @brief  Escreve um string estática (sem printf) no LCD.
  * @param c: ponteiro para a string em RAM
  *
  * @retval Nenhum
  */
void escreve_LCD_i2c(char *c)
{
   for (; *c!=0;c++) cmd_LCD_i2c(*c,1);
}

/**
  * @brief  Escreve um string estática (sem printf) no LCD.
  * @param c: ponteiro para a string em FLASH
  *
  * @retval Nenhum
  */
void escreve_LCD_Flash_i2c(const char *c)
{
   for (;pgm_read_byte(&(*c))!=0;c++) cmd_LCD_i2c(pgm_read_byte(&(*c)),1);
}

/**
  * @brief Escreve um caractere no stream. Função utilizada pela libc.
  * @param c: caractere a ser escrito.
  * @param fp: ponteiro do stream inicilizado que receberá o dado.
  *
  * @retval int maior que zero se sucesso.
  */
int lcd_putchar_i2c(char c, FILE *fp){
	cmd_LCD_i2c(c,1);

	return 0;
}
