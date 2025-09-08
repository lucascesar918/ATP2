#include <stdio.h>
#include <stdlib.h>

unsigned long long compute_nxn_pathways(int n);
unsigned long long recursive_pathway_count(int n, int j, int k);

int main(int argc, char *argv[]) {
  int input;
  printf("Calcular para uma grade de qual largura e altura?\n>> ");
  scanf("%d", &input);
  if (input < 0)
    input *= -1;
  if (input == 0) {
    printf("Não existem grades 0x0!\n");
    return EXIT_FAILURE;
  }

  printf("Calculando rotas numa grade %dx%d...\n", input, input);

  printf("Uma grade %dx%d tem um total de %llu caminhos possíveis!\n", input,
         input, compute_nxn_pathways(input));

  return EXIT_SUCCESS;
}

unsigned long long compute_nxn_pathways(int n) {
  return recursive_pathway_count(n, 1, 1);
}

unsigned long long recursive_pathway_count(int n, int j, int k) {
  // Não compensa a segurança de checar por 0 em toda a call stack,
  // então fica a critério da implementação interface.
  if (n == j || n == k) {
    return 1;
  }

  return recursive_pathway_count(n, j + 1, k) +
         recursive_pathway_count(n, j, k + 1);
}
