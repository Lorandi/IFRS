/*
Atividade 03 
Faça um algoritmo recursivo que dado um valor 
decimal, imprime seu correspondente em binário.  
Implementar usando laço de repetição (while ou  
for) e outra usando recursividade. 
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void decimal_para_binario_laco(int decimal) {
    int binario[32]; // Assumindo que o máximo de bits é 32 (para int)
    int indice = 0;

    if (decimal == 0) {
        printf("Binário: 0\n");
        return;
    }

    while (decimal > 0) {
        binario[indice] = decimal % 2;
        decimal = decimal / 2;
        indice++;
    }

    for (int i = indice - 1; i >= 0; i--) {
        printf("%d", binario[i]);
    }
    printf("\n");
}

void decimal_para_binario_recursivo(int decimal) {
    if (decimal == 0) {
        return;
    }
    decimal_para_binario_recursivo(decimal / 2);
    printf("%d", decimal % 2);
}

int main() {
	
	int decimal = 11;
	
	printf("\nLaco - Binario de %d: ", decimal);
	decimal_para_binario_laco(decimal);
	
	printf("\nRecursica - Binario de %d: ", decimal);
	decimal_para_binario_recursivo(decimal);
	
  	getchar();
    
    //printf("Laco: %s\n", decimal_para_binario_recursivo(x));
   

    return 0;
}
