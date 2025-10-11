#include <stdio.h>

typedef struct {
    char* name;
    char* phone;
    char* email;
} Customer;

void print_customer(Customer* customer) {
    printf("%s, telefone é %s, email é %s.\n", customer->name, customer->phone, customer->email);
}

int main() {
    Customer cliente = {"Søren Kierkegaard", "13988020304", "desesperohumano@gmail.com"};
    Customer cliente2 = {"Mikhail Bakunin", "13988050607", "deuseestado@gmail.com"};
    Customer cliente3 = {"Pierre Bordieu", "13988080900", "dominacaomasculina@gmail.com"};

    print_customer(&cliente);
    print_customer(&cliente2);
    print_customer(&cliente3);

    return 0;
}