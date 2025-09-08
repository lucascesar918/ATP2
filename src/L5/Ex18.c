#include <stdio.h>
#include <stdlib.h>

void solve_hanoi(int n, char origin, char end, char aux);

int main(int argc, char *argv[]) {
  int n;

  printf("Solução para quantos discos?\n>> ");
  scanf("%d", &n);
  solve_hanoi(n, 'A', 'C', 'B');

  return EXIT_SUCCESS;
}

void solve_hanoi(int n, char origin, char end, char aux) {
  if (n == 1) {
    printf("Mover disco 1 de %c para %c.\n", origin, end);
    return;
  }

  solve_hanoi(n - 1, origin, aux, end);
  printf("Mover disco %d de %c para %c.\n", n, origin, end);
  solve_hanoi(n - 1, aux, end, origin);
}
