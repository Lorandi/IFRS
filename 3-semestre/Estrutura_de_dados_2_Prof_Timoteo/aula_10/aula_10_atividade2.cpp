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

    // Medição de tempo para a implementação com laço
    inicio_laco = clock();
    int resultado_laco = num_divisores_laco(numero);
    fim_laco = clock();
    tempo_laco = ((double)(fim_laco - inicio_laco)) / CLOCKS_PER_SEC;

    // Medição de tempo para a implementação recursiva
    inicio_recursiva = clock();
    int resultado_recursivo = num_divisores_recursiva(numero, i);
    fim_recursiva = clock();
    tempo_recursivo = ((double)(fim_recursiva - inicio_recursiva)) / CLOCKS_PER_SEC;

    // Exibindo resultados e tempos de execução
    printf("Número de divisores de %d (usando laço): %d\n", numero, resultado_laco);
    printf("Tempo de execução (laço): %.6f segundos\n", tempo_laco);

    printf("Número de divisores de %d (recursiva): %d\n", numero, resultado_recursivo);
    printf("Tempo de execução (recursiva): %.6f segundos\n", tempo_recursivo);

    return 0;
}
