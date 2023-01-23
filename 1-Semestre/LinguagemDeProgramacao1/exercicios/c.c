// Algoritmo criado para simulado 2 da disciplina Linguagens de Programação 1
// Autor: Rodrigo Lorandi
// Professor: FABIO YOSHIMITSU OKUYAMA
// Porto Alegre, 30/11/2022

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N_VALORES_INTEIROS 5
#define N_VALORES_FLOATS 5

// Funções com inteiros
void preencheListaInteiros(int valores[N_VALORES_INTEIROS]);

int maiorImpar(int valores[N_VALORES_INTEIROS]);

int menorPar(int valores[N_VALORES_INTEIROS]);

int mediaValores(int valores[N_VALORES_INTEIROS]);

// Funções com float
void preencheListaFloat(float valores[N_VALORES_FLOATS]);

float maiorFloat(float valores[N_VALORES_FLOATS]);

float mediaFloats(float valores[N_VALORES_FLOATS]);

float menorfloat(float valores[N_VALORES_FLOATS]);

int main()
{
    // INTEIROS
    int arrayValoresInteiros[N_VALORES_INTEIROS];

    // Preencha a Lista  inteiros
    preencheListaInteiros(arrayValoresInteiros);

    printf("\n  Maior inteiro impar : %d\n", maiorImpar(arrayValoresInteiros));

    printf("\n  Menor inteiro par: %d\n", menorPar(arrayValoresInteiros));

    printf("\n  A média inteira dos valores é %d ", mediaValores(arrayValoresInteiros));

    // FLOAT
    float arrayValoresFloats[N_VALORES_FLOATS];

    // Preencha a Lista  floats
    preencheListaFloat(arrayValoresFloats);

    printf("\nMaior float: %.2f\n", maiorFloat(arrayValoresFloats));

    printf("\nA média float dos valores é %.2f ", mediaFloats(arrayValoresFloats));

    printf("\n  Menor float : %.2f\n", menorfloat(arrayValoresFloats));

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
    printf("\n Lista inteiros: ");
    for (int i = 0; i < N_VALORES_INTEIROS; i++)
    {
        printf("%d ", valores[i]);
    }
    printf("\n");
}

int maiorImpar(int valores[N_VALORES_INTEIROS])
{
    int maiorImpar = valores[0];
    for (int i = 0; i < N_VALORES_INTEIROS; i++)
    {
        if (valores[i] % 2 != 0)
        {
            maiorImpar = valores[i];
        }
    }

    for (int i = 0; i < N_VALORES_INTEIROS; i++)
    {
        if (valores[i] % 2 != 0 && valores[i] > maiorImpar)
        {
            maiorImpar = valores[i];
        }
    }
    return maiorImpar;
}

int menorPar(int valores[N_VALORES_INTEIROS])
{
    int menorPar = valores[0];
    for (int i = 0; i < N_VALORES_INTEIROS; i++)
    {
        if (valores[i] % 2 == 0)
        {
            menorPar = valores[i];
        }
    }

    for (int i = 0; i < N_VALORES_INTEIROS; i++)
    {
        if (valores[i] % 2 == 0 && valores[i] < menorPar)
        {
            menorPar = valores[i];
        }
    }
    return menorPar;
}

int mediaValores(int valores[N_VALORES_INTEIROS])
{
    int somaTodos = 0;
    for (int i = 0; i < N_VALORES_INTEIROS; i++)
    {
        somaTodos += valores[i];
    }
    return somaTodos / N_VALORES_INTEIROS;
}

void preencheListaFloat(float valores[N_VALORES_FLOATS])
{
    printf("\n\nPreencha a lista com %d números float:", N_VALORES_FLOATS);
    float numero = 0;
    for (int i = 0; i < N_VALORES_FLOATS; i++)
    {
        printf("\nNúmero %d: ", i + 1);
        scanf(" %f", &numero);
        valores[i] = numero;
    }
    printf("\n Lista: ");
    for (int i = 0; i < N_VALORES_FLOATS; i++)
    {
        printf("%.2f ", valores[i]);
    }
    printf("\n");
}

float maiorFloat(float valores[N_VALORES_FLOATS])
{
    float maiorFloat = valores[0];
    for (int i = 0; i < N_VALORES_FLOATS; i++)
    {
        if (valores[i] > maiorFloat)
        {
            maiorFloat = valores[i];
        }
    }

    return maiorFloat;
}

float mediaFloats(float valores[N_VALORES_FLOATS])
{
    float somaTodos = 0;
    for (int i = 0; i < N_VALORES_FLOATS; i++)
    {
        somaTodos += valores[i];
    }
    return somaTodos / N_VALORES_FLOATS;
}

float menorfloat(float valores[N_VALORES_FLOATS])
{
    float menorFloat = valores[0];

    for (int i = 0; i < N_VALORES_INTEIROS; i++)
    {
        if (valores[i] < menorFloat)
        {
            menorFloat = valores[i];
        }
    }
    return menorFloat;
}