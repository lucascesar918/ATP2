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
    char* name;
    double wage;
    Department department;
} Employee;

char* get_department_name(Department dept) {
    switch (dept) {
        case Administration:    return "Administração";
        case HumanResources:    return "Recursos Humanos";
        case Sales:             return "Vendas";
        case Marketing:         return "Marketing";
        case Development:       return "Desenvolvimento";
        default:                return "Desconhecido";
    }
}

void print_employee(Employee* emp) {
    printf("%s ganha R$%.2f e é do departamento de %s.\n", emp->name, emp->wage, get_department_name(emp->department));
} 

int main() {
    Employee emp = {"Alice", 15000.0, Development};
    Employee emp2 = {"Bárbara", 12000.0, Marketing};
    Employee emp3 = {"Carlos", 8000.0, Sales};
    Employee emp4 = {"Daniel", 5000.0, HumanResources};
    Employee emp5 = {"Eduardo", 3000.0, Administration};

    print_employee(&emp);
    print_employee(&emp2);
    print_employee(&emp3);
    print_employee(&emp4);
    print_employee(&emp5);

    return 0;
}