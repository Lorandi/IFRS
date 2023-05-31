#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Contato{
    int id;
    char nome[50];
    struct Contato *proximo;
}Contato;

typedef struct Pilha{
    Contato *topo;
}Pilha;

void inicializarPilha(Pilha *p){
    p->topo = NULL;
}

void empilha(int id, char *nome, Pilha *p){
    Contato *ptr = (Contato*) malloc(sizeof(Contato));
    if(ptr == NULL){
        printf("Erro de alocação de contato \n");
        return;
    } else{
        ptr->id = id;
        strcpy(ptr->nome, nome);
        ptr->proximo = p->topo;
        p->topo = ptr;
        printf("Empilhou id %d \n", ptr->id);
    }
}

int desempilha(Pilha *p){
    Contato *ptr = p->topo;
    int id;
    if(ptr == NULL){
        printf("Pilha vazia \n");
        return 0;
    }else{
        p->topo = ptr->proximo;
        ptr->proximo = NULL;
        id = ptr->id;
        free(ptr);
        return id;
    }
}

void imprimePilha(Pilha *p){
    Contato *ptr = p->topo;
    if(ptr == NULL){
        printf("Pilha vazia \n");
        return;
    }else{
        printf("Lista: ");
        while(ptr != NULL){
            printf("%s ", ptr->nome);
            ptr = ptr->proximo;
        }
        printf("\n");
    }
}

int main(){
    Pilha *p1 = (Pilha*) malloc(sizeof(Pilha));
    if(p1 ==  NULL){
        printf("Erro de alocação da pilha. \n");
        exit(0);
    }else{
        inicializarPilha(p1);
        

printf("1- inserir contatos de 1 a 3 \n");
        empilha(1, "João", p1);
        empilha(2, "Maria", p1);
        empilha(3, "Pedro", p1);
        imprimePilha(p1);
        printf("\n");


printf("2- remover um Contato  e imprimir em tela os dados \n");
        printf("Tentando desempilhar -  id: %d \n ", desempilha(p1));
        imprimePilha(p1);
        printf("\n");


printf("3 - remover um Contato  e imprimir em tela os dados \n");
        printf("Tentando desempilhar -  id: %d \n ", desempilha(p1));
        imprimePilha(p1);
        printf("\n");

printf("4 -  empilhar um novo contato \n");
        empilha(4, "Teresa", p1);
        imprimePilha(p1);
        printf("\n");

printf("5 - remover um Contato  e imprimir em tela os dados \n");
        printf("Tentando desempilhar -  id: %d \n ", desempilha(p1));
        imprimePilha(p1);
        printf("\n");

printf("6 - remover um Contato  e imprimir em tela os dados \n");
        printf("Tentando desempilhar -  id: %d \n ", desempilha(p1));
        imprimePilha(p1);
        printf("\n");

printf("7 – tentar remover contato (deve dar erro) \n");
        printf("Tentando desempilhar -  id: %d \n ", desempilha(p1));
        printf("\n");
        
    }
}
// video: https://www.youtube.com/watch?v=Q5UZWmjmYCE
