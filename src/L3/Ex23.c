#include <stdio.h>

typedef enum {
  JAN,
  FEB,
  MAR,
  APR,
  MAY,
  JUN,
  JUL,
  AUG,
  SEP,
  OCT,
  NOV,
  DEC
} Month;

char *get_month_name(Month month) {
  switch (month) {
  case JAN:
    return "Janeiro";
  case FEB:
    return "Fevereiro";
  case MAR:
    return "Março";
  case APR:
    return "Abril";
  case MAY:
    return "Maio";
  case JUN:
    return "Junho";
  case JUL:
    return "Julho";
  case AUG:
    return "Agosto";
  case SEP:
    return "Setembro";
  case OCT:
    return "Outubro";
  case NOV:
    return "Novembro";
  case DEC:
    return "Dezembro";
  default:
    return "Desconhecido";
  }
}

int main() {
  for (int i = 0; i <= DEC; i++)
    printf("%s\n", get_month_name(i));

  return 0;
}