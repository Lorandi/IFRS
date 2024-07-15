/*
Laboratório
• Execute o Programa “Gera_RAND” para criar um
arquivo com 100.000 número randômicos.
• Altere o Programa do Algoritmo de QuickSort para
que leia o arquivo e gere um arquivo ordenado.
• Altere o Programa do Algoritmo MergeSort para que
leia o arquivo e gere um arquivo ordenado.
• Qual dos dois foi mais rápido?
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMEROS_A_GERAR 20000

void swap(int* a, int* b) {
	 int tmp;
	 tmp = *a;
	 *a = *b;
	 *b = tmp;
 }
int partition(int vec[], int left, int right) {
	int i, j;
	i = left;
	for (j = left + 1; j <= right; ++j) {
		 if (vec[j] < vec[left]) {
		 ++i;
		 swap(&vec[i], &vec[j]);
	}
 }
	 swap(&vec[left], &vec[i]);
	 return i;
}
void quickSort(int vec[], int left, int right) {
	int r;
	if (right > left) {
		r = partition(vec, left, right);
		quickSort(vec, left, r - 1);
		quickSort(vec, r + 1, right); 
	}
}

int main() {
    int v[NUMEROS_A_GERAR];
    int i;

    // Inicializando a semente do gerador randômico com o tempo atual
    srand(time(NULL));

    // Gerando e armazenando os números randômicos no array
    for (i = 0; i < NUMEROS_A_GERAR; i++) {
        v[i] = rand();
    }
    
    int pivot = v[0];
    
    //Algoritmo de Ordenação
	quickSort(v,0,pivot);
	//Laço de impressão do Vetor
	for (int q=0; q<50000; q++)
	{
		printf("%d - ",q);
		printf("%d \n",v[q]);
		if (v[q]<v[q-1]){
		 	return 1;	 	
		}
	 }



    return 0;
}
