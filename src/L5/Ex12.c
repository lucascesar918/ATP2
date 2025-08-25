#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void print_n_primes(int n, int current);
int kth_prime(int k);

int main(int argc, char *argv[]) {
  int n;
  printf("Quantos números primos mostrar?\n>> ");
  scanf("%d", &n);
  printf("Mostrando os %d primeiros primos...\n", n);

  print_n_primes(n, 1);

  return EXIT_SUCCESS;
}

void print_n_primes(int n, int current) {
  if (current == n) {
    printf("%d, ", kth_prime(n));
    return;
  }

  print_n_primes(n, current + 1);
  int current_prime = kth_prime(current);
  printf("%d%s", current_prime, current == 1 ? "\0" : ", ");
}

int kth_prime(int k) {
  if (k == 1)
    return 2;
  if (k == 2)
    return 3;

  return 6 * (k - 2) + 1;
}
