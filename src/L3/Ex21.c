#include <stdio.h>

typedef struct  {
    char* name;
    char* registration;
    double price;
} Product;

int main() {
    Product prod = {"tres tonelada de banana", "B4N4N4", 3000.50};

    printf("A estrutura de produto ocupa %lu bytes na memória.\n", sizeof(prod));

    return 0;
}