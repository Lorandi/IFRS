/*
Atividade 02
Faça uma função que receba, por parâmetro, um valor
inteiro e positivo e retorne o número de divisores do
valor lido.
a) Implementar usando laço de repetição (while ou for) e
outra usando recursividade.
b) Comparar o tempo gasto na execução de cada
implementação. 
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NUMERO 100000


int num_divisores_laco(int x){ 
	int total_divisores = 0;
	for(int i = 1; i <= x; i++){
		if(x % i == 0){
			total_divisores++;
		}	
	}
	return total_divisores;
}

int num_divisores_recursiva(int x, int i, int total_divisores){ 
	if (i == 0) return total_divisores;	
    if (x % i == 0) {
    	total_divisores++;
	}
    return num_divisores_recursiva(x, i - 1, total_divisores);
}

int main() {

	
	    // Alocando variáveis no heap
    int *numero_heap = (int *)malloc(sizeof(int));
    int *recursivas_heap = (int *)malloc(sizeof(int));
    
        // Verificação da alocação
    if (numero_heap == NULL || recursivas_heap == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }
    
    *numero_heap = NUMERO;
    *recursivas_heap = NUMERO;

    clock_t inicio_laco, fim_laco, inicio_recursiva, fim_recursiva;
    double tempo_laco, tempo_recursivo;
    
        // Medição de tempo para a implementação recursiva
    inicio_recursiva = clock();         
    int resultado_recursivo = num_divisores_recursiva(*numero_heap, *recursivas_heap, 0);
    fim_recursiva = clock();
    tempo_recursivo = ((double)(fim_recursiva - inicio_recursiva)) / CLOCKS_PER_SEC;
    printf("Numero de divisores de %d (recursiva): %d\n", *numero_heap, resultado_recursivo);
    printf("Tempo de execução (recursiva): %.6f segundos\n", tempo_recursivo);

    // Medição de tempo para a implementação com laço
    inicio_laco = clock();   
    int resultado_laco = num_divisores_laco(*numero_heap);
    fim_laco = clock();
    tempo_laco = ((double)(fim_laco - inicio_laco)) / CLOCKS_PER_SEC;
    printf("Numero de divisores de %d (usando laco): %d\n", *numero_heap, resultado_laco);
    printf("Tempo de execução: %.6f segundos\n", tempo_laco);   
   

    return 0;
}
