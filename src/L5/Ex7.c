#include <stdio.h>
#include <stdlib.h>

int power(int b, int exp);

int main(int argc, char *argv[]) {
  int a, n;
  printf("Digite a base: ");
  scanf("%d", &a);

  printf("Digite o expoente: ");
  scanf("%d", &n);

  printf("%d^%d = %d\n", a, n, power(a, n));

  return EXIT_SUCCESS;
}

int power(int b, int exp) {
  if (b == 0 && exp == 0)
    return -1.0;

  if (exp == 1)
    return b;

  return b * power(b, exp - 1);
}
