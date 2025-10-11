#include <stdio.h>

#define PRODMAX 5

typedef struct {
    char* name;
    char* id;
    double price;
} Product;

void print_product(Product* prod) {
    printf("[%s]: %s - R$ %.2f\n", prod->id, prod->name, prod->price);
}

int main() {
    Product prod = {"Notebook", "AIM123", 3600.00};
    Product prod_aux;

    prod_aux = prod;

    print_product(&prod_aux);

    return 0;
}