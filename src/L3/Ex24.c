#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPLOYEE_CAPACITY 5
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

typedef struct
{
    char *name;
    int registered;
    int capacity;
    Employee *employees;
} EmployeeList;

typedef enum
{
    MENU,
    ADD,
    REMOVE,
    LIST,
    EXIT
} View;

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

void clear_stdin() {
    while(getchar() != '\n');
}

void strip_newline(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

void wait_enter(){
    printf("Aperte [ENTER] para continuar.");
    clear_stdin();
    getchar();
}

int add_employee(EmployeeList* el, Employee e)
{
    if (el->registered >= el->capacity)
        return 1;

    el->employees[el->registered++] = e;
    return 0;
}

int remove_employee(EmployeeList* el)
{
    if (el->registered <= 0)
        return 1;

    free(el->employees[el->registered - 1].name);

    el->registered--;
    return 0;
}

void print_employees(const EmployeeList* el)
{
    if (el->registered == 0)
    {
        printf("Nenhum aluno matriculado.\n");
        return;
    }

    for (int i = 0; i < el->registered; i++)
    {
        Employee e = el->employees[i];
        printf("%s, Departamento de %s, Salário: %.2f\n", e.name, get_department_name(e.department), e.wage);
    }
}

void print_departments() {
    for (int i = 0; i<=Development; i++)
        printf("%d. %s\n", i+1, get_department_name((Department)i));
}

void ui_menu()
{
    printf("1. Adicionar funcionário\n");
    printf("2. Remover funcionário\n");
    printf("3. Listar funcionário\n");
    printf("4. Sair\n");
}

void ui_add(EmployeeList* el)
{
    if (el->registered >= el->capacity) {
        printf("A equipe está cheia. Não é possível adicionar mais funcionários.\n");
        return;
    }

    char *name = malloc(BUFSIZE * sizeof(char));
    char *dep_in = malloc(BUFSIZE * sizeof(char));
    double wage;
    Employee e;

    clear_stdin();
    printf("Digite o nome do funcionário: ");
    fgets(name, BUFSIZE, stdin);
    strip_newline(name);

    printf("Escolha o departamento do funcionário:\n");
    print_departments();
    int dept_choice;
    scanf("%d", &dept_choice);
    if (dept_choice < 1 || dept_choice > Development + 1) {
        printf("Departamento inválido. Operação cancelada.\n");
        free(name);
        free(dep_in);
        return;
    }

    printf("Digite o salário do funcionário: ");
    scanf("%lf", &wage);

    e.name = name;
    e.department = dept_choice - 1;
    e.wage = wage;

    if (add_employee(el, e) == 0)
        printf("Funcionário adicionado com sucesso!\n");
    else
        printf("Erro ao adicionar funcionário.\n");

    free(dep_in);
    wait_enter();
}

void ui_remove(EmployeeList* el)
{
    if (el->registered <= 0) {
        printf("Nenhum funcionário para remover.\n");
        return;
    }

    Employee e = el->employees[el->registered - 1];
    printf("Removendo funcionário: %s, Departamento: %s, Salário: %.2f\n", e.name, get_department_name(e.department), e.wage);
    printf("Tem certeza que deseja remover este aluno? (s/N): ");
    clear_stdin();
    char response = getchar();
    if (response != 'S' && response != 's') {
        printf("Remoção cancelada.\n");
        wait_enter();
        return;
    }
    remove_employee(el);
    printf("Funcionário removido com sucesso!\n");

    wait_enter();
}

void ui_list(EmployeeList* el)
{
    printf("Listando funcionários...\n");
    if (el->registered <= 0) {
        printf("Nenhum funcionário registrado.\n");
        return;
    }

    print_employees(el);
}

View get_choice()
{
    int choice;
    scanf("%d", &choice);
    return choice;
}

int handle_choice(EmployeeList* el)
{
    printf("\nEscolha uma opção: ");
    switch (get_choice())
    {
    case MENU:
        ui_menu(el);
        break;
    case ADD:
        ui_add(el);
        break;
    case REMOVE:
        ui_remove(el);
        break;
    case LIST:
        ui_list(el);
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

void free_classroom(EmployeeList* el) {
    for (int i=0; i<el->registered; i++)
        free(el->employees[i].name);

    free(el->employees);
    free(el);
}

int main()
{
    EmployeeList equipe = {"Sala 1", 0, EMPLOYEE_CAPACITY, malloc(EMPLOYEE_CAPACITY * sizeof(Employee))};
    Employee e;

    while (1)
    {
        ui_menu(&equipe);
        if (handle_choice(&equipe))
            break;
    }

    free_classroom(&equipe);
    return 0;
}