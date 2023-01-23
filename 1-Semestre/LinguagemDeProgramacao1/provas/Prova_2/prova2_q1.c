// Prova de Linguagem de Programação I
// Curso Sistemas para Internet - 01/12/2022
// Prof. Fabio Okuyama

// Autor: Rodrigo Lorandi
// Questão 1

#include <stdio.h>

// PRINCIPAL é o número total de linhas ou colunas em uma matriz quadrada
#define PRINCIPAL 7
// N_LINHAS número de linhas
#define N_LINHAS PRINCIPAL

// N_COLUNAS número de linhas
#define N_COLUNAS PRINCIPAL

// N_MULTIPLICADOR número base que será multiplicador para construção da tabela
#define N_MULTIPLICADOR 7

int quantidadeImparesDeUmaColuna(int matriz[N_LINHAS][N_COLUNAS], int coluna);

int quantidadeImparesEmTodaAMatriz(int matriz[N_LINHAS][N_COLUNAS]);

int main()
{
    int matriz[N_LINHAS][N_COLUNAS];
    int valor = N_MULTIPLICADOR;
    int maiorElemento = N_MULTIPLICADOR;
    int elementosParesDiagonaPrincipal = 0;
    int produtoCadaLinha[N_LINHAS];
    

    // Construir a matriz
    printf("\na) Preenchimento correto da matriz/exibir corretamente a matriz\n");
    for (int i = 0; i < N_LINHAS; i++)
    {
        for (int j = 0; j < N_COLUNAS; j++)
        {
            matriz[i][j] = valor;
            printf("%d  ", matriz[i][j]);

            // aqui o valor é acrescido do multiplicador para os próximos valores da tabela
            valor += N_MULTIPLICADOR;
        }
        printf("\n");
    }

    // Apresentar o maior elemento da matriz
    for (int i = 0; i < N_LINHAS; i++)
    {
        for (int j = 0; j < N_COLUNAS; j++)
        {
            if (matriz[i][j] > maiorElemento)
            {
                maiorElemento = matriz[i][j];
            }
        }
    }
    printf("\nb) O maior elemento da matriz é o %d. \n", maiorElemento);


    // Apresentar quantidade de elementos pares na diagonal principal
    for (int i = 0; i < N_LINHAS; i++)
    {
        for (int j = 0; j < N_COLUNAS; j++)
        {
            if (i == j && matriz[i][j] % 2 == 0)
            {
                elementosParesDiagonaPrincipal++;
            }
        }
    }
    printf("\nc) A quantidade de elementos pares na diagonal principal é o %d. \n", elementosParesDiagonaPrincipal);

    // PRDUTO dos elementos de cada linha
    for (int j = 0; j < N_LINHAS; j++)
    {
        produtoCadaLinha[j] = 1;
    }
    for (int i = 0; i < N_LINHAS; i++)
    {
        for (int j = 0; j < N_COLUNAS; j++)
        {
            produtoCadaLinha[i] = produtoCadaLinha[i] * matriz[i][j];
        }
    }
    printf("\nd) PRODUTO dos elementos de cada linha:");
    for (int i = 0; i < N_LINHAS; i++)
    {
        printf("\n     Linha %d: %d", i, produtoCadaLinha[i]);
    }
    
    // Quantidade impares em uma coluna
    printf("\n\ne)Quantidade de impares na coluna 0: %d", quantidadeImparesDeUmaColuna(matriz, 0));
    

    // Quantidade impares totais
    printf("\n\nf)Quantidade de impares totais: %d", quantidadeImparesEmTodaAMatriz(matriz));
    
    printf("\n \nProgramador: Rodrigo Lorandi");
    
    return 0;
}

int quantidadeImparesDeUmaColuna(int matriz[N_LINHAS][N_COLUNAS], int coluna)
{
    int impares = 0;

    for (int i = 0; i < N_LINHAS; i++)
    {
        for (int j = 0; j < N_COLUNAS; j++)
        {
            if (j == coluna && matriz[i][j] % 2 == 1)
            {
                impares++;
            }
        }
    }
    return impares;
}

int quantidadeImparesEmTodaAMatriz(int matriz[N_LINHAS][N_COLUNAS])
{
    int totalImpares = 0;

    for (int j = 0; j < N_COLUNAS; j++)
    {
        totalImpares += quantidadeImparesDeUmaColuna(matriz, j);
    }

    return totalImpares;
}
