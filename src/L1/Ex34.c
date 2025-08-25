/*
 * Escreva um programa em C que receba uma string como
 * argumento na linha de comando e conte o número de caracteres dessa string.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc == 1) {
    fprintf(stderr, "Poucos argumentos!\nUso correto: %s <string>\n", argv[0]);
    return EXIT_FAILURE;
  }

  if (argc > 2) {
    fprintf(stderr, "Muitos argumentos!\nUso correto: %s <string>\n", argv[0]);
    return EXIT_FAILURE;
  }

  printf("A string digitada tem %d caractere%c.\n", strlen(argv[1]),
         strlen(argv[1]) == 1 ? '\0' : 's');

  return EXIT_SUCCESS;
}
