#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100

typedef enum {
  Administration,
  HumanResources,
  Sales,
  Marketing,
  Development
} Department;

typedef struct {
  char *name;
  double wage;
  Department department;
} Employee;

char *get_department_name(Department dept) {
  switch (dept) {
  case Administration:
    return "Administração";
  case HumanResources:
    return "Recursos Humanos";
  case Sales:
    return "Vendas";
  case Marketing:
    return "Marketing";
  case Development:
    return "Desenvolvimento";
  default:
    return "Desconhecido";
  }
}

void print_employee(Employee emp) {
  printf("%s ganha R$%.2f e é do departamento de %s.\n", emp.name, emp.wage,
         get_department_name(emp.department));
}

int main() {
  Employee emp = {"Alice", 15000.0, Development};

  printf("Tamanho da instância da struct de funcionário: %lu bytes.\n",
         sizeof(emp));

  return 0;
}