
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHELF_CAPACITY 5
#define BUFSIZE 100

typedef struct {
  char *title;
  char *author;
  int year;
} Book;

typedef struct {
  char *nome;
  int quantidade;
  int capacidade;
  Book *livros;
} Shelf;

typedef enum { MENU, ADD, REMOVE, LIST, EXIT } View;

void clear_stdin() {
  while (getchar() != '\n')
    ;
}

void strip_newline(char *str) {
  size_t len = strlen(str);
  if (len > 0 && str[len - 1] == '\n')
    str[len - 1] = '\0';
}

void wait_enter() {
  printf("Aperte [ENTER] para continuar.");
  clear_stdin();
  getchar();
}

int add_book(Shelf *shelf, Book book) {
  if (shelf->quantidade >= shelf->capacidade)
    return 1;
  shelf->livros[shelf->quantidade++] = book;
  return 0;
}

int remove_book(Shelf *shelf) {
  if (shelf->quantidade <= 0)
    return 1;
  free(shelf->livros[shelf->quantidade - 1].title);
  free(shelf->livros[shelf->quantidade - 1].author);
  shelf->quantidade--;
  return 0;
}

void print_books(const Shelf *shelf) {
  if (shelf->quantidade == 0) {
    printf("Nenhum livro na estante.\n");
    return;
  }
  for (int i = 0; i < shelf->quantidade; i++) {
    Book livro = shelf->livros[i];
    printf("Título: %s, Autor: %s, Ano: %d\n", livro.title, livro.author,
           livro.year);
  }
}

void ui_menu(Shelf *shelf) {
  printf("Gerenciando estante '%s'\n", shelf->nome);
  printf("1. Adicionar livro\n");
  printf("2. Remover livro\n");
  printf("3. Listar livros\n");
  printf("4. Sair\n");
}

void ui_add(Shelf *shelf) {
  if (shelf->quantidade >= shelf->capacidade) {
    printf("A estante está cheia. Não é possível adicionar mais livros.\n");
    return;
  }
  char *titulo = malloc(BUFSIZE * sizeof(char));
  char *autor = malloc(BUFSIZE * sizeof(char));
  char abuf[BUFSIZE];
  int ano;
  Book book;

  clear_stdin();
  printf("Digite o título do livro: ");
  fgets(titulo, BUFSIZE, stdin);
  strip_newline(titulo);

  printf("Digite o autor do livro: ");
  fgets(autor, BUFSIZE, stdin);
  strip_newline(autor);

  printf("Digite o ano do livro: ");
  fgets(abuf, BUFSIZE, stdin);
  ano = atoi(abuf);

  book.title = titulo;
  book.author = autor;
  book.year = ano;

  if (add_book(shelf, book) == 0)
    printf("Livro adicionado com sucesso!\n");
  else
    printf("Erro ao adicionar livro.\n");

  wait_enter();
}

void ui_remove(Shelf *shelf) {
  if (shelf->quantidade <= 0) {
    printf("Nenhum livro para remover.\n");
    return;
  }
  Book livro = shelf->livros[shelf->quantidade - 1];
  printf("Removendo livro: Título: %s, Autor: %s, Ano: %d\n", livro.title,
         livro.author, livro.year);
  printf("Tem certeza que deseja remover este livro? (s/N): ");
  clear_stdin();
  char response = getchar();
  if (response != 'S' && response != 's') {
    printf("Remoção cancelada.\n");
    return;
  }
  remove_book(shelf);
  printf("Livro removido com sucesso!\n");
  wait_enter();
}

void ui_list(Shelf *shelf) {
  printf("Listando livros...\n");
  if (shelf->quantidade <= 0) {
    printf("Nenhum livro na estante.\n");
    return;
  }
  print_books(shelf);
}

View get_choice() {
  int choice;
  scanf("%d", &choice);
  return choice;
}

int handle_choice(Shelf *shelf) {
  printf("\nEscolha uma opção: ");
  switch (get_choice()) {
  case MENU:
    ui_menu(shelf);
    break;
  case ADD:
    ui_add(shelf);
    break;
  case REMOVE:
    ui_remove(shelf);
    break;
  case LIST:
    ui_list(shelf);
    break;
  case EXIT:
    printf("Saindo...\n");
    return;
  default:
    printf("Opção inválida. Escolha uma opção informada abaixo.\n");
    break;
  }
  printf("\n");
}

void free_shelf(Shelf *shelf) {
  for (int i = 0; i < shelf->quantidade; i++) {
    free(shelf->livros[i].title);
    free(shelf->livros[i].author);
  }
  free(shelf->livros);
  free(shelf->nome);
  free(shelf);
}

int main() {
  Shelf estante = {"Estante 1", 0, SHELF_CAPACITY,
                   malloc(SHELF_CAPACITY * sizeof(Book))};

  while (1) {
    ui_menu(&estante);
    if (handle_choice(&estante))
      break;
  }

  free_shelf(&estante);
  return 0;
}