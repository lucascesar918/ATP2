#include <stdio.h>
#include <stdlib.h>

int sum_digits(int n);

int main(int argc, char *argv[]) {
  int num;
  printf("Digite um número: ");
  scanf("%d", &num);

  printf("A soma dos dígitos de %d equivale a %d.\n", num, sum_digits(num));

  return EXIT_SUCCESS;
}

int sum_digits(int n) {
  if (n < 0)
    n *= -1;
  if (n < 1)
    return 0;

  return n % 10 + sum_digits(n / 10);
}
