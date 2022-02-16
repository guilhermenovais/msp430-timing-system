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

//Constantes para configurar o número de linhas do LCD
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
Função pulso
Entrada: não recebe nenhuma entrada
Saída: não retorna nenhum valor
Descrição: envia um pulso no ENABLE do display
---------------------------------------------------------------------------------------------------*/
void pulso(void);

/*---------------------------------------------------------------------------------------------------
Função envia_dado
Entrada: dado (código ASCII do caractere que será enviado para o display)
Saída: não retorna nenhum valor
Descrição: envia o caractere recebido na entrada para o display
---------------------------------------------------------------------------------------------------*/
void envia_dado(char dado);

/*---------------------------------------------------------------------------------------------------
Função envia_comando
Entrada: comando (instrução a ser enviada para o display)
Saída: não retorna nenhum valor
Descrição: envia o comando recebido na entrada para o display
---------------------------------------------------------------------------------------------------*/
void envia_comando(char comando);

/*---------------------------------------------------------------------------------------------------
Função envia_string
Entrada: str
Saída: não retorna nenhum valor
Descrição: envia uma string para o display
---------------------------------------------------------------------------------------------------*/
void envia_string(unsigned char *str);

/*---------------------------------------------------------------------------------------------------
Função move_cursor
Entrada: indice (posição com conteúdo no display)
Saída: não retorna nenhum valor
Descrição: desloca o cursor para a posição desejada no sistema de temporização
---------------------------------------------------------------------------------------------------*/
void desloca_cursor(char indice);

/*---------------------------------------------------------------------------------------------------
Função envia_numero
Entrada: num
Saída: não retorna nenhum valor
Descrição: envia um número para o display
---------------------------------------------------------------------------------------------------*/
void envia_numero(char num);

/*---------------------------------------------------------------------------------------------------
Função programa_lcd
Entrada: não recebe nenhuma entrada
Saída: não retorna nenhum valor
Descrição: envia comandos de configuração para o LCD
---------------------------------------------------------------------------------------------------*/
void programa_lcd(void);


#endif