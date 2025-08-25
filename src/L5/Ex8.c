#include <stdio.h>
#include <stdlib.h>

int recursive_gcd(int a, int b);

int main(int argc, char *argv[]) {
  int a, b;
  printf("Digite um número: ");
  scanf("%d", &a);

  printf("Digite outro número: ");
  scanf("%d", &b);

  printf("O MDC de %d e %d é %d.\n", a, b, recursive_gcd(a, b));

  return EXIT_SUCCESS;
}

int recursive_gcd(int a, int b) {
  if (a < 0)
    a *= -1;
  if (b < 0)
    b *= -1;
  if (b == 0)
    return a;

  return recursive_gcd(b, a % b);
}
