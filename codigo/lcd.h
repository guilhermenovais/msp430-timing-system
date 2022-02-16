#ifndef LCD_H
#define LCD_H

#include "msp430f1121.h"

//Constantes para dar nome aos pinos e portas do microcontrolador
#define DADOS      P1OUT
#define DADOS_DIR  P1DIR
#define CTRL           P2OUT
#define CTRL_DIR       P2DIR
#define RS             BIT3
#define ENABLE         BIT5
#define DADO_0         BIT0
#define DADO_1         BIT1
#define OE_74HC241     BIT2

//Constantes para configurar o n�mero de linhas do LCD
#define LCD_1_LINHA    0x02
#define LCD_2_LINHA    0x04
#define LCD_3_LINHA    0x08

//Constantes para configurar o funcionamento do LCD
#define INTE_4BITS_2L  0x28
#define INTE_8BITS_2L  0x38
#define ATIVA_DISP     0x0D
#define DESLOC_DIR     0x06 
#define LIMPA_DISP     0x01
#define RESET          0x30

//Constantes para comandos do LCD
#define LIMPA_TELA     0x01
#define C_INATIVO      0x0C
#define C_ALTERNADO    0x0F
#define C_PISCANTE     0x0D
#define C_FIXO         0x0E

#define LINHA1         0x80
#define LINHA2         0xC0

/*---------------------------------------------------------------------------------------------------
Fun��o pulso
Entrada: n�o recebe nenhuma entrada
Sa�da: n�o retorna nenhum valor
Descri��o: envia um pulso no ENABLE do display
---------------------------------------------------------------------------------------------------*/
void pulso(void);

/*---------------------------------------------------------------------------------------------------
Fun��o envia_dado
Entrada: dado (c�digo ASCII do caractere que ser� enviado para o display)
Sa�da: n�o retorna nenhum valor
Descri��o: envia o caractere recebido na entrada para o display
---------------------------------------------------------------------------------------------------*/
void envia_dado(char dado);

/*---------------------------------------------------------------------------------------------------
Fun��o envia_comando
Entrada: comando (instru��o a ser enviada para o display)
Sa�da: n�o retorna nenhum valor
Descri��o: envia o comando recebido na entrada para o display
---------------------------------------------------------------------------------------------------*/
void envia_comando(char comando);

/*---------------------------------------------------------------------------------------------------
Fun��o envia_string
Entrada: str
Sa�da: n�o retorna nenhum valor
Descri��o: envia uma string para o display
---------------------------------------------------------------------------------------------------*/
void envia_string(unsigned char *str);

/*---------------------------------------------------------------------------------------------------
Fun��o move_cursor
Entrada: indice (posi��o com conte�do no display)
Sa�da: n�o retorna nenhum valor
Descri��o: desloca o cursor para a posi��o desejada no sistema de temporiza��o
---------------------------------------------------------------------------------------------------*/
void desloca_cursor(char indice);

/*---------------------------------------------------------------------------------------------------
Fun��o envia_numero
Entrada: num
Sa�da: n�o retorna nenhum valor
Descri��o: envia um n�mero para o display
---------------------------------------------------------------------------------------------------*/
void envia_numero(char num);

/*---------------------------------------------------------------------------------------------------
Fun��o programa_lcd
Entrada: n�o recebe nenhuma entrada
Sa�da: n�o retorna nenhum valor
Descri��o: envia comandos de configura��o para o LCD
---------------------------------------------------------------------------------------------------*/
void programa_lcd(void);


#endif