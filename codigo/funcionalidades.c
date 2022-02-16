#include "funcionalidades.h"

// Variáveis de controle do sistema de temporização
char disparar = 0; // Setado se o temporizador ou o cronômetro devem rodar
char modo = 0; // 0: Relógio, 1: temporizador, 2: cronômetro
char temp = 1; // Armazena a soma dos dígitos no temporizador (se for 0, o temporizador chegou a 00:00:00)
char temp_zerou = 0; // Setado quando o temporizador chega a 00:00:00

// Variáveis que armazenam os dígitos do display
char d1 = 0; // Dezena das horas no display
char d2 = 0; // Unidade das horas no display
char d3 = 0; // Dezena dos minutos no display
char d4 = 0; // Unidade dos minutos no display
char d5 = 0; // Dezena dos segundos no display 
char d6 = 0; // Unidade dos segundos no display

// Variáveis que armazenam os dígitos do relógio
char r1 = 0; // Dezena das horas do relógio
char r2 = 0; // Unidade das horas do relógio
char r3 = 0; // Dezena dos minutos do relógio
char r4 = 0; // Unidade dos minutos do relógio
char r5 = 0; // Dezena dos segundos do relógio
char r6 = 0; // Unidade dos segundos do relógio

// Variáveis que armazenam os dígitos do valor inicial do temporizador
char t1 = 0; // Dezena das horas do valor inicial do temporizador
char t2 = 0; // Unidade das horas do valor inicial do temporizador
char t3 = 1; // Dezena dos minutos do valor inicial do temporizador
char t4 = 0; // Unidade dos minutos do valor inicial do temporizador
char t5 = 0; // Dezena dos segundos do valor inicial do temporizador
char t6 = 0; // Unidade dos segundos do valor inicial do temporizador

void inc_seg_disp(void) {

  // Atualiza o display
  if(d6 < 9) {
    d6++;
    desloca_cursor(6);
    envia_numero(d6);
  }
  else { // Caso a unidade dos segundos atingiu 9
    d6 = 0;
    desloca_cursor(6);
    envia_numero(d6);
    if(d5 < 5) {
      d5++;
      desloca_cursor(5);
      envia_numero(d5);
    }
    else { // Caso a dezena dos segundos atingiu 5
      d5 = 0;
      desloca_cursor(5);
      envia_numero(d5);
      inc_min_disp();
    }
  }
}

void inc_min_disp(void) {
  if(d4 < 9) {
    d4++;
    desloca_cursor(4);
    envia_numero(d4);
  }
  else { // Caso a unidade dos minutos atingiu 9
    d4 = 0;
    desloca_cursor(4);
    envia_numero(d4);
    if(d3 < 5) {
      d3++;
      desloca_cursor(3);
      envia_numero(d3);
    }
    else { // Caso a dezena dos minutos atingiu 5
      d3 = 0;
      desloca_cursor(3);
      envia_numero(d3);
      inc_hora_disp();
    }
  }
}

void inc_hora_disp(void) {
  if((d2 < 9 && d1 < 2) || (d2 < 3 && d1 == 2)) { // Caso a dezena das horas não precise ser mudada
    d2++;
    desloca_cursor(2);
    envia_numero(d2);
  }
  else if (d2 == 9) { // Caso a dezena das horas precise ser mudada
    d2 = 0;
    desloca_cursor(2);
    envia_numero(d2);
    d1++;
    desloca_cursor(1);
    envia_numero(d1);
  }
  else if (d3 == 5 && d4 == 9){ // Caso seja 23:59:59
    zera_disp();
  }
  else {
    d1 = 0;
    desloca_cursor(1);
    envia_numero(d1);
    d2 = 0;
    desloca_cursor(2);
    envia_numero(d2);
  }
}

void inc_seg_rlg(void) {
  // Atualiza as variáveis do relógio
  if(r6 < 9) {
    r6++;
  }
  else { // Caso a unidade dos segundos atingiu 9
    r6 = 0;
    if(r5 < 5) {
      r5++;
    }
    else { // Caso a dezena dos segundos atingiu 5
      r5 = 0;
      inc_min_rlg();
    }
  }
}

void inc_min_rlg(void) {
  if(r4 < 9) {
    r4++;
  }
  else { // Caso a unidade dos minutos atingiu 9
    r4 = 0;
    if(r3 < 5) {
      r3++;
    }
    else { // Caso a dezena dos minutos atingiu 5
      r3 = 0;
      inc_hora_rlg();
    }
  }
}

void inc_hora_rlg(void) {
  if((r2 < 9 && r1 < 2) || (r2 < 3 && r1 == 2)) { // caso não seja necessária uma mudança nas dezenas
    r2++;
  }
  else if (r2 == 9) { // Caso seja necessária uma mudança nas dezenas
    r2 = 0;
    r1++;
  }
  else if (r3 == 5 && r4 == 9){ // Caso seja 23:59:59
    r1 = 0;
    r2 = 0;
    r3 = 0;
    r4 = 0;
    r5 = 0;
    r6 = 0;
  }
  else {
    r1 = 0;
    r2 = 0;
  }
}

char dec_seg_disp(void) {
  if(d6 > 0) {
    d6--;
    desloca_cursor(6);
    envia_numero(d6);
  }
  else { // Caso a unidade dos segundos atingiu 0
    d6 = 9;
    desloca_cursor(6);
    envia_numero(d6);
    if(d5 > 0) {
      d5--;
      desloca_cursor(5);
      envia_numero(d5);
    }
    else { // Caso a dezena dos segundos atingiu 0
      d5 = 5;
      desloca_cursor(5);
      envia_numero(d5);
      dec_min_disp();
    }
  }
  return (d1 + d2 + d3 + d4 + d5 + d6);
}

void dec_min_disp(void) {
  if(d4 > 0) {
    d4--;
    desloca_cursor(4);
    envia_numero(d4);
  }
  else { // Caso a unidade dos minutos atingiu 0
    d4 = 9;
    desloca_cursor(4);
    envia_numero(d4);
    if(d3 > 0) {
      d3--;
      desloca_cursor(3);
      envia_numero(d3);
    }
    else { // Caso a dezena dos minutos atingiu 0
      d3 = 5;
      desloca_cursor(3);
      envia_numero(d3);
      dec_hora_disp();
    }
  }
}

void dec_hora_disp(void) {
  if(d2 > 0) {
    d2--;
    desloca_cursor(2);
    envia_numero(d2);
  }
  else { // Caso a unidade das horas atingiu 0
    d2 = 9;
    desloca_cursor(2);
    envia_numero(d2);
    if(d1 > 0) {
      d1--;
      desloca_cursor(1);
      envia_numero(d1);
    }
    else { // Caso a dezena dos minutos atingiu 0
      d1 = 2;
      desloca_cursor(1);
      envia_numero(d1);
      d2 = 3;
      desloca_cursor(2);
      envia_numero(d2);
    }
  }
}

void dec_min_rlg(void) {
  if(r4 > 0) {
    r4--;
  }
  else { // Caso a unidade dos minutos atingiu 0
    r4 = 9;
    if(r3 > 0) {
      r3--;
    }
    else { // Caso a dezena dos minutos atingiu 0
      r3 = 5;
      dec_hora_rlg();
    }
  } 
}
    
void dec_hora_rlg(void) {
  if(r2 > 0) {
    r2--;
  }
  else { // Caso a unidade das horas atingiu 0
    r2 = 9;
    if(r1 > 0) {
      r1--;
    }
    else { // Caso a dezena dos minutos atingiu 0
      r1 = 2;
      r2 = 3;
    }
  }
}

void zera_disp(void) {
  d1 = 0;
  desloca_cursor(1);
  envia_numero(d1);
  d2 = 0;
  desloca_cursor(2);
  envia_numero(d2);
  d3 = 0;
  desloca_cursor(3);
  envia_numero(d3);
  d4 = 0;
  desloca_cursor(4);
  envia_numero(d4);
  d5 = 0;
  desloca_cursor(5);
  envia_numero(d5);
  d6 = 0;
  desloca_cursor(6);
  envia_numero(d6);
}

void inicia_temp(void) {
  d1 = t1;
  desloca_cursor(1);
  envia_numero(d1);
  d2 = t2;
  desloca_cursor(2);
  envia_numero(d2);
  d3 = t3;
  desloca_cursor(3);
  envia_numero(d3);
  d4 = t4;
  desloca_cursor(4);
  envia_numero(d4);
  d5 = t5;
  desloca_cursor(5);
  envia_numero(d5);
  d6 = t6;
  desloca_cursor(6);
  envia_numero(d6);
}

void registra_temp(void) {
  t1 = d1;
  t2 = d2;
  t3 = d3;
  t4 = d4;
  t5 = d5;
  t6 = d6;
}

void reseta_temp(void) {
  d1 = t1;
  desloca_cursor(1);
  envia_numero(d1);
  d2 = t2;
  desloca_cursor(2);
  envia_numero(d2);
  d3 = t3;
  desloca_cursor(3);
  envia_numero(d3);
  d4 = t4;
  desloca_cursor(4);
  envia_numero(d4);
  d5 = t5;
  desloca_cursor(5);
  envia_numero(d5);
  d6 = t6;
  desloca_cursor(6);
  envia_numero(d6);
}

void inicia_rlg(void) {
  d1 = r1;
  desloca_cursor(1);
  envia_numero(d1);
  d2 = r2;
  desloca_cursor(2);
  envia_numero(d2);
  d3 = r3;
  desloca_cursor(3);
  envia_numero(d3);
  d4 = r4;
  desloca_cursor(4);
  envia_numero(d4);
  d5 = r5;
  desloca_cursor(5);
  envia_numero(d5);
  d6 = r6;
  desloca_cursor(6);
  envia_numero(d6);
}

void trata_tecla(char tecla) {
  switch (modo)
      {
      case 0: // Relógio
        switch (tecla) {
              case 0x37: // H+
                inc_hora_disp();
                inc_hora_rlg();
                break;
              case 0x34: // H-
                dec_hora_disp();
                dec_hora_rlg();
                break;
              case 0x31: // M+
                inc_min_disp();
                inc_min_rlg();
                break;
              case 0x2E: // M-                
                dec_min_disp();
                dec_min_rlg();
                break;
              case 0x39: // T
                modo = 1;
                inicia_temp();
                registra_temp();
                disparar = 0;
                temp_zerou = 0;
                desloca_cursor(0);
                envia_dado('T');
                break;
              case 0x2F: // C
                modo = 2;
                zera_disp();
                disparar = 0;
                desloca_cursor(0);
                envia_dado('C');
                break;
              default:
                break;
              }
        break;

      case 1: // Temporizador
        switch (tecla)
              {
              case 0x37: // H+
                inc_hora_disp();
                registra_temp();
                break;
              case 0x34: // H-
                dec_hora_disp();
                registra_temp();
                break;
              case 0x31: // M+
                inc_min_disp();
                registra_temp();
                break;
              case 0x2E: // M-
                dec_min_disp();
                registra_temp();
                break;
              case 0x36: // Z
                inicia_temp();
                disparar = 0;
                temp_zerou = 0;
                break;
              case 0x33: // D
                disparar = 1;
                break;
              case 0x3D: // P
                disparar = 0;
                break;
              case 0x38: // R
                modo = 0;
                inicia_rlg();
                desloca_cursor(0);
                envia_dado('R');
                break;
              case 0x2F: // C
                modo = 2;
                zera_disp();
                disparar = 0;
                desloca_cursor(0);
                envia_dado('C');
                break;
              default:
                break;
              }
        break;

      case 2: // Cronômetro
        switch (tecla) {
              case 0x36: // Z
                zera_disp();
                disparar = 0;
                break;
              case 0x33: // D
                disparar = 1;
                break;
              case 0x3D: // P
                disparar = 0;
                break;
              case 0x38: // R
                modo = 0;
                inicia_rlg();
                desloca_cursor(0);
                envia_dado('R');
                break;
              case 0x39: // T
                modo = 1;
                inicia_temp();
                registra_temp();
                disparar = 0;
                temp_zerou = 0;
                desloca_cursor(0);
                envia_dado('T');
                break;
              default:
                break;
              }
        break;

      default:
        break;
      }
}

void trata_interrupcao(void) {
  inc_seg_rlg();
    
    // Caso esteja no modo Relógio ou no modo Cronômetro com disparar setado
    if(modo == 0 || (modo == 2 && disparar)) { 
      inc_seg_disp();
    }
    
    // Caso esteja no modo Temporizador com disparar setado e temp_zerou resetado
    else if(modo == 1 && disparar && temp_zerou == 0) {
      temp = dec_seg_disp();
      if(temp == 0) {
        disparar = 0;
        temp_zerou = 1;
      }
    }
}