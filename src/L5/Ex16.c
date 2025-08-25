#include <stdio.h>
#include <stdlib.h>

long long unsigned recursive_ackermann(int m, int n);

int main(int argc, char *argv[]) {
  int m, n;
  printf("Digite o inteiro m\n>> ");
  scanf("%d", &m);

  printf("Digite o inteiro n\n>> ");
  scanf("%d", &n);

  if (m < 0 || n < 0) {
    printf("Os números m e n devem ser não negativos!\n");
    return EXIT_FAILURE;
  }

  printf("Segundo a Função de Ackermann, o resultado é %d.\n",
         recursive_ackermann(m, n));

  return EXIT_SUCCESS;
}

long long unsigned recursive_ackermann(int m, int n) {
  if (m == 0)
    return n + 1;

  if (n == 0)
    return recursive_ackermann(m - 1, 1);

  if (n > 0) {
    int lhs = m - 1;
    int rhs = recursive_ackermann(m, n - 1);
    return recursive_ackermann(lhs, rhs);
  }
}
