#include <stdio.h>

int main() {
    union {
        double d_val;
        char c_val;
    } u;

    u.d_val = 123.456;
    printf("Valor armazenado na union: %.3f\n", u.d_val);

    u.c_val = 'A';
    printf("Valor armazenado na union: '%c'\n", u.c_val);

    return 0;
}