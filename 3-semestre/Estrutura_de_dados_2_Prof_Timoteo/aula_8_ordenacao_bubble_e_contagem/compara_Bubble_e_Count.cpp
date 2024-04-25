#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>
#include <time.h>

#define TAMANHO 100000

int *alocarLista(int tamanho);

void imprimirLista(int *lista, int tamanho);

void gerarArquivoELista(const char *nomeArquivo, int *lista, int tamanho);

void copiarLista(int *origem, int *destino, int tamanho);

void bubbleSort(int *array, int size);

void counting_sort(int *array, int size);

void criarArquivoLista(const char *nomeArquivo, int *lista, int tamanho);

void pausarExecucao(); 

main(){
	int i;
	unsigned int ex;
		
	int *lista = alocarLista(TAMANHO);
	int *listaBubbleSort = alocarLista(TAMANHO);
	int *listaCountSort = alocarLista(TAMANHO);

	gerarArquivoELista("Arquivo.txt", lista, TAMANHO);	
	
	copiarLista(lista, listaBubbleSort, TAMANHO);	
	
	copiarLista(lista, listaCountSort, TAMANHO);
	
	bubbleSort(listaBubbleSort, TAMANHO);
	//imprimirLista(listaBubbleSort, TAMANHO);
	criarArquivoLista("ListaBubbleSort.txt", listaBubbleSort, TAMANHO);
	//pausarExecucao(); 

	counting_sort(listaCountSort, TAMANHO);	
	criarArquivoLista("listaCountSort.txt", listaBubbleSort, TAMANHO);
	//imprimirLista(listaCountSort, TAMANHO);
	pausarExecucao();	
	
    free(lista);
    free(listaBubbleSort);
    free(listaCountSort);
    return 0;
	
}

int *alocarLista(int tamanho) {
    int *lista = (int *)malloc(tamanho * sizeof(int));
    if (lista == NULL) {
        printf("Erro ao alocar memória para a lista");
        exit(1);
    }
    return lista;
}

void imprimirLista(int *lista, int tamanho) {
    printf("Lista de números armazenados na memória:\n");
    for (int i = 0; i < tamanho; ++i) {
        printf("%d\n", lista[i]);
    }
}

void gerarArquivoELista(const char *nomeArquivo, int *lista, int tamanho) {
    unsigned int ex = (unsigned)time(NULL);
    srand(ex);

    FILE *txt;
    if ((txt = fopen(nomeArquivo, "w")) == NULL) {
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    for (int i = 0; i < tamanho; ++i) {
        int c = rand() % tamanho;
        fprintf(txt, "%d\n", c);
        lista[i] = c; // Salvar na lista
    }
    fclose(txt);
}

void copiarLista(int *origem, int *destino, int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        destino[i] = origem[i];
    }
}

void bubbleSort(int *array, int size) {
	printf("Bubble sort iniciado: ");
    int i, j, aux, flag;
    
    clock_t inicio = clock();

    // Algoritmo de Ordenação
    for (j = 0; j < size; ++j) {
    	if(j % (size/10) == 0){
    		printf(".");
		}
    	
        flag = 0;
        for (i = 0; i < size - 1; ++i) {        	
            if (array[i] > array[i + 1]) {
                aux = array[i];
                array[i] = array[i + 1];
                array[i + 1] = aux;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\nTempo decorrido no bubble sort: %.6f segundos\n\n", tempo);
}

void counting_sort(int *array, int size){
	printf("Count sort iniciado: ");
	int i, min, max;
 	int j=0; 
 	min = max = array[0];
 	clock_t inicio = clock();
 	
	 //Identifica o Maior Elemento
	for(i = 1; i < size;  i++) {
	  	if (array[i] < min)
	     	min = array[i];
	  	else if (array[i] > max)
	     	max = array[i];  
	}
		
	int range = max - min + 1;
	int *count = (int *) malloc(range * sizeof(int));
	  
	//Marca Todas as posições com Zero
	for(i = 0; i < range; i++)
	    count[i] = 0;
	    
	//Marca as posições ocupadas
	  	for(i = 0; i < size; i++)
	        count[array[i] - min]++;
	 
	int indice;
	indice=0; 
	
	//Array recebe as posicoes ocupadas
	for(i = min; i <= max; i++){	
	    for(j = 0; j < count[ i - min ]; j++){
	        	array[indice] = i;
	            indice++;
		}
	}
	clock_t fim = clock();
	double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\nTempo decorrido no count sort: %.6f segundos\n\n", tempo);
			
	free(count);
}

void criarArquivoLista(const char *nomeArquivo, int *lista, int tamanho) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo");
        return;
    }

    for (int i = 0; i < tamanho; ++i) {
        fprintf(arquivo, "%d\n", lista[i]);
    }

    fclose(arquivo);
}

void pausarExecucao() {
    printf("Pressione Enter para continuar...");
    while (getchar() != '\n');
}

