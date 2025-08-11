/*
  Escreva um programa em C que leia uma string e conte o número
  de caracteres, palavras e linhas na string.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_words(char *str);
int count_lines(char *str);

int main(int argc, char *argv[]) {
  const size_t bufsize = 1024 * 1024;
  char *buffer = malloc(sizeof(char) * bufsize);

  if (!buffer) {
    perror("");
    return EXIT_FAILURE;
  }

  printf("Digite o que quiser.\n");
  fgets(buffer, bufsize, stdin);

  printf("%zu caracteres\n", strlen(buffer) - 1);
  printf("%d palavras\n", count_words(buffer));
  printf("%d linhas\n", count_lines(buffer));

  free(buffer);
  return EXIT_SUCCESS;
}

int count_words(char *str) {
  if (strlen(str) == 0 || str[0] == '\n')
    return 0;
  int count = 1;

  for (size_t j = 0; str[j] != '\0'; j++) {
    while (str[j] == ' ') {
      j++;
      if (str[++j] != ' ' && str[j] != '\0')
        count++;
    }
  }

  return count;
}

int count_lines(char *str) {
  if (strlen(str) == 0)
    return 0;
  int count = 0;

  for (size_t j = 0; str[j] != '\0'; j++) {
    if (str[j] == '\n')
      count++;
  }

  return count;
}
