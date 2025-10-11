#include <stdio.h>

enum Weekday { SEG, TER, QUA, QUI, SEX, SAB, DOM };

int main() {
  const char *nomesDias[] = {"Segunda-Feira", "Terça-Feira", "Quarta-Feira",
                             "Quinta-Feira",  "Sexta-Feira", "Sábado",
                             "Domingo"};

  for (int i = SEG; i <= DOM; i++)
    printf("%s\n", nomesDias[i]);

  return 0;
}