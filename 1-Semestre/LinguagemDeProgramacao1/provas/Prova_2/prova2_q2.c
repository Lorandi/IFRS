// Prova de Linguagem de Programação I
// Curso Sistemas para Internet - 01/12/2022
// Prof. Fabio Okuyama

// Autor: Rodrigo Lorandi
// Questão 2

#include <stdio.h>

#define N_VALORES_INTEIROS 6

// Funções com inteiros
void preencheListaInteiros(int valores[N_VALORES_INTEIROS]);
int maiorInt(int valores[N_VALORES_INTEIROS]);
int quantidadeInteirosPares(int valores[N_VALORES_INTEIROS]);
int somaTodosInteiros(int valores[N_VALORES_INTEIROS]);

int main()
{
    // Array de inteiros
    int arrayValoresInteiros[N_VALORES_INTEIROS];

    // Preencha a Lista  inteiros
    preencheListaInteiros(arrayValoresInteiros);
    
    //Função maior inteiros
    printf("\nb) Maior inteiro: %d\n", maiorInt(arrayValoresInteiros));
    
    //Funcão quantidade de pares inteiros
    printf("\nc) A quantidade de inteiros pares é: %d \n", quantidadeInteirosPares(arrayValoresInteiros));
    
    //Função soma todos inteiros
    printf("\nd) A soma dos inteiros é: %d \n", somaTodosInteiros(arrayValoresInteiros));


    printf("\nProgramador: Rodrigo Lorandi\n");

    return 0;
}

void preencheListaInteiros(int valores[N_VALORES_INTEIROS])
{
    printf("\nPreencha a lista com %d números inteiros:", N_VALORES_INTEIROS);
    int numero = 0;
    for (int i = 0; i < N_VALORES_INTEIROS; i++)
    {
        printf("\nNúmero %d: ", i + 1);
        scanf(" %d", &numero);
        valores[i] = numero;
    }
    printf("\na) Lista inteiros: ");
    for (int i = 0; i < N_VALORES_INTEIROS; i++)
    {
        printf("%d ", valores[i]);
    }
    printf("\n");
}

int maiorInt(int valores[N_VALORES_INTEIROS])
{
    int maiorInt = valores[0];
    for (int i = 0; i < N_VALORES_INTEIROS; i++)
    {
        if (valores[i] > maiorInt)
        {
            maiorInt = valores[i];
        }
    }
    return maiorInt;
}


int quantidadeInteirosPares(int valores[N_VALORES_INTEIROS]){
    int inteirosPares = 0;
    for (int i = 0; i < N_VALORES_INTEIROS; i++)
    {
        if (valores[i] % 2 == 0)
        {
            inteirosPares++;
        }
    }
    return inteirosPares;
}

int somaTodosInteiros(int valores[N_VALORES_INTEIROS]){
    int somaInteiros = 0;
    for (int i = 0; i < N_VALORES_INTEIROS; i++)
    {
        somaInteiros += valores[i];
    }
    return somaInteiros;
}









