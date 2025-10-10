#include <stdio.h>

int main() {
    union un {
        int ival;
        float fval;
    } u;

    u.ival = 42;
    printf("Inteiro armazenado na union: %d\n", u.ival);
    u.fval = 3.14;
    printf("Float armazenado na union: %.2f\n", u.fval);
    printf("Inteiro \"armazenado\" na union (depois de armazenar o float): %d\n", u.ival);

    return 0;
}