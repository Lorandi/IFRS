#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>
#include <time.h>

#define TAMANHO 100000

int *alocarLista(int tamanho);

void imprimirLista(int *lista, int tamanho);

void gerarArquivoEListaRandomica(const char *nomeArquivo, int *lista, int tamanho);
void gerarArquivoEListaOrdenada(const char *nomeArquivo, int *lista, int tamanho);
void gerarArquivoEListaInvertida(const char *nomeArquivo, int *lista, int tamanho);

void copiarLista(int *origem, int *destino, int tamanho);

long long unsigned bubbleSort(int *array, int size, const char *ordem);
long long unsigned insertSort(int *array, int size, const char *ordem);
long long unsigned selectionSort(int *array, int size, const char *ordem);

long long unsigned bubbleSortDecrescente(int *array, int size, const char *ordem);
long long unsigned insertSortDecrescente(int *array, int size, const char *ordem);
long long unsigned selectionSortDecrescente(int *array, int size, const char *ordem);


void criarArquivoLista(const char *nomeArquivo, int *lista, int tamanho);

void pausarExecucao(); 

int main(){
	int i;
	unsigned int ex;
	long long unsigned bubbleSortRandomico = 0LL;
	long long unsigned bubbleSortOrdenado = 0LL;
	long long unsigned bubbleSortInvertido = 0LL;
	
	long long unsigned insertSortRandomico = 0LL;
	long long unsigned insertSortOrdenado = 0LL;
	long long unsigned insertSortInvertido = 0LL;
	
	long long unsigned selectionSortRandomico = 0LL;
	long long unsigned selectionSortOrdenado = 0LL;
	long long unsigned selectionSortInvertido = 0LL;
	
	long long unsigned bubbleSortRandomicoDecrescente = 0LL;
	long long unsigned insertSortRandomicoDecrescente = 0LL;
	long long unsigned selectionSortRandomicoDecrescente = 0LL;	
		
	int *listaRandomica = alocarLista(TAMANHO);
	int *listaOrdenada = alocarLista(TAMANHO);
	int *listaInversa =  alocarLista(TAMANHO);

	gerarArquivoEListaRandomica("ListaRandomica.txt", listaRandomica, TAMANHO);	
	gerarArquivoEListaOrdenada("ListaOrdenada.txt", listaOrdenada, TAMANHO);	
	gerarArquivoEListaInvertida("ListaInvertida.txt", listaInversa, TAMANHO);
	
	
	bubbleSortRandomico = bubbleSort(listaRandomica, TAMANHO, "Lista Randomica");
	bubbleSortOrdenado = bubbleSort(listaOrdenada, TAMANHO, "Lista Ordenada");
	bubbleSortInvertido = bubbleSort(listaInversa, TAMANHO, "Lista Invertida");	

	insertSortRandomico = insertSort(listaRandomica, TAMANHO, "Lista Randomica");
	insertSortOrdenado = insertSort(listaOrdenada, TAMANHO, "Lista Ordenada");
	insertSortInvertido = insertSort(listaInversa, TAMANHO, "Lista Invertida");
	
	
	selectionSortRandomico = selectionSort(listaRandomica, TAMANHO, "Lista Randomica");
	selectionSortOrdenado = selectionSort(listaOrdenada, TAMANHO, "Lista Ordenada");
	selectionSortInvertido = selectionSort(listaInversa, TAMANHO, "Lista Invertida"); 
	
	
	bubbleSortRandomicoDecrescente = bubbleSortDecrescente(listaRandomica, TAMANHO, "Lista Randomica");
	insertSortRandomicoDecrescente = insertSortDecrescente(listaRandomica, TAMANHO, "Lista Randomica");
	selectionSortRandomicoDecrescente= selectionSortDecrescente(listaRandomica, TAMANHO, "Lista Randomica");	

	pausarExecucao();	
	
    free(listaRandomica);
    free(listaOrdenada);
    free(listaInversa);   
    

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

void gerarArquivoEListaRandomica(const char *nomeArquivo, int *lista, int tamanho) {
    unsigned int ex = (unsigned)time(NULL);
    srand(ex);

    FILE *txt;
    if ((txt = fopen(nomeArquivo, "w")) == NULL) {
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    for (int i = 0; i < tamanho; ++i) {
        int c = rand() * rand() % tamanho;
        fprintf(txt, "%d\n", c);
        lista[i] = c; 
    }
    fclose(txt);
}

void gerarArquivoEListaOrdenada(const char *nomeArquivo, int *lista, int tamanho) {
    FILE *txt;
    if ((txt = fopen(nomeArquivo, "w")) == NULL) {
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    // Gerar lista ordenada e escrever no arquivo
    for (int i = 0; i < tamanho; ++i) {
        fprintf(txt, "%d\n", i);
        lista[i] = i; 
    }

    fclose(txt);
}

void gerarArquivoEListaInvertida(const char *nomeArquivo, int *lista, int tamanho) {
    FILE *txt;
    if ((txt = fopen(nomeArquivo, "w")) == NULL) {
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    // Gerar lista invertida e escrever no arquivo
    for (int i = tamanho - 1; i >= 0; --i) {
        fprintf(txt, "%d\n", i);
        lista[tamanho - 1 - i] = i; 
    }

    fclose(txt);
}


void copiarLista(int *origem, int *destino, int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        destino[i] = origem[i];
    }
}

long long unsigned bubbleSort(int *array, int size, const char *ordem) {
	int *lista =  alocarLista(TAMANHO);
	long long unsigned count = 0;	
	
	copiarLista(array, lista, TAMANHO);
	
    int i, j, aux, flag;
    printf("\nBubbletSort com %s iniciado",ordem);
    
    clock_t inicio = clock();

    // Algoritmo de Ordenação
    for (j = 0; j < size; ++j) {
    	if(j % (size/10) == 0){
    		printf(".");
		}
    	
        flag = 0;
        for (i = 0; i < size - 1; ++i) {        	
            if (lista[i] > lista[i + 1]) {
                aux = lista[i];
                lista[i] = lista[i + 1];
                lista[i + 1] = aux;
                flag = 1;
                count++;
            }
        }
        if (flag == 0)
            break;
    }
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf(" %llu iteracoes",count);
    printf("\nTempo decorrido no BubbleSort: %.6f segundos\n\n", tempo);
    
    //criarArquivoLista("BubbleSort.txt",lista, size);
    
    free(lista);
    return count;
}

long long unsigned bubbleSortDecrescente(int *array, int size, const char *ordem) {
	int *lista =  alocarLista(TAMANHO);
	long long unsigned count = 0;	
	
	copiarLista(array, lista, TAMANHO);
	
    int i, j, aux, flag;
    printf("\nBubbletSortDecrescente com %s iniciado",ordem);
    
    clock_t inicio = clock();

    // Algoritmo de Ordenação
    for (j = 0; j < size; ++j) {
    	if(j % (size/10) == 0){
    		printf(".");
		}
    	
        flag = 0;
        for (i = 0; i < size - 1; ++i) {        	
            if (lista[i] < lista[i + 1]) {
                aux = lista[i];
                lista[i] = lista[i + 1];
                lista[i + 1] = aux;
                flag = 1;
                count++;
            }
        }
        if (flag == 0)
            break;
    }
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf(" %llu iteracoes",count);
    printf("\nTempo decorrido no BubbleSortDecrescente: %.6f segundos\n\n", tempo);   
    
    //criarArquivoLista("BubbleSortDecrescente.txt",lista, size);
    
    free(lista);
    return count;
}

long long unsigned insertSort(int *array, int size, const char *ordem) {
	int *lista =  alocarLista(TAMANHO);
	long long unsigned count = 0;	
	
	copiarLista(array, lista, TAMANHO);	

    int i, j, chave, flag;
    
    printf("\nInsertSort com %s iniciado",ordem);
    
    clock_t inicio = clock();

    // Algoritmo de Ordenação
   	for(j=1; j<size; j++){
   		
   		if(j % (size/10) == 0){
    		printf(".");
		}
   		
		chave = lista[j];
		i = j-1;
		while(i >= 0 && lista[i] > chave) {
			lista[i+1] = lista[i];
			i--;
			count++;
		}		
		lista[i+1] = chave;
	}
	
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf(" %llu iteracoes", count);
    printf("\nTempo decorrido no InsertSort: %.6f segundos\n\n", tempo);
    
    //criarArquivoLista("InsertSort.txt",lista, size);
    
    free(lista);
    return count;
}

long long unsigned insertSortDecrescente(int *array, int size, const char *ordem) {
	int *lista =  alocarLista(TAMANHO);
	long long unsigned count = 0;	
	
	copiarLista(array, lista, TAMANHO);	

    int i, j, chave, flag;
    
    printf("\nInsertSortDecrescente com %s iniciado",ordem);
    
    clock_t inicio = clock();

    // Algoritmo de Ordenação
   	for(j=1; j<size; j++){
   		
   		if(j % (size/10) == 0){
    		printf(".");
		}
   		
		chave = lista[j];
		i = j-1;
		while(i >= 0 && lista[i] < chave) {
			lista[i+1] = lista[i];
			i--;
			count++;
		}		
		lista[i+1] = chave;
	}
	
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf(" %llu iteracoes", count);
    printf("\nTempo decorrido no InsertSort: %.6f segundos\n\n", tempo);
    
    //criarArquivoLista("InsertSortDecrescente.txt",lista, size);
    
    free(lista);
    return count;
}

long long unsigned selectionSort(int *array, int size, const char *ordem) {
	int *lista =  alocarLista(TAMANHO);
	long long unsigned count = 0;	
	
	copiarLista(array, lista, TAMANHO);	

    int i, j, min;
    
    printf("\nSelectionSort com %s iniciado",ordem);
    
    clock_t inicio = clock();

    //Algoritmo de Ordenação
  	for (i = 0; i < (size-1); i++) {
  		
  		if(i % (size/10) == 0){
    		printf(".");
		}
		
   		min = i;
	    for (j = (i+1); j < size; j++) {
	    	if(lista[j] < lista[min]) {
	        	min = j;
	      	}
	      	count++;
		}
	    if (i != min) {
	      	int swap = lista[i];
	      	lista[i] = lista[min];
	      	lista[min] = swap;
		}
	}
	
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf(" %llu iteracoes", count);
    printf("\nTempo decorrido no SelectionSort: %.6f segundos\n\n", tempo);
    
    //criarArquivoLista("SelectionSort.txt",lista, size);
    
    free(lista);
    return count;
}

long long unsigned selectionSortDecrescente(int *array, int size, const char *ordem) {
	int *lista =  alocarLista(TAMANHO);
	long long unsigned count = 0;	
	
	copiarLista(array, lista, TAMANHO);	

    int i, j, max;
    
    printf("\nSelectionSortDecrescente com %s iniciado",ordem);
    
    clock_t inicio = clock();

    //Algoritmo de Ordenação
  	for (i = 0; i < (size-1); i++) {
  		
  		if(i % (size/10) == 0){
    		printf(".");
		}
		
   		max = i;
	    for (j = (i+1); j < size; j++) {
	    	if(lista[j] > lista[max]) {
	        	max = j;
	      	}
	      	count++;
		}
	    if (i != max) {
	      	int swap = lista[i];
	      	lista[i] = lista[max];
	      	lista[max] = swap;
		}
	}
	
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf(" %llu iteracoes", count);
    printf("\nTempo decorrido no SelectionSort: %.6f segundos\n\n", tempo);
    
    //criarArquivoLista("SelectionSortDecrescente.txt",lista, size);
    
    free(lista);
    return count;
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
    printf("\nPressione Enter para continuar...");
    while (getchar() != '\n');
}

