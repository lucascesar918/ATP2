#include <stdio.h>

typedef struct {
    char* phone;
    char* name;
    char* nickname;
} Contact;

void print_contact(Contact* contact) {
    printf("[%s] - %s (%s)\n", contact->phone, contact->name, contact->nickname);
}

int main() {
    Contact contato_felipe = {"12345678901", "Felipe Olavo", "Bonitin"};
    Contact contato_secundario = contato_felipe;

    print_contact(&contato_secundario);

    return 0;
}