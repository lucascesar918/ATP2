#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_between(int min, int max);
int recursive_sum_first_n_naturals(int n);

int main(int argc, char *argv[]) {
  srand(time(NULL));
  const int num = rand_between(0, 1000);
  const int sum = recursive_sum_first_n_naturals(num);

  if (num == -1) {
    printf("Valores negativos não são contemplados no domínio da função!\n");
    return EXIT_FAILURE;
  }

  printf("A soma dos %d primeiros naturais resulta em %d.\n", num,
         recursive_sum_first_n_naturals(num));

  return EXIT_SUCCESS;
}

int rand_between(int min, int max) { return rand() % (max - min + 1) + min; }
int recursive_sum_first_n_naturals(int n) {
  if (n < 0)
    return -1;
  if (n <= 1)
    return n;

  return n + recursive_sum_first_n_naturals(n - 1);
}
