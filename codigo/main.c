/*--------------------------------------------------------------------------------------------------------
Question�rio 5 - Sistema de Temporiza��o
Autor: Guilherme Novais de Souza
Descri��o do Programa: Sistema de Temporiza��o composto pelos modos de Rel�gio, Temporizador e Cron�metro.
O sistema foi feito para o hardware MSP430F1121, que deve ser ligado a um display LCD 16x1 e a um teclado
matricial de 4x4. Ao ser ligado, o sistema entra no modo rel�gio. Pode-se selecionar os modos por meio das
teclas R, T e C. As teclas H+, H-, M+ e M- possuem diferentes fun��es dependendo do modo de funcionamento 
atual.
---------------------------------------------------------------------------------------------------------*/
#include "msp430f1121.h"

#include "lcd.h"
#include "teclado.h"
#include "timer.h"
#include "funcionalidades.h"

int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;

  configura_msp(); 
  programa_lcd();
  envia_string("R   00:00:00");
  configura_timer();
  
  char caractere; //Inicializa a vari�vel que vai armazenar o caractere dentro do loop

  while(1) {
    caractere = teclado(); //Armazena o caractere na vari�vel

    if(caractere != 0x00) { //Quando alguma tecla for pressionada
        trata_tecla(caractere);
      }
  }
  
  return 0;
}

#pragma vector = TIMER0_A1_VECTOR
__interrupt void TIMER0_A1_ISR(void) {
  switch(__even_in_range(TA0IV, 0x0A)){
  case TA0IV_NONE:
    break;
  case TA0IV_TACCR1:
    break;
  case TA0IV_6:
    break;
  case TA0IV_8:
    break;
  case TA0IV_TAIFG:
    trata_interrupcao();
    break;
  default:
    break;
  }
}