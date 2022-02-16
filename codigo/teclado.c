#include "teclado.h"
#include "lcd.h"

// Tabelas do teclado matricial
const char TAB_TEC[] = {0x00, 0x37, 0x38, 0x39, 0X2F, 0x34, 0x35, 0x36, 0x2A, 0x31, 0x32, 0x33, 0x2D, 0x2E, 0x30, 0x3D, 0x2B};
const char TAB_LIN[] = {0xfe,0x0d,0x0b,0x07,0x00};

char ler_colunas(void) {
  char colunas; //Inicializa a variável que será retornada

  CTRL &= ~OE_74HC241; //Zera o bit OE
  //Olha as colunas 1 e 2
  switch (P2IN & (DADO_0 + DADO_1)) {
  case 0x02:
    colunas = 1;
    break;
  case 0x01:
    colunas = 2;
    break;
  
  default: //Caso nem a coluna 1 nem a coluna 2 estejam ativas
    CTRL |= OE_74HC241; //Seta o bit OE
    // Olha as colunas 3 e 4
    switch (P2IN & (DADO_0 + DADO_1)) {
    case 0x02:
      colunas = 4;
      break;
    case 0x01:
      colunas = 8;
      break;
    default: //Caso nenhuma coluna esteja ativa
      colunas = 0;
      break;
    }
    break;
  }
  return colunas;
}

char teclado(void) {
  char *APT_TEC = (char *) TAB_TEC; //Inicializa o ponteiro com o endereço do vetor com as teclas
  char *APT_LIN = (char *) TAB_LIN; //Inicializa o ponteiro com o endereço do vetor com as linhas
  DADOS = 0xF0; //Zera todas as linhas do teclado matricial
  char COLUNAS = ler_colunas();

  if(COLUNAS != 0x00) {
    __delay_cycles(100000); //tempo_repique

    DADOS = *APT_LIN;
    COLUNAS = ler_colunas();
    //Se a primeira linha não tiver nenhuma coluna ativa, entra no loop 
    while(COLUNAS == 0 & *APT_LIN != 0x00) {
      APT_TEC += 4; //Soma 4 ao ponteiro das teclas
      APT_LIN += 1; //Soma 1 ao ponteiro das linhas
      DADOS = *APT_LIN; //Passa para a próxima linha do teclado matricial
      COLUNAS = ler_colunas(); //Registra o valor das colunas nessa linha
    }

    if(*APT_LIN == 0x00) { //Confere se o ponteiro percorreu todo o vetor das linhas
      APT_TEC = (char *) TAB_TEC;
    }
    else {
      switch(COLUNAS) {
        case 1:
          APT_TEC += 1;
          break;
        
        case 2: // Caso a segunda coluna tenha sido ativada
          APT_TEC += 2;
          break;
        
        case 4: // Caso a terceira coluna tenha sido ativada
          APT_TEC += 3;
          break;
        
        case 8: // Caso a quarta coluna tenha sido ativada
          APT_TEC += 4;
          break;
        
        default: // Caso mais de uma coluna tenha sido ativada
          APT_TEC = (char *) TAB_TEC;
          break;
      }
    }
  }
  
  return *APT_TEC; //Retorna o código ASCII do caractere
}