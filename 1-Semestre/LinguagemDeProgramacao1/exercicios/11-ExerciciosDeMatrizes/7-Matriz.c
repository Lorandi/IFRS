#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    int n = 3, max = 50, min = 10;
    int matriz[n][n], maiorNumero = 0, menorNumero = max;
    int somaLinha = 0, somaTodos = 0, produtoDiagonal = 1; 
    float media;

    srand(time(NULL));
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matriz[i][j] = rand() % max + min;
            if(matriz[i][j] > maiorNumero){
                maiorNumero = matriz[i][j];
            }
            
            if(matriz[i][j] < menorNumero){
                menorNumero = matriz[i][j];
            }
            
            somaTodos += matriz[i][j];
            
            if(i == j){
                produtoDiagonal *= matriz[i][j];
            }
            
            if(i == 0){
                somaLinha += matriz[i][j];
            }
            
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    media = 1.00*somaTodos/(n*n);
    
    printf("\nMaior número %d", maiorNumero);
    printf("\nMenor número %d", menorNumero);
    printf("\nMédia dos números %.2f", media);
    printf("\nSoma da linha 1 : %d", somaLinha);
    printf("\nProduto da diagonal : %d", produtoDiagonal);

    return 0;
}

