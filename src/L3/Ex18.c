#include <stdio.h>

typedef struct {
    struct {
        int number;
        char* street;
        char* city;
        char* state;
        char* country;
    } location;

    struct {
        char* complement;
        char* zip_code;
    } additional;
} Address;

void print_address(Address* addr) {
    printf("%s, %s, %s, %s - %d.\n", addr->location.country, addr->location.state, addr->location.city, addr->location.street, addr->location.number);
    printf("Complemento: %s, CEP: %s.\n", addr->additional.complement, addr->additional.zip_code);
}

int main() {
    Address addr = {
        .location = {157, "Praça Tavares Corrêa", "Garanhuns", "Pernambuco", "Brasil"},
        .additional = {"Relógio das Flores", "55296-300"}
    };

    print_address(&addr);

    return 0;
}