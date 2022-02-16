#ifndef TECLADO_H
#define TECLADO_H

#include "msp430f1121.h"

/*---------------------------------------------------------------------------------------------------
Fun��o ler_colunas
Entrada: n�o recebe nenhuma entrada
Sa�da: colunas (1: coluna 1, 2: coluna 2, 4: coluna 3, 8: coluna 4, 0: nenhuma coluna)
Descri��o: retorna um n�mero indicando qual coluna do display est� ativa no momento. Foi utilizado
o CI 74HC241 para permitir que fossem usados apenas 2 pinos para fazer a leitura. Ao zerar o bit OE, 
os valores das colunas 1 e 2 s�o projetados nos pinos P2.0 e P2.1. Ao setar o bit OE, os valores das 
colunas 3 e 4 s�o projetados nos pinos P2.0 e P2.1. Como as colunas do teclado matricial est�o liga-
das em resistores de pull-up e v�o a n�vel baixo quando pressionados, uma coluna pressionada tem n�-
vel l�gico 0 enquanto uma coluna n�o-pressionada tem n�vel l�gico 1.
---------------------------------------------------------------------------------------------------*/
char ler_colunas(void);

/*---------------------------------------------------------------------------------------------------
Nome da fun��o: teclado
Entrada: nenhuma
Sa�da: tecla (c�digo ASCII do caractere da tecla que foi pressionada no teclado matricial)
Descri��o: Verifica se alguma tecla foi pressionada e retorna essa tecla ou, caso nenhuma tecla tenha
sido pressionada, retorna 0x00 (NULL)
---------------------------------------------------------------------------------------------------*/
char teclado(void);

#endif