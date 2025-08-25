/*
 * Escreva um programa em C que leia uma string e verifique
 * se ela é um palíndromo.
 * */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_palindrome(char *str);
void trim_newline(char *str);

int main(int argc, char *argv[]) {
  const size_t bufsize = 1024;
  char *buf = malloc(sizeof(char) * bufsize);

  if (!buf) {
    perror("");
    return EXIT_FAILURE;
  }

  printf("Digite algo:\n");
  fgets(buf, bufsize, stdin);
  trim_newline(buf);

  printf("A string digitada %s um palíndromo!\n",
         is_palindrome(buf) ? "é" : "não é");

  free(buf);
  return EXIT_SUCCESS;
}

bool is_palindrome(char *str) {
  size_t j = 0, k = strlen(str) - 1;
  while (j < k) {
    if (str[j++] != str[k--])
      return false;
  }

  return true;
}

void trim_newline(char *str) {
  char *newline_char = strrchr(str, '\n');

  if (newline_char)
    *newline_char = '\0';
}
