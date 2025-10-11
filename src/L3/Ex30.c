#include <stdio.h>

typedef struct {
    int x;
    int y;
    int z;
} Position;

typedef struct {
    Position corner_a;
    Position corner_b;
} Cube;

int main() {
    Cube cubo = {{0, 0, 0}, {10, 10, 10}};

    printf("O cubo no plano começa em x:%d, y:%d, z:%d e termina em x:%d, y:%d, z:%d\n",
        cubo.corner_a.x,
        cubo.corner_a.y,
        cubo.corner_a.z,
        cubo.corner_b.x,
        cubo.corner_b.y,
        cubo.corner_b.z
    );

    return 0;
}