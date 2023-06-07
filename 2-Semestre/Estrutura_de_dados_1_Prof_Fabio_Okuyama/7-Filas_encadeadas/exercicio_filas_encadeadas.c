#include <stdio.h>
#include <stdlib.h>

#define TOTAL 0

typedef struct No{
    int dado;
    struct No *prox;
}No;

typedef struct Fila{
    No *inicio;
    No *fim;
    int tamanho;
}Fila;

void inicializarFila(Fila *f){
    f -> inicio = NULL;
    f -> fim = NULL;
    f -> tamanho = 0; 
}

void enfileirar( int dado, Fila *f){
    No *ptr =  (No*) malloc(sizeof(No));
    if(ptr == NULL){
        printf("Erro de alocação \n");
    } else{
        ptr -> dado = dado;
        ptr -> prox =  NULL;
        if(f -> inicio == NULL){
            f ->inicio = ptr;
        }else{
            f -> fim -> prox = ptr;
        }
        f -> fim =  ptr;
        f->tamanho++; 
        
        printf("    Enfileirado número %d \n", dado);
    }
    return;
}

int desenfileirar (Fila *f){
    No *ptr = f ->inicio;
    int dado;
    
    if(ptr != NULL){
        f -> inicio = ptr -> prox;
        ptr -> prox =  NULL;
        dado = ptr -> dado;
        free(ptr);
        if(f ->inicio == NULL){
            f -> fim = NULL;
        }
         f->tamanho--; 
        printf("    Desenfileirando %d \n", dado);
        return dado;
    }else{
        printf("Fila vazia \n");
    }
}

void imprimeFila(Fila *f){
    No *ptr = f -> inicio;
    if(ptr != NULL){
        printf("Lista: ");
        while(ptr != NULL){
            printf("%d ", ptr ->dado);
            ptr = ptr -> prox;
        }
    }else{
        printf("Fila vazia \n");
    }
    printf("\n");
}

int somarValoresDaFila(Fila *f){
    int total = 0;
    No *ptr = f -> inicio;
    if(ptr != NULL){
        while(ptr != NULL){
            total += ptr ->dado;
            ptr = ptr -> prox;
        }
    return total;
    }else{
        printf("Fila vazia \n");
        return 0;
    }
    printf("\n");
}


int main(){
    
    Fila *f1 = (Fila*) malloc (sizeof(Fila));
    if(f1 ==NULL){
        printf("Erro de alocação \n");
        exit(-1);
    }else{
        printf("\n1.CRIAR FILA DE NÚMEROS INTEIROS \n");
        inicializarFila(f1);
        
        printf("\n2. INSERIR 7 NÚMEROS \n");
        for (int i = 1; i <= 7; i++) {
        enfileirar(i, f1);
        }

        printf("\n3. REMOVER 2 NÚMEROS \n");
        for (int i = 0; i < 2; i++) {
            desenfileirar(f1);
        }
        
        printf("\n4. SOMAR E INSERIR O RESULTADO  NA FILA \n");
        enfileirar(somarValoresDaFila(f1),f1);
        imprimeFila(f1);
        
        while(f1->tamanho > 1 ){
            for (int i = 0; i < 2; i++) {
            desenfileirar(f1);
            }
            enfileirar(somarValoresDaFila(f1),f1);
            imprimeFila(f1);
        }
        
        free(f1);
        
        return 0;
    }
}
