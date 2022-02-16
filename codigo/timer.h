#ifndef TIMER_H
#define TIMER_H

#include "lcd.h"

/*---------------------------------------------------------------------------------------------------
Função configura_msp
Entradas: não recebe nenhuma entrada
Saída: não retorna nenhum valor
Descrição: configura a Entrada/Saída microcontrolador
---------------------------------------------------------------------------------------------------*/
void configura_msp(void);

/*---------------------------------------------------------------------------------------------------
Função configura_timer
Entradas: não recebe nenhuma entrada
Saída: não retorna nenhum valor
Descrição: configura o Timer A do microcontrolador
---------------------------------------------------------------------------------------------------*/
void configura_timer(void);

#endif