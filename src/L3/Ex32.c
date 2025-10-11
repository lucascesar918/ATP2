#include <stdio.h>

#define PROD_MAX 4

typedef struct  {
    char* name;
    char* registration;
    double price;
} Product;

void print_product_list(Product prodlist[]) {
    for (int i=0; i<PROD_MAX; i++)
        printf("[%s]: '%s' - %.2f\n", prodlist[i].registration, prodlist[i].name, prodlist[i].price);
}

int main() {
    Product prodlist[PROD_MAX] = {
        {"tres tonelada de banana", "B4N4N4", 3000.50},
        {"tres tonelada de maçã", "M4C4", 6000.50},
        {"tres tonelada de kiwi", "K1W1", 1000.50},
        {"tres tonelada de manga", "M4NG4", 7000.50}
    };

    print_product_list(prodlist);

    return 0;
}