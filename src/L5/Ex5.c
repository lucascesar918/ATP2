#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool recursive_is_prime(int n, int current);

int main(int argc, char *argv[]) {
  printf("Digite um número:\n>> ");
  int num;
  scanf("%d", &num);

  printf("O número %d %sé primo!\n", num,
         recursive_is_prime(num, 2) ? "\0" : "não ");

  return EXIT_SUCCESS;
}

bool recursive_is_prime(int n, int current) {
  if (n < 2)
    return false;
  if (current * current > n)
    return true;
  if (n % current == 0)
    return false;
  return recursive_is_prime(n, current + 1);
}
