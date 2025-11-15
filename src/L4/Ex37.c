#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_EMAIL 50
#define MAX_PHONE 20
#define MAX_LINE 200

typedef struct {
  char name[MAX_NAME];
  char email[MAX_EMAIL];
  char phone[MAX_PHONE];
} Contact;

static void trim_newline(char *s) {
  s[strcspn(s, "\r\n")] = '\0';
}

static int add_contact(const char *filename, const char *name, const char *email, const char *phone) {
  FILE *fd = fopen(filename, "a");
  if (!fd) {
    fprintf(stderr, "Erro ao abrir o arquivo '%s'\n", filename);
    return 1;
  }

  fprintf(fd, "%s|%s|%s\n", name, email, phone);
  fclose(fd);
  printf("Contato '%s' adicionado com sucesso.\n", name);
  return 0;
}

static int search_contact(const char *filename, const char *search_term) {
  FILE *fd = fopen(filename, "r");
  if (!fd) {
    fprintf(stderr, "Erro ao abrir o arquivo '%s'\n", filename);
    return 1;
  }

  char line[MAX_LINE];
  char name[MAX_NAME];
  char email[MAX_EMAIL];
  char phone[MAX_PHONE];
  int found = 0;

  while (fgets(line, sizeof(line), fd)) {
    trim_newline(line);
    if (sscanf(line, "%49[^|]|%49[^|]|%19[^\n]", name, email, phone) == 3) {
      if (strstr(name, search_term) || strstr(email, search_term) || strstr(phone, search_term)) {
        if (!found) {
          printf("\nResultados da busca:\n");
          printf("----------------------------------------\n");
          found = 1;
        }
        printf("Nome: %s\n", name);
        printf("Email: %s\n", email);
        printf("Telefone: %s\n", phone);
        printf("----------------------------------------\n");
      }
    }
  }

  if (!found) {
    printf("Nenhum contato encontrado com o termo '%s'.\n", search_term);
  }

  fclose(fd);
  return 0;
}

static int delete_contact(const char *filename, const char *name) {
  FILE *fd = fopen(filename, "r");
  if (!fd) {
    fprintf(stderr, "Erro ao abrir o arquivo '%s'\n", filename);
    return 1;
  }

  FILE *temp = fopen("temp_contacts.txt", "w");
  if (!temp) {
    fprintf(stderr, "Erro ao criar arquivo temporário\n");
    fclose(fd);
    return 1;
  }

  char line[MAX_LINE];
  char current_name[MAX_NAME];
  char email[MAX_EMAIL];
  char phone[MAX_PHONE];
  int deleted = 0;

  while (fgets(line, sizeof(line), fd)) {
    trim_newline(line);
    if (sscanf(line, "%49[^|]|%49[^|]|%19[^\n]", current_name, email, phone) == 3) {
      if (strcmp(current_name, name) == 0) {
        deleted = 1;
        continue;
      }
    }
    fprintf(temp, "%s\n", line);
  }

  fclose(fd);
  fclose(temp);

  if (deleted) {
    remove(filename);
    rename("temp_contacts.txt", filename);
    printf("Contato '%s' removido com sucesso.\n", name);
  } else {
    remove("temp_contacts.txt");
    printf("Contato '%s' não encontrado.\n", name);
  }

  return 0;
}

static void list_all_contacts(const char *filename) {
  FILE *fd = fopen(filename, "r");
  if (!fd) {
    fprintf(stderr, "Erro ao abrir o arquivo '%s'\n", filename);
    return;
  }

  char line[MAX_LINE];
  char name[MAX_NAME];
  char email[MAX_EMAIL];
  char phone[MAX_PHONE];
  int count = 0;

  printf("\nLista de contatos:\n");
  printf("----------------------------------------\n");

  while (fgets(line, sizeof(line), fd)) {
    trim_newline(line);
    if (sscanf(line, "%49[^|]|%49[^|]|%19[^\n]", name, email, phone) == 3) {
      printf("Nome: %s\n", name);
      printf("Email: %s\n", email);
      printf("Telefone: %s\n", phone);
      printf("----------------------------------------\n");
      count++;
    }
  }

  if (count == 0) {
    printf("Nenhum contato cadastrado.\n");
  } else {
    printf("Total de contatos: %d\n", count);
  }

  fclose(fd);
}

static void introduction() {
  printf("Sistema de Gerenciamento de Contatos\n");
  printf("_____________________________________________\n");
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Argumentos inválidos!\n\nUso: %s <arquivo_contatos>\n", argv[0]);
    return 1;
  }

  char *filename = argv[1];
  char input[512];
  char name[MAX_NAME];
  char email[MAX_EMAIL];
  char phone[MAX_PHONE];
  char search_term[MAX_NAME];

  introduction();

  while (1) {
    printf("\nComandos: (a)dd, (s)earch, (d)elete, (l)ist, (q)uit\n");
    printf(">> ");

    if (!fgets(input, sizeof(input), stdin))
      break;
    trim_newline(input);

    if (!strcmp(input, "quit") || !strcmp(input, "q")) {
      break;
    } else if (!strcmp(input, "add") || !strcmp(input, "a")) {
      printf("Nome: ");
      if (!fgets(name, sizeof(name), stdin))
        continue;
      trim_newline(name);

      printf("Email: ");
      if (!fgets(email, sizeof(email), stdin))
        continue;
      trim_newline(email);

      printf("Telefone: ");
      if (!fgets(phone, sizeof(phone), stdin))
        continue;
      trim_newline(phone);

      add_contact(filename, name, email, phone);

    } else if (!strcmp(input, "search") || !strcmp(input, "s")) {
      printf("Buscar por: ");
      if (!fgets(search_term, sizeof(search_term), stdin))
        continue;
      trim_newline(search_term);

      search_contact(filename, search_term);

    } else if (!strcmp(input, "delete") || !strcmp(input, "d")) {
      printf("Nome do contato a deletar: ");
      if (!fgets(name, sizeof(name), stdin))
        continue;
      trim_newline(name);

      printf("Tem certeza que deseja deletar '%s'? (y/N): ", name);
      if (!fgets(input, sizeof(input), stdin))
        continue;

      if (input[0] == 'y' || input[0] == 'Y') {
        delete_contact(filename, name);
      } else {
        printf("Operação cancelada.\n");
      }

    } else if (!strcmp(input, "list") || !strcmp(input, "l")) {
      list_all_contacts(filename);

    } else {
      printf("Comando desconhecido.\n");
    }
  }

  printf("Saindo...\n");
  return 0;
}
