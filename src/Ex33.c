/*
 * Escreva um programa em C que receba 3 números inteiros como
 * argumentos na linha de comando e imprima a soma deles.
 * */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARGCOUNT 3

int sum_str_array(char *src_array[], size_t size);
int validate_input(char *args[], size_t size);
bool is_digit(char ch);

int main(int argc, char *argv[]) {
  if (argc != ARGCOUNT + 1) {
    if (argc > ARGCOUNT + 1) {
      fprintf(stderr,
              "Muitos argumentos!\nUso correto: %s [Inteiro 1] [Inteiro 2] "
              "[Inteiro 3]\n",
              argv[0]);
      return EXIT_FAILURE;
    } else {
      fprintf(stderr,
              "Poucos argumentos!\nUso correto: %s [Inteiro 1] [Inteiro 2] "
              "[Inteiro 3]\n",
              argv[0]);
      return EXIT_FAILURE;
    }
  }

  if (validate_input(argv + 1, ARGCOUNT)) {
    fprintf(stderr,
            "Argumento inválido!\nUso correto: %s [Inteiro 1] [Inteiro 2] "
            "[Inteiro 3]\n",
            argv[0]);
    return EXIT_FAILURE;
  }

  printf("A soma dos argumentos passados resulta em %d.\n",
         sum_str_array(&argv[1], ARGCOUNT));

  return EXIT_SUCCESS;
}

int sum_str_array(char *src_array[], size_t size) {
  int sum = 0;

  for (size_t j = 0; j < size; j++)
    sum += atoi(src_array[j]);

  return sum;
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
