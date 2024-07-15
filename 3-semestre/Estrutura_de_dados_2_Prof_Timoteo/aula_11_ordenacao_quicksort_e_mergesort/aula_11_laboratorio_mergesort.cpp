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

#define NUMEROS_A_GERAR 100000

void merge(int vec[], int vecSize) {
	int mid;
	int i, j, k;
	int* tmp;
	tmp = (int*) malloc(vecSize * sizeof(int));
	
	if (tmp == NULL) {
		exit(1);
	}
	
	mid = vecSize / 2;
	i = 0;
	j = mid;
	k = 0;
	
	while (i < mid && j < vecSize) {
		if (vec[i] < vec[j]) {
			tmp[k] = vec[i];
			++i;
		}else {
			tmp[k] = vec[j];
			++j;
		}
		++k;
	}
		if (i == mid) {
	 		while (j < vecSize) {
		 		tmp[k] = vec[j];
		 		++j;
		 		++k;
			}
		}else {
			while (i < mid) {
	 			tmp[k] = vec[i];
	 			++i;
	 			++k;
			}
		}
		
	for (i = 0; i < vecSize; ++i) {
		vec[i] = tmp[i];
	}
	
	free(tmp);
}
 
void mergeSort(int vec[], int vecSize){
	int mid;
	if (vecSize > 1)
	{
		mid = vecSize / 2;
		mergeSort(vec, mid);
		mergeSort(vec + mid, vecSize - mid);
		merge(vec, vecSize);
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
	mergeSort(v,NUMEROS_A_GERAR);
	
	//Laço de impressão do Vetor	
	/*for (int q=0; q<100000; q++)
	{
		printf("%d - ",q);
		printf("%d \n",v[q]);
		if (v[q]<v[q-1]){
		 	return 1;	 	
		}
	 }
	 */
	 

    return 0;
}
