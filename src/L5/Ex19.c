#include <stdio.h>
#include <stdlib.h>

int binominal_coefficient(int n, int k);

int main(int argc, char *argv[]) {
  int n, k;
  printf("Digite n: ");
  scanf("%d", &n);

  printf("Digite k: ");
  scanf("%d", &k);

  printf("O coeficiente binomial de %d e %d é igual a %d.\n", n, k,
         binominal_coefficient(n, k));

  return EXIT_SUCCESS;
}

int binominal_coefficient(int n, int k) {
  if (k == 0 || k == n)
    return 1;

  if (k > n)
    return 0;

  return binominal_coefficient(n - 1, k - 1) + binominal_coefficient(n - 1, k);
}
