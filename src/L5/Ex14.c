#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool recursive_is_palindrome(char *src, int span);
void trim_newline(char *src) { src[strcspn(src, "\n")] = '\0'; }

int main(int argc, char *argv[]) {
  const size_t bufsize = 1024;
  char *buf = malloc(sizeof(char) * bufsize);

  if (!buf) {
    perror("Falha na alocação de memória!");
    return EXIT_FAILURE;
  }

  printf("Digite uma string\n>> ");
  fgets(buf, bufsize, stdin);
  trim_newline(buf);

  printf("A string digitada%sé um palíndromo!\n",
         recursive_is_palindrome(buf, 0) ? " " : " não ");

  free(buf);
  return EXIT_SUCCESS;
}

bool recursive_is_palindrome(char *src, int span) {
  if (strlen(src) == 0)
    return false;
  if (strlen(src) - span <= 1)
    return true;

  return src[0] == src[strlen(src) - 1 - span] &&
         recursive_is_palindrome(src + 1, span + 1);
}
