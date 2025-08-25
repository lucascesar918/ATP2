#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

uint64_t recursive_factorial(int n);
int rand_between(int min, int max);

int main(int argc, char *argv[]) {
  srand(time(NULL));
  const int num = rand_between(-2, 23); // A partir do 20 há overflow do valor
  const uint64_t fact_calc = recursive_factorial(num);

  if (fact_calc == -1) {
    printf("O número %d está fora da abrangência do programa!\n", num);
    return EXIT_FAILURE;
  }

  printf("%d! = %llu\n", num, fact_calc);

  return EXIT_SUCCESS;
}

uint64_t recursive_factorial(int n) {
  if (n < 0 || n > 20)
    return -1;
  if (n <= 1)
    return n;

  return (uint64_t)n * recursive_factorial(n - 1);
}

int rand_between(int min, int max) { return rand() % (max - min + 1) + min; }
