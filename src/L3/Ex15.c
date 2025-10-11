#include <stdio.h>

typedef struct {
  int number;
  char *street;
  char *city;
  char *state;
  char *country;
} Address;

void print_address(Address *addr) {
  printf("%s, %s, %s, %s - %d.\n", addr->country, addr->state, addr->city,
         addr->street, addr->number);
}

int main() {
  Address addr = {157, "Praça Tavares Corrêa", "Garanhuns", "Pernambuco",
                  "Brasil"};
  Address addr2;

  addr2 = addr;

  print_address(&addr2);
  return 0;
}