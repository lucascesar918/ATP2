#include <stdio.h>
#include <stdlib.h>

void print_array(float *array, size_t size);
void populate_array(float *array, size_t size);
int nth_fibonacci(int n);

int main(int argc, char *argv[]) {
  const size_t arrlen = 8;
  float *array = malloc(sizeof(float) * arrlen);

  // Checando falha de alocação de memória
  if (array == NULL) {
    perror("Falha ao alocar memória!\n");
    free(array);
    return EXIT_FAILURE;
  }

  populate_array(array, arrlen);
  print_array(array, arrlen);

  free(array);
  return EXIT_SUCCESS;
}

// Função para printar os valores do array
void print_array(float *array, size_t size) {
  for (int j = 0; j < size; j++)
    printf("[%d°]: %.2f\n", j + 1, array[j]);
}

// Função para preencher o array
void populate_array(float *array, size_t size) {
  for (int c = 0; c < size; c++)
    array[c] = nth_fibonacci(c);
}

int nth_fibonacci(int n) {
  if (n == 0 || n == 1)
    return n;

  return nth_fibonacci(n - 1) + nth_fibonacci(n - 2);
}
