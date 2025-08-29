#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

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
         input, compute_path(input));

  return EXIT_SUCCESS;
}
