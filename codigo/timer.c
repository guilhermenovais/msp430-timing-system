#include "timer.h"

#define CICLOS 32767

void configura_msp(void) {
  DADOS_DIR = 0xFF;
  DADOS = 0x00;
  CTRL_DIR = 0xFC;
  CTRL &= 0xF8;
}

void configura_timer(void) {
  TA0R = 0; // Reseta o contador
  TACTL = TASSEL_1 + // Fonte do clock: ACLK (1MHz)
          MC_1 +     // Modo de contagem: Crescente
          ID_0 +     // Divisão por 1
          TAIE;      // Habilita a interrupção do núcleo
  TA0CCR0 = CICLOS; 
  __bis_SR_register(GIE);
}