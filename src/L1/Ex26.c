/*
 * Escreva um programa em C que leia duas strings e concatene-as. Imprima a
 * string resultante.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trim_newline(char *str);

int main(int argc, char *argv[]) {
  const size_t bufsize = 1024;
  char *buffer1 = malloc(sizeof(char) * bufsize);
  char *buffer2 = malloc(sizeof(char) * bufsize);

  if (!buffer1 || !buffer2) {
    perror("");
    return EXIT_FAILURE;
  }

  printf("Digite qualquer coisa:\n");
  fgets(buffer1, bufsize, stdin);
  printf("Digite qualquer coisa novamente:\n");
  fgets(buffer2, bufsize, stdin);
  trim_newline(buffer1); // Remover caractere de nova linha do buffer 1
  trim_newline(buffer2); // Remover caractere de nova linha do buffer 2

  printf("\n%s\n", strcat(buffer1, buffer2));

  free(buffer1);
  free(buffer2);
  return EXIT_SUCCESS;
}

void trim_newline(char *str) {
  char *newline_char = strrchr(str, '\n');

  if (newline_char)
    *newline_char = '\0';
}
