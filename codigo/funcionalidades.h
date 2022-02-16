#ifndef FUNCIONALIDADES_H
#define FUNCIONALIDADES_H

#include "lcd.h"

/*---------------------------------------------------------------------------------------------------
Fun��o inc_seg_disp
Entrada: n�o recebe nenhuma entrada
Sa�da: n�o retorna nenhum valor
Descri��o: incrementa os segundos no display
---------------------------------------------------------------------------------------------------*/
void inc_seg_disp(void);

/*---------------------------------------------------------------------------------------------------
Fun��o inc_min_disp
Entrada: n�o recebe nenhuma entrada
Sa�da: n�o retorna nenhum valor
Descri��o: incrementa os minutos no display
---------------------------------------------------------------------------------------------------*/
void inc_min_disp(void);

/*---------------------------------------------------------------------------------------------------
Fun��o inc_seg_disp
Entrada: n�o recebe nenhuma entrada
Sa�da: n�o retorna nenhum valor
Descri��o: incrementa as horas no display
---------------------------------------------------------------------------------------------------*/
void inc_hora_disp(void);

/*---------------------------------------------------------------------------------------------------
Fun��o inc_seg_rlg
Entrada: n�o recebe nenhuma entrada
Sa�da: n�o retorna nenhum valor
Descri��o: incrementa os segundos no rel�gio
---------------------------------------------------------------------------------------------------*/
void inc_seg_rlg(void);

/*---------------------------------------------------------------------------------------------------
Fun��o inc_min_rlg
Entrada: n�o recebe nenhuma entrada
Sa�da: n�o retorna nenhum valor
Descri��o: incrementa os minutos no rel�gio
---------------------------------------------------------------------------------------------------*/
void inc_min_rlg(void);

/*---------------------------------------------------------------------------------------------------
Fun��o inc_hora_rlg
Entrada: n�o recebe nenhuma entrada
Sa�da: n�o retorna nenhum valor
Descri��o: incrementa as horas no rel�gio
---------------------------------------------------------------------------------------------------*/
void inc_hora_rlg(void);

/*---------------------------------------------------------------------------------------------------
Fun��o dec_seg_disp
Entrada: n�o recebe nenhuma entrada
Sa�da: n�o retorna nenhum valor
Descri��o: decrementa os segundos no display
---------------------------------------------------------------------------------------------------*/
char dec_seg_disp(void);

/*---------------------------------------------------------------------------------------------------
Fun��o dec_min_disp
Entrada: n�o recebe nenhuma entrada
Sa�da: n�o retorna nenhum valor
Descri��o: decrementa os minutos no display
---------------------------------------------------------------------------------------------------*/
void dec_min_disp(void);

/*---------------------------------------------------------------------------------------------------
Fun��o dec_hora_disp
Entrada: n�o recebe nenhuma entrada
Sa�da: n�o retorna nenhum valor
Descri��o: decrementa as horas no display
---------------------------------------------------------------------------------------------------*/
void dec_hora_disp(void);

/*---------------------------------------------------------------------------------------------------
Fun��o dec_min_rlg
Entrada: n�o recebe nenhuma entrada
Sa�da: n�o retorna nenhum valor
Descri��o: decrementa os minutos no rel�gio
---------------------------------------------------------------------------------------------------*/
void dec_min_rlg(void);

/*---------------------------------------------------------------------------------------------------
Fun��o dec_hora_rlg
Entrada: n�o recebe nenhuma entrada
Sa�da: n�o retorna nenhum valor
Descri��o: decrementa horas no hora
---------------------------------------------------------------------------------------------------*/
void dec_hora_rlg(void);

/*---------------------------------------------------------------------------------------------------
Fun��o zera_disp
Entrada: n�o recebe nenhuma entrada
Sa�da: n�o retorna nenhum valor
Descri��o: envia 00:00:00 para o display
---------------------------------------------------------------------------------------------------*/
void zera_disp(void);

/*---------------------------------------------------------------------------------------------------
Fun��o inicia_temp
Entrada: n�o recebe nenhuma entrada
Sa�da: n�o retorna nenhum valor
Descri��o: envia o valor registrado nas vari�veis do temporizador para o display
---------------------------------------------------------------------------------------------------*/
void inicia_temp(void);

/*---------------------------------------------------------------------------------------------------
Fun��o registra_temp
Entrada: n�o recebe nenhuma entrada
Sa�da: n�o retorna nenhum valor
Descri��o: registra o valor atual do display nas vari�veis do temporizador
---------------------------------------------------------------------------------------------------*/
void registra_temp(void);

/*---------------------------------------------------------------------------------------------------
Fun��o reseta_temp
Entrada: n�o recebe nenhuma entrada
Sa�da: n�o retorna nenhum valor
Descri��o: volta o display para o valor registrado nas vari�veis do temporizador
---------------------------------------------------------------------------------------------------*/
void reseta_temp(void);

/*---------------------------------------------------------------------------------------------------
Fun��o inicia_rlg
Entrada: n�o recebe nenhuma entrada
Sa�da: n�o retorna nenhum valor
Descri��o: volta o display para o valor registrado nas vari�veis do rel�gio
---------------------------------------------------------------------------------------------------*/
void inicia_rlg(void);

/*---------------------------------------------------------------------------------------------------
Fun��o trata_tecla
Entrada: n�o recebe nenhuma entrada
Sa�da: n�o retorna nenhum valor
Descri��o: executa os comandos com base na tecla que foi pressionada
---------------------------------------------------------------------------------------------------*/
void trata_tecla(char tecla);

/*---------------------------------------------------------------------------------------------------
Fun��o trata_interrupcao
Entrada: n�o recebe nenhuma entrada
Sa�da: n�o retorna nenhum valor
Descri��o: trata a passagem de segundo com base no modo atual e nas vari�veis de controle
---------------------------------------------------------------------------------------------------*/
void trata_interrupcao(void);

#endif