/*
Atividade 02
Fa�a uma fun��o que receba, por par�metro, um valor
inteiro e positivo e retorne o n�mero de divisores do
valor lido.
a) Implementar usando la�o de repeti��o (while ou for) e
outra usando recursividade.
b) Comparar o tempo gasto na execu��o de cada
implementa��o. 
*/
#include <stdio.h>
#include <time.h>

int num_divisores_laco(int x){ 
	int total_divisores = 0;
	for(int i = 1; i <= x; i++){
		if(x % i == 0){
			total_divisores++;
		}	
	}
	return total_divisores;
}

int num_divisores_recursiva(int x, int i){ 
	if (i == 0) return 0;	
    if (x % i == 0) {
            return 1 + num_divisores_recursiva(x, i - 1);
    } else {
        return num_divisores_recursiva(x, i - 1);
    }    
}

int main() {
    int numero = 100000;
    int i = numero;
    clock_t inicio_laco, fim_laco, inicio_recursiva, fim_recursiva;
    double tempo_laco, tempo_recursivo;

    // Medi��o de tempo para a implementa��o com la�o
    inicio_laco = clock();
    int resultado_laco = num_divisores_laco(numero);
    fim_laco = clock();
    tempo_laco = ((double)(fim_laco - inicio_laco)) / CLOCKS_PER_SEC;

    // Medi��o de tempo para a implementa��o recursiva
    inicio_recursiva = clock();
    int resultado_recursivo = num_divisores_recursiva(numero, i);
    fim_recursiva = clock();
    tempo_recursivo = ((double)(fim_recursiva - inicio_recursiva)) / CLOCKS_PER_SEC;

    // Exibindo resultados e tempos de execu��o
    printf("N�mero de divisores de %d (usando la�o): %d\n", numero, resultado_laco);
    printf("Tempo de execu��o (la�o): %.6f segundos\n", tempo_laco);

    printf("N�mero de divisores de %d (recursiva): %d\n", numero, resultado_recursivo);
    printf("Tempo de execu��o (recursiva): %.6f segundos\n", tempo_recursivo);

    return 0;
}
