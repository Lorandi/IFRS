/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int soma (int n){
        if (n == 0) return 0;
        else return (n + soma (n - 1));
    }
int main()
{
    int n = 2;
    printf("Soma de 1 até %d : %d", n, soma(n));
    return 0;
}
