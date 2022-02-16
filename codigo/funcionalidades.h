#ifndef FUNCIONALIDADES_H
#define FUNCIONALIDADES_H

#include "lcd.h"

/*---------------------------------------------------------------------------------------------------
Função inc_seg_disp
Entrada: não recebe nenhuma entrada
Saída: não retorna nenhum valor
Descrição: incrementa os segundos no display
---------------------------------------------------------------------------------------------------*/
void inc_seg_disp(void);

/*---------------------------------------------------------------------------------------------------
Função inc_min_disp
Entrada: não recebe nenhuma entrada
Saída: não retorna nenhum valor
Descrição: incrementa os minutos no display
---------------------------------------------------------------------------------------------------*/
void inc_min_disp(void);

/*---------------------------------------------------------------------------------------------------
Função inc_seg_disp
Entrada: não recebe nenhuma entrada
Saída: não retorna nenhum valor
Descrição: incrementa as horas no display
---------------------------------------------------------------------------------------------------*/
void inc_hora_disp(void);

/*---------------------------------------------------------------------------------------------------
Função inc_seg_rlg
Entrada: não recebe nenhuma entrada
Saída: não retorna nenhum valor
Descrição: incrementa os segundos no relógio
---------------------------------------------------------------------------------------------------*/
void inc_seg_rlg(void);

/*---------------------------------------------------------------------------------------------------
Função inc_min_rlg
Entrada: não recebe nenhuma entrada
Saída: não retorna nenhum valor
Descrição: incrementa os minutos no relógio
---------------------------------------------------------------------------------------------------*/
void inc_min_rlg(void);

/*---------------------------------------------------------------------------------------------------
Função inc_hora_rlg
Entrada: não recebe nenhuma entrada
Saída: não retorna nenhum valor
Descrição: incrementa as horas no relógio
---------------------------------------------------------------------------------------------------*/
void inc_hora_rlg(void);

/*---------------------------------------------------------------------------------------------------
Função dec_seg_disp
Entrada: não recebe nenhuma entrada
Saída: não retorna nenhum valor
Descrição: decrementa os segundos no display
---------------------------------------------------------------------------------------------------*/
char dec_seg_disp(void);

/*---------------------------------------------------------------------------------------------------
Função dec_min_disp
Entrada: não recebe nenhuma entrada
Saída: não retorna nenhum valor
Descrição: decrementa os minutos no display
---------------------------------------------------------------------------------------------------*/
void dec_min_disp(void);

/*---------------------------------------------------------------------------------------------------
Função dec_hora_disp
Entrada: não recebe nenhuma entrada
Saída: não retorna nenhum valor
Descrição: decrementa as horas no display
---------------------------------------------------------------------------------------------------*/
void dec_hora_disp(void);

/*---------------------------------------------------------------------------------------------------
Função dec_min_rlg
Entrada: não recebe nenhuma entrada
Saída: não retorna nenhum valor
Descrição: decrementa os minutos no relógio
---------------------------------------------------------------------------------------------------*/
void dec_min_rlg(void);

/*---------------------------------------------------------------------------------------------------
Função dec_hora_rlg
Entrada: não recebe nenhuma entrada
Saída: não retorna nenhum valor
Descrição: decrementa horas no hora
---------------------------------------------------------------------------------------------------*/
void dec_hora_rlg(void);

/*---------------------------------------------------------------------------------------------------
Função zera_disp
Entrada: não recebe nenhuma entrada
Saída: não retorna nenhum valor
Descrição: envia 00:00:00 para o display
---------------------------------------------------------------------------------------------------*/
void zera_disp(void);

/*---------------------------------------------------------------------------------------------------
Função inicia_temp
Entrada: não recebe nenhuma entrada
Saída: não retorna nenhum valor
Descrição: envia o valor registrado nas variáveis do temporizador para o display
---------------------------------------------------------------------------------------------------*/
void inicia_temp(void);

/*---------------------------------------------------------------------------------------------------
Função registra_temp
Entrada: não recebe nenhuma entrada
Saída: não retorna nenhum valor
Descrição: registra o valor atual do display nas variáveis do temporizador
---------------------------------------------------------------------------------------------------*/
void registra_temp(void);

/*---------------------------------------------------------------------------------------------------
Função reseta_temp
Entrada: não recebe nenhuma entrada
Saída: não retorna nenhum valor
Descrição: volta o display para o valor registrado nas variáveis do temporizador
---------------------------------------------------------------------------------------------------*/
void reseta_temp(void);

/*---------------------------------------------------------------------------------------------------
Função inicia_rlg
Entrada: não recebe nenhuma entrada
Saída: não retorna nenhum valor
Descrição: volta o display para o valor registrado nas variáveis do relógio
---------------------------------------------------------------------------------------------------*/
void inicia_rlg(void);

/*---------------------------------------------------------------------------------------------------
Função trata_tecla
Entrada: não recebe nenhuma entrada
Saída: não retorna nenhum valor
Descrição: executa os comandos com base na tecla que foi pressionada
---------------------------------------------------------------------------------------------------*/
void trata_tecla(char tecla);

/*---------------------------------------------------------------------------------------------------
Função trata_interrupcao
Entrada: não recebe nenhuma entrada
Saída: não retorna nenhum valor
Descrição: trata a passagem de segundo com base no modo atual e nas variáveis de controle
---------------------------------------------------------------------------------------------------*/
void trata_interrupcao(void);

#endif