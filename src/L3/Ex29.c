#include <stdio.h>

typedef struct {
  char *name;
  int age;
  char *address;
} Customer;

void print_customer(Customer *customer) {
  printf("%s, %d anos, mora em %s.\n", customer->name, customer->age,
         customer->address);
}

int main() {
  Customer cliente = {"Søren Kierkegaard", 42, "Rua Dinamarca, 123"};
  Customer cliente2 = {"Mikhail Bakunin", 62, "Avenida Rússia, 456"};
  Customer cliente3 = {"Pierre Bordieu", 71, "Travessia França, 789"};

  print_customer(&cliente);
  print_customer(&cliente2);
  print_customer(&cliente3);

  return 0;
}