/*
 * Escreva um programa em C que leia uma string e substitua
 * todas as ocorrências de um caractere por outro
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replace_char(char *str, char target, char src);

int main(int argc, char *argv[]) {
  const size_t bufsize = 1024;
  char *buf = malloc(sizeof(char) * bufsize);

  if (!buf) {
    perror("");
    return EXIT_FAILURE;
  }

  printf("Digite algo: ");
  fgets(buf, bufsize, stdin);

  fflush(stdin);

  printf("Caractere para procurar: ");
  char target_ch;
  scanf("%c", &target_ch);

  fflush(stdin);

  printf("Caractere para substituição: ");
  char src_ch;
  scanf("\n%c", &src_ch);

  replace_char(buf, target_ch, src_ch);
  printf(buf);

  free(buf);
  return EXIT_SUCCESS;
}

void replace_char(char *str, char target, char src) {
  const size_t size = strlen(str);
  for (size_t j = 0; j < size; j++)
    if (str[j] == target)
      str[j] = src;
}
