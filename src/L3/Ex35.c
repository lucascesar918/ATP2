#include <stdio.h>

typedef enum { SUMMER, SPRING, FALL, WINTER } Season;

char *get_season_name(Season season) {
  switch (season) {
  case SUMMER:
    return ("Verão");
  case SPRING:
    return ("Primavera");
  case FALL:
    return ("Outono");
  case WINTER:
    return ("Inverno");
  default:
    return ("?????");
  }
}

int main() {
  for (Season i = 0; i <= WINTER; i++)
    printf("%s\n", get_season_name(i));

  return 0;
}