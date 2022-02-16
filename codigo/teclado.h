#ifndef TECLADO_H
#define TECLADO_H

#include "msp430f1121.h"

/*---------------------------------------------------------------------------------------------------
Função ler_colunas
Entrada: não recebe nenhuma entrada
Saída: colunas (1: coluna 1, 2: coluna 2, 4: coluna 3, 8: coluna 4, 0: nenhuma coluna)
Descrição: retorna um número indicando qual coluna do display está ativa no momento. Foi utilizado
o CI 74HC241 para permitir que fossem usados apenas 2 pinos para fazer a leitura. Ao zerar o bit OE, 
os valores das colunas 1 e 2 são projetados nos pinos P2.0 e P2.1. Ao setar o bit OE, os valores das 
colunas 3 e 4 são projetados nos pinos P2.0 e P2.1. Como as colunas do teclado matricial estão liga-
das em resistores de pull-up e vão a nível baixo quando pressionados, uma coluna pressionada tem ní-
vel lógico 0 enquanto uma coluna não-pressionada tem nível lógico 1.
---------------------------------------------------------------------------------------------------*/
char ler_colunas(void);

/*---------------------------------------------------------------------------------------------------
Nome da função: teclado
Entrada: nenhuma
Saída: tecla (código ASCII do caractere da tecla que foi pressionada no teclado matricial)
Descrição: Verifica se alguma tecla foi pressionada e retorna essa tecla ou, caso nenhuma tecla tenha
sido pressionada, retorna 0x00 (NULL)
---------------------------------------------------------------------------------------------------*/
char teclado(void);

#endif