// Algoritmo criado para simulado 2 da disciplina Linguagens de ProgramaC'C#o 1
// Autor: Rodrigo Lorandi
// Professor: FABIO YOSHIMITSU OKUYAMA
// Porto Alegre, 17/11/2022

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N_VALORES 7
#define RANDOMICO 100

void preencheLista (int valores[N_VALORES]);

int maiorImpar(int valores[N_VALORES]);

int menorPar(int valores[N_VALORES]);

int mediaValores(int valores[N_VALORES]);

int main (){
    srand(time(NULL));
    int valores[N_VALORES];
    
    preencheLista(valores);
    
    printf("\n b) Maior impar: %d\n", maiorImpar(valores));
    
    printf("\n c) Menor par: %d\n", menorPar(valores));
    
    printf("\n d) A média inteira dos valores é %d", mediaValores(valores));
    
    printf ("\nProgramador: Rodrigo Lorandi\n");
    

  return 0;
}

void preencheLista (int valores[N_VALORES]){
    int temPar = 0, temImpar = 0;
    printf("\n a) Lista: ");
    while(temPar == 0 || temImpar == 0){
        temPar = 0;
        temImpar = 0;
        for(int i = 0; i < N_VALORES; i++){
            valores[i] = rand() % RANDOMICO ;
            if(valores[i] % 2 == 0){
                temPar++;
            }else{
                temImpar++;
            }
        }
    }
    for(int i = 0; i < N_VALORES; i++){
        printf("%d ", valores[i]);
    }
    printf("\n");
}

int maiorImpar(int valores[N_VALORES]){
    int maiorImpar = valores[0];
    for(int i = 0; i < N_VALORES; i++){
        if(valores[i] % 2 != 0){
            maiorImpar = valores[i];
        }
    }
    
    for(int i = 0; i < N_VALORES; i++){
        if(valores[i] % 2 != 0 && valores[i] > maiorImpar){
            maiorImpar = valores[i];
        }
    }
    return maiorImpar;
}

int menorPar(int valores[N_VALORES]){
    int menorPar = valores[0];
    for(int i = 0; i < N_VALORES; i++){
        if(valores[i] % 2 == 0){
            menorPar = valores[i];
        }
    }
    
    for(int i = 0; i < N_VALORES; i++){
        if(valores[i] % 2 == 0 && valores[i] < menorPar){
            menorPar = valores[i];
        }
    }
    return menorPar;
}

int mediaValores(int valores[N_VALORES]){
    int somaTodos = 0;
    for(int i = 0; i < N_VALORES; i++){
        somaTodos += valores[i];
    }
    return somaTodos / N_VALORES;
}





 
 








