#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, size_t size);
void populate_array(int *array, size_t size);
bool is_prime(int n);

int main(int argc, char *argv[]) {
  const size_t arrlen = 7;
  int *array = malloc(sizeof(int) * arrlen);

  // Checando falha de alocação de memória
  if (array == NULL) {
    perror("Falha ao alocar memória!\n");
    return EXIT_FAILURE;
  }

  populate_array(array, arrlen);
  print_array(array, arrlen);

  free(array);
  return EXIT_SUCCESS;
}

// Função para printar os valores do array
void print_array(int *array, size_t size) {
  for (int j = 0; j < size; j++)
    printf("[%2.dº]: %d\n", j + 1, array[j]);
}

// Função para preencher o array
void populate_array(int *array, size_t size) {
  int c = 0, j = 0;

  while (j < size) {
    if (is_prime(c))
      array[j++] = c;
    c++;
  }
}

bool is_prime(int n) {
  if (n <= 1)
    return false;
  if (n <= 3)
    return true;
  if (n % 2 == 0 || n % 3 == 0)
    return false;

  for (int i = 5; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0)
      return false;

  return true;
}
