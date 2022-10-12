#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    int l = 5, c = 4,  max = 9, min = 1;
    int matriz[l][c], maiorEstoqueDoProduto2 = min, armazemComMaiorEstoqueDoProduto2 = 0;
    int  menorEstoqueDoProduto4 = max, armazemComMenorEstoqueDoProduto4 = 0;
    int quantPro1 = 0, quantPro2 = 0, quantPro3 = 0, quantPro4 = 0;
    int somaLinha = 0, totalCustoArmazem = 0;

    srand(time(NULL));
    
    for(int i = 0; i < l; i++){
        somaLinha = 0;
        for(int j = 0; j < c; j++){
            matriz[i][j] = rand() % max + min;
            printf("%d  ", matriz[i][j]);
        }
        printf("\n");
    }
    
    for(int i = 0; i < l-1; i++){
        somaLinha = 0;
        totalCustoArmazem = 0;
        for(int j = 0; j < c; j++){
            
            somaLinha += matriz[i][j];
            totalCustoArmazem += matriz[i][j] * matriz[4][j];
            
            if(j == 0){
                quantPro1 += matriz[i][j];
            }
            
            if(j == 1){
                quantPro2 += matriz[i][j];
                if(matriz[i][j] > maiorEstoqueDoProduto2){
                    maiorEstoqueDoProduto2 = matriz[i][j];
                    armazemComMaiorEstoqueDoProduto2 = i+1;
                }
            }
            
            if(j == 2){
                quantPro3 += matriz[i][j];
            }
            
            if(j == 3){
                quantPro4 += matriz[i][j];
                if(matriz[i][j]< menorEstoqueDoProduto4){
                    menorEstoqueDoProduto4 = matriz[i][j];
                    armazemComMenorEstoqueDoProduto4 = i+1;
                }
            }
            
        }
        
        printf("\nSoma itens armazém %d : %d ", i + 1 , somaLinha);
        printf("\nCusto total do armazém %d é R$ %d,00", i + 1, totalCustoArmazem);
        printf("\n");
        
    }
    
    printf("\nO armazém que possui maior estoque do produto 2 é o %d com %d unidades", 
        armazemComMaiorEstoqueDoProduto2, maiorEstoqueDoProduto2);
        
    printf("\nO armazém que possui menor estoque do produto 4 é o %d com %d unidades", 
        armazemComMenorEstoqueDoProduto4, menorEstoqueDoProduto4);
        
    printf("\n");
    
    printf("\nO produto 1 tem %d unidades e o custo total é R$ %d,00 ", 
        quantPro1, quantPro1*matriz[4][0]); 
        
    printf("\nO produto 2 tem %d unidades e o custo total é R$ %d,00 ", 
        quantPro2, quantPro2*matriz[4][1]); 
        
    printf("\nO produto 3 tem %d unidades e o custo total é R$ %d,00 ", 
        quantPro3, quantPro3*matriz[4][2]); 
    
    printf("\nO produto 4 tem %d unidades e o custo total é R$ %d,00 ", 
        quantPro4, quantPro4*matriz[4][3]);      

    return 0;
}
