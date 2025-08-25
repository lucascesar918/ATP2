#include <stdio.h>
#include <stdlib.h>

void recursive_fibonacci(int n, int current, int next);

int main(int argc, char *argv[]) {
  printf("Calcular quantos números da sequência de Fibonacci?\n>> ");
  int input;
  scanf("%d", &input);

  if (input >= 47 || input < 0) {
    fprintf(stderr, "O número não está contemplado no funcionamento padrão do "
                    "programa: ");
    if (input >= 47)
      fprintf(stderr, "O inteiro digitado causa overflow!\n");
    else
      fprintf(stderr, "O valor deve ser positivo!\n");
    return EXIT_FAILURE;
  }

  recursive_fibonacci(input, 0, 1);

  return EXIT_SUCCESS;
}

void recursive_fibonacci(int n, int current, int next) {
  if (n == 0)
    return;

  printf("[%dº]: %d\n", n, current);
  recursive_fibonacci(n - 1, next, current + next);
}
