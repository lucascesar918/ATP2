#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recursive_inv_string(char *str, int current, const size_t size);

int main(int argc, char *argv[]) {
  const size_t arrlen = 1024;
  char *str = malloc(sizeof(char) * arrlen);

  if (!str) {
    perror("");
    return EXIT_FAILURE;
  }

  printf("Digite uma string: ");
  fgets(str, arrlen, stdin);

  recursive_inv_string(str, 0, strlen(str));
  printf("String invertida: %s", str);

  free(str);
  return EXIT_SUCCESS;
}

void recursive_inv_string(char *str, int current, const size_t size) {
  if (size <= 1)
    return;
  int k = size - 1;
  if (current > k)
    return;

  recursive_inv_string(str, current + 1, k);
  char aux = str[current];
  str[current] = str[k];
  str[k] = aux;
}
