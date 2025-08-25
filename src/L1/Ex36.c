/*
 * Escreva um programa em C que receba 5 números inteiros
 * como argumentos na linha de comando e imprima o maior deles
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARGCOUNT 5

int validate_input(char *args[], size_t size);
bool is_digit(char ch);
int find_greatest(char *args[], size_t size);

int main(int argc, char *argv[]) {
  if (argc != ARGCOUNT + 1) {
    if (argc > ARGCOUNT + 1) {
      fprintf(stderr,
              "Muitos argumentos!\nUso correto: %s <inteiro> <inteiro> "
              "<inteiro> <inteiro> <inteiro> \n",
              argv[0]);
      return EXIT_FAILURE;
    } else {
      fprintf(stderr,
              "Poucos argumentos!\nUso correto: %s <inteiro> <inteiro> "
              "<inteiro> <inteiro> <inteiro> \n",
              argv[0]);
      return EXIT_FAILURE;
    }
  }

  if (validate_input(argv + 1, ARGCOUNT)) {
    fprintf(stderr,
            "Argumento inválido!\nUso correto: %s <inteiro> <inteiro> "
            "<inteiro> <inteiro> <inteiro>\n",
            argv[0]);
    return EXIT_FAILURE;
  }

  printf("O maior inteiro digitado foi %d\n",
         find_greatest(argv + 1, ARGCOUNT));

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

int find_greatest(char *args[], size_t size) {
  if (size == 1)
    return atoi(args[0]);

  int greatest = atoi(args[0]);
  for (size_t k = 1; k < size; k++)
    if (atoi(args[k]) > greatest)
      greatest = atoi(args[k]);

  return greatest;
}
