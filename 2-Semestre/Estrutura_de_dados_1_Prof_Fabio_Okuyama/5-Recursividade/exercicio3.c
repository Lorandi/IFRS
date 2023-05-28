/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define TAM 8
void imprimeVetor(int vet[]){
    int i;
    printf("vetor: ");
    for(i=0; i<TAM; i++) printf("%d ",vet[i]);
}
void deslocarD(int vet[],int indice, int elementos){
    printf("Chamada: deslocarD(vet, %d, %d)\n",indice,elementos);
    if(elementos==0) return; //fazer nada
    if(elementos+indice>TAM -1) return; //fazer nada, ultrapassou limite
        else{
            if(elementos==1){
                vet[indice+1]=vet[indice];
            }
            imprimeVetor(vet);
            deslocarD(vet,indice+1, elementos -1);
            deslocarD(vet,indice,elementos-1);
        }
}
int main(){
   int vetor[]={1,2,3,4,5,6,7,8};
    imprimeVetor(vetor);
    deslocarD(vetor,3,3);
}

//A função deslocarD desloca elementos de um vetor para a direita a partir de um 
//índice específico. A função é chamada a partir do programa principal, que 
//também chama uma função para imprimir o vetor original. Durante a execução da 
//função de deslocamento, o vetor atualizado é impresso a cada etapa do processo,
//e o deslocamento é realizado de forma recursiva. O resultado final é o vetor 
//original com os elementos deslocados para a direita.

