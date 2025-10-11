#include <stdio.h>

typedef struct {
  int x;
  int y;
  int z;
} Point;

int main() {
  Point mypoint = {1, 2, 3};

  printf("Ponto localizado em x:%d, y:%d, z:%d\n", mypoint.x, mypoint.y,
         mypoint.z);

  return 0;
}