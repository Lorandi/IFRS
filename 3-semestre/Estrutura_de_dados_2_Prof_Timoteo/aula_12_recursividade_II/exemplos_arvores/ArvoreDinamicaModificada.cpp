#include <stdio.h>
#include <stdlib.h>
#include "arvore2.h"

int main(void)
{

TArvore *raiz = NULL;
int valores[] = {15, 6, 23, 4, 7, 71, 5, 50, 1, 10,10,10,22, 35, 17, 30, 13, 12, 3, 2, 11, 9};  
int n = sizeof(valores) / sizeof(valores[0]); 
int acessos;
int valor;
    
printf("Valores sendo adicionado sendo %d a raiz: ", valores[0]);
for (int i = 0; i < n; i++) {
    if (raiz == NULL) {
        raiz = Cria(NULL, valores[i], NULL);
    } else {
        raiz = insere_binario(raiz, valores[i]);
    }
}
  
 printf("Caminhamentos na Arvore:\n\n");
 
 printf("\n - Pre-Ordem: \t");
 Caminhamento_Pre_Ordem(raiz);
 
 printf("\n - In-Fixado: \t");
 Caminhamento_In_Fixado(raiz);
 
 printf("\n - Pos-Fixado: \t");
 Caminhamento_Pos_Fixado(raiz);
 
 int valores_para_localizar[] = {22, 50, 71, 100};  
    int m = sizeof(valores_para_localizar) / sizeof(valores_para_localizar[0]);

    for (int i = 0; i < m; i++) {
        valor = valores_para_localizar[i];
        if (localiza(raiz, valor, &acessos)) {
            printf("\nValor %d encontrado com %d acessos.\n", valor, acessos);
        } else {
            printf("\nValor %d nao encontrado apos %d acessos.\n", valor, acessos);
        }
    }
 
 Destroi(raiz); 

return(0);
}

