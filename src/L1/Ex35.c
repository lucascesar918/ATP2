/*
 * Escreva um programa em C que receba um número inteiro
 * como argumento na linha de comando e verifique se ele é par ou ímpar.
 * */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARGCOUNT 1

int validate_input(char *args[], size_t size);
bool is_digit(char ch);

int main(int argc, char *argv[]) {
  if (argc != ARGCOUNT + 1) {
    if (argc > ARGCOUNT + 1) {
      fprintf(stderr, "Muitos argumentos!\nUso correto: %s <inteiro>\n",
              argv[0]);
      return EXIT_FAILURE;
    } else {
      fprintf(stderr, "Poucos Argumentos!\nUso correto: %s <inteiro>\n",
              argv[0]);
      return EXIT_FAILURE;
    }
  }

  if (validate_input(argv + 1, ARGCOUNT)) {
    fprintf(stderr, "Argumento inválido!\nUso correto: %s <inteiro>\n",
            argv[0]);
    return EXIT_FAILURE;
  }

  int input = atoi(argv[1]);
  printf("O inteiro digitado é %s!\n", input % 2 == 0 ? "par" : "ímpar");

  return EXIT_SUCCESS;
}

int validate_input(char *args[], size_t size) {
  size_t current_strlen;
  for (size_t k = 0; k < size; k++) {
    current_strlen = strlen(args[k]);
    for (size_t l = 0; l < current_strlen && args[k][l] != '\0'; l++) {
      if (!is_digit(args[k][l]))
        return 1;
    }
  }

  return 0;
}

bool is_digit(char ch) { return ch >= '0' && ch <= '9'; }
