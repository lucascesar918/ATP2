#include <stdio.h>

#define PRODMAX 5

typedef struct {
  char *name;
  char *id;
  double price;
} ProductList[5];

void print_productlist(const ProductList prodlist) {
  for (int i = 0; i < PRODMAX; i++) {
    printf("[%s] %s: %.2f\n", prodlist[i].id, prodlist[i].name,
           prodlist[i].price);
  }
}

int main() {
  ProductList carrinho = {{"Notebook", "AIM123", 3600.00},
                          {"Celular", "BIM456", 1200.00},
                          {"Chuveiro", "CIM789", 350.00},
                          {"Geladeira", "DIM012", 6000.00},
                          {"Forno Elétrico", "EIM345", 1500.00}};

  print_productlist(carrinho);

  return 0;
}