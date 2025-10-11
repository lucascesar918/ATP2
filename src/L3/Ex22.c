#include <stdio.h>

int main() {
  union {
    int uint;   // Int genérico
    char *ustr; // Long unsigned pro endereço da string
  } u;

  printf("Modificando a string...\n");

  u.ustr = "Hello, World!";
  printf("Int representado incorretamente: %d\n", u.uint);
  printf("String: %s\n", u.ustr);

  printf("\nModificando o int...\n");

  u.uint = 46;
  printf("Int: %d\n", u.uint);
  printf(
      "Tentando representar a string e causando segfault...\n"); // Ocorre por
                                                                 // tentar
                                                                 // acessar o
                                                                 // endereço na
                                                                 // memória 46,
                                                                 // que não é
                                                                 // permitido
  printf("String representada incorretamente: %s\n", u.ustr);

  return 0;
}