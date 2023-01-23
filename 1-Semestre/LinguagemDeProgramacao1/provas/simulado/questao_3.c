// Algoritmo criado para simulado 2 da disciplina Linguagens de ProgramaC'C#o 1
// Autor: Rodrigo Lorandi
// Professor: FABIO YOSHIMITSU OKUYAMA
// Porto Alegre, 17/11/2022

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define CANDIDATAS 5
#define INVALIDOS 3
#define RANDOMICO 10

void eleicao(int opcoes[CANDIDATAS + INVALIDOS]);
int maisVotos(int opcoes[CANDIDATAS + INVALIDOS]);

int main (){
    int opcoes[CANDIDATAS + INVALIDOS];
    srand(time(NULL));
    
    eleicao(opcoes);
    
    printf("\n \nA mais votada teve %d votos.",maisVotos(opcoes));
    
    printf ("\nProgramador: Rodrigo Lorandi\n");

  return 0;
}

void eleicao(int opcoes[CANDIDATAS + INVALIDOS]){
     int voto = 0;
        for (int i = 0; i <= CANDIDATAS + INVALIDOS; i++){
         opcoes[i]=0;
    }
    
    printf("\nVotos: ");
    do{
        voto = rand() % RANDOMICO;
        
        printf(" %d", voto);
        
        switch(voto){
            case 0 : break;
            case 1 : opcoes[1]++;  break;
            case 2 : opcoes[2]++;break;
            case 3 : opcoes[3]++;break;
            case 4 : opcoes[4]++;break;
            case 5 : opcoes[5]++;break;
            case 7 : opcoes[7]++;break;
            default: opcoes[8]++;break;
        }
        
    }while(voto != 0);
    
    for (int i = 0; i <= (CANDIDATAS + INVALIDOS); i++){
        if(i > 0 && i <= CANDIDATAS){
          printf("\nCandidata %d : %d votos", i, opcoes[i]); 
        }
        
        if(i == 7){
            printf("\nVotos branco : %d votos", opcoes[i]); 
        }
        
        if(i == 8){
            printf("\nVotos nulos : %d votos", opcoes[i]); 
        }
        
    }
    
}

int maisVotos(int opcoes[CANDIDATAS + INVALIDOS]){
    int maisVotos = opcoes[0];
    for (int i = 1; i <= CANDIDATAS ; i++){
        if(maisVotos <  opcoes[i]){
           maisVotos = opcoes[i];
        }
    }
    
    return maisVotos;
}



