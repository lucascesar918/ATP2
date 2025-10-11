#include <stdio.h>

struct Book {
  char *titulo;
  char *autor;
  int ano;
};

void print_book(const struct Book *book) {
  printf("Título: %s\n", book->titulo);
  printf("Autor: %s\n", book->autor);
  printf("Ano: %d\n", book->ano);
}

int main() {
  struct Book livro = {"'O Capital, Livro 1'", "Karl Marx", 1867};
  print_book(&livro);

  return 0;
}