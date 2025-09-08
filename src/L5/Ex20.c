#include <stdio.h>
#include <stdlib.h>

int my_sqrt(int num, int low, int high) {
  if (low > high)
    return high;

  int mid = low + (high - low) / 2;
  long long square = (long long)mid * mid;

  if (square == num)
    return mid;

  if (square > num)
    return my_sqrt(num, low, mid - 1);

  return my_sqrt(num, mid + 1, high);
}

int main(int argc, char *argv[]) {
  int num;
  printf("Encontrar raiz quadrada de qual número?\n>> ");
  scanf("%d", &num);

  printf("A raiz quadrada é aproximadamente ou igual a %d.\n",
         my_sqrt(num, 0, num));

  return EXIT_SUCCESS;
}
