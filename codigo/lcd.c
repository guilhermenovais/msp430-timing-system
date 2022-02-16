#include "lcd.h"

void pulso(void) {
  __delay_cycles(200);
  CTRL |= ENABLE;
  __delay_cycles(200);
  CTRL &= ~ENABLE;
  __delay_cycles(200);
}

void envia_dado(char dado) {
  DADOS = dado;
  CTRL |= RS;
  pulso();
}

void envia_comando(char comando) {
  DADOS = comando;
  CTRL &= ~RS;
  pulso();
}

void envia_string(unsigned char *str) {
  for(; *str != 0x00; str++) {
    envia_dado(*str);
  }
}

void desloca_cursor(char indice) {
  switch(indice){
  case 0:
    envia_comando(0x80);
    break;
  case 1:
    envia_comando(0x84);
    break;
  case 2:
    envia_comando(0x85);
    break;
  case 3:
    envia_comando(0x87);
    break;
  case 4:
    envia_comando(0x88);
    break;
  case 5:
    envia_comando(0x8A);
    break;
  case 6:
    envia_comando(0x8B);
    break;
  }
}

void envia_numero(char num) {
  envia_dado(48 + num);
}

void programa_lcd(void) {
  envia_comando(RESET); 
  envia_comando(C_INATIVO);
  envia_comando(DESLOC_DIR);
  envia_comando(LIMPA_DISP);
  __delay_cycles(100000); //Espera o tempo do comando limpar display
}