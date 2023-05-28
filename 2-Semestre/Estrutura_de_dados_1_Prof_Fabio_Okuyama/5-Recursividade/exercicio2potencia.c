/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int potencia(int base, int expoente) {
    if (expoente == 0) {
        return 1;
    } else {
        return base * potencia(base, expoente - 1);
    }
}

int main() {
    int base, expoente, resultado;
    printf("Digite a base: ");
    scanf("%d", &base);
    printf("Digite o expoente: ");
    scanf("%d", &expoente);

    resultado = potencia(base, expoente);

    printf("%d elevado a %d é igual a %d", base, expoente, resultado);

    return 0;
}