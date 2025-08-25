#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int *array, size_t size);
void populate_array(int *array, size_t size);
int recursive_array_gdb(int *array, size_t size);
int gcd(int a, int b);

int main(int argc, char *argv[]) {
  const size_t arrlen = 5;
  int *arr = malloc(sizeof(int) * arrlen);

  if (!arr) {
    perror("");
    return EXIT_FAILURE;
  }

  populate_array(arr, arrlen);
  printf("Array utilizado: ");
  print_array(arr, arrlen);

  printf("\nO Máximo Divisor Comum é %d.\n", recursive_array_gdb(arr, arrlen));

  free(arr);
  return EXIT_SUCCESS;
}

int recursive_array_gdb(int *array, size_t size) {
  if (size == 1)
    return array[0];
  if (size != 2) {
    int x1 = recursive_array_gdb(array, size / 2);
    int x2 = recursive_array_gdb(array + (size / 2), size - (size / 2));

    return gcd(x1, x2);
  }

  return gcd(array[0], array[1]);
}

void print_array(int *array, size_t size) {
  for (size_t k = 0; k < size; k++)
    printf("%d%s", array[k], k == size - 1 ? "\0" : ", ");
}

void populate_array(int *array, size_t size) {
  for (size_t j = 0; j < size; j++) {
    printf("Digite o %dº número: ", j + 1);
    scanf("%d", &array[j]);
  }
}

int gcd(int a, int b) {
  if (a < 0)
    a *= -1;
  if (b < 0)
    b *= -1;

  while (b != 0) {
    int aux = b;
    b = a % b;
    a = aux;
  }

  return a;
}
