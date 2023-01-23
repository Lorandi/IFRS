// Algoritmo criado para estudo do conteúdo da disclina Linguagens de Programação 1
// Autor: Rodrigo Lorandi
// Professor: FABIO YOSHIMITSU OKUYAMA
// Porto Alegre, 30/11/2022

#include <stdio.h>

// PRINCIPAL é o número total de linhas ou colunas em uma matriz quadrada
#define PRINCIPAL 7
// N_LINHAS número de linhas
#define N_LINHAS PRINCIPAL

// N_COLUNAS número de linhas
#define N_COLUNAS PRINCIPAL

// N_MULTIPLICADOR número base que será multiplicador para construção da tabela
#define N_MULTIPLICADOR 9

void quantidadeParesCadaColuna(int matriz[N_LINHAS][N_COLUNAS], int colunas);

int quantidadeParesEmUmaColuna(int matriz[N_LINHAS][N_COLUNAS], int coluna);

int quantidadeParesEmTodaAMatriz(int matriz[N_LINHAS][N_COLUNAS]);

float mediaMatriz(int matriz[N_LINHAS][N_COLUNAS], int linhas, int colunas);

int somaDosDivisiveisPor5(int matriz[N_LINHAS][N_COLUNAS], int linhas, int colunas);

int main()
{
    int matriz[N_LINHAS][N_COLUNAS];
    int valor = N_MULTIPLICADOR;
    int marioElemento = N_MULTIPLICADOR;
    int menorElemento = N_MULTIPLICADOR;
    int elementosParesDiagonaPrincipal = 0;
    int somaTotalCadaColuna[N_COLUNAS];
    float mediaDiagonalSecundaria = 0;
    float mediaDiagonalPrincipal = 0;
    int somaDiagonalPrincipal = 0;
    int somaDiagonalSecundaria = 0;

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
            if (matriz[i][j] > marioElemento)
            {
                marioElemento = matriz[i][j];
            }
        }
    }
    printf("\nb) O maior elemento da matriz é o %d. \n", marioElemento);

    // Apresentar o menor elemento da matriz
    for (int i = 0; i < N_LINHAS; i++)
    {
        for (int j = 0; j < N_COLUNAS; j++)
        {
            if (matriz[i][j] < menorElemento)
            {
                menorElemento = matriz[i][j];
            }
        }
    }
    printf("\nc) O menor elemento da matriz é o %d. \n", menorElemento);

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
    printf("\nd) A quantidade de elementos pares na diagonal principal é o %d. \n", elementosParesDiagonaPrincipal);

    // Média de cada coluna
    // Preencher o vetor somaColunas[N_COLUNAS] com valores 0;
    for (int j = 0; j < N_COLUNAS; j++)
    {
        somaTotalCadaColuna[j] = 0;
    }
    for (int i = 0; i < N_LINHAS; i++)
    {
        for (int j = 0; j < N_COLUNAS; j++)
        {
            somaTotalCadaColuna[j] = somaTotalCadaColuna[j] + matriz[i][j];
        }
    }
    printf("\ne) Média dos elementos de cada coluna:");
    for (int j = 0; j < N_COLUNAS; j++)
    {
        printf("\n     Coluna %d: %d", j, somaTotalCadaColuna[j] / PRINCIPAL);
    }

    // Média e somas das diagonais
    for (int i = 0; i < N_LINHAS; i++)
    {
        for (int j = 0; j < N_COLUNAS; j++)
        {
            if ((i + j) == PRINCIPAL - 1)
            {
                somaDiagonalSecundaria += matriz[i][j];
            }

            if (i == j)
            {
                somaDiagonalPrincipal += matriz[i][j];
            }
        }
    }
    mediaDiagonalPrincipal = somaDiagonalPrincipal / PRINCIPAL;
    mediaDiagonalSecundaria = somaDiagonalSecundaria / PRINCIPAL;
    printf("\n\nf) Média e somas das diagonais");
    printf("\n     Soma dos elementos da diagonal principal é %d.", somaDiagonalPrincipal);
    printf("\n     Média dos elementos da diagonal principal é %.2f.", mediaDiagonalPrincipal);
    printf("\n     Soma dos elementos da diagonal secundária é %d.", somaDiagonalSecundaria);
    printf("\n     Média dos elementos da diagonal secundária é %.2f.", mediaDiagonalSecundaria);

    // Quantidade números pares na coluna
    printf("\n\ng)  Quantidade de pares em cada coluna: ");

    quantidadeParesCadaColuna(matriz, N_COLUNAS);

    // Quantidade números pares em uma coluna
    printf("\n\nh)Quantidade de pares na coluna 1: %d", quantidadeParesEmUmaColuna(matriz, 1));

    // Quantidade números pares rotais
    printf("\n\ni)Quantidade de pares totais: %d", quantidadeParesEmTodaAMatriz(matriz));

    // Média da matriz
    printf("\n\nj) Média da matriz: %.2f \n", mediaMatriz(matriz, N_LINHAS, N_COLUNAS));

    printf("\nk) Soma dos divisíveis por 5 é %d \n", somaDosDivisiveisPor5(matriz, N_LINHAS, N_COLUNAS));

    return 0;
}

void quantidadeParesCadaColuna(int matriz[N_LINHAS][N_COLUNAS], int colunas)
{
    int arrayColunas[colunas];

    // popula array com valores 0
    for (int j = 0; j < colunas; j++)
    {
        arrayColunas[j] = 0;
    }

    for (int i = 0; i < colunas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if (matriz[i][j] % 2 == 0)
            {
                arrayColunas[j]++;
            }
        }
    }
    for (int j = 0; j < colunas; j++)
    {
        printf("\n     Coluna %d: tem %d números pares", j, arrayColunas[j]);
    }
}

int quantidadeParesEmUmaColuna(int matriz[N_LINHAS][N_COLUNAS], int coluna)
{
    int pares = 0;

    for (int i = 0; i < N_LINHAS; i++)
    {
        for (int j = 0; j < N_COLUNAS; j++)
        {
            if (j == coluna && matriz[i][j] % 2 == 0)
            {
                pares++;
            }
        }
    }
    return pares;
}

int quantidadeParesEmTodaAMatriz(int matriz[N_LINHAS][N_COLUNAS])
{
    int totalPares = 0;

    for (int j = 0; j < N_COLUNAS; j++)
    {
        totalPares += quantidadeParesEmUmaColuna(matriz, j);
    }

    return totalPares;
}

float mediaMatriz(int matriz[N_LINHAS][N_COLUNAS], int linhas, int colunas)
{
    float somaTodosOsNumeros = 0;

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            somaTodosOsNumeros += matriz[i][j];
        }
    }
    return somaTodosOsNumeros / (linhas * colunas);
}

int somaDosDivisiveisPor5(int matriz[N_LINHAS][N_COLUNAS], int linhas, int colunas)
{
    int somaDosDivisiveisPor5 = 0;

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if (matriz[i][j] % 5 == 0)
            {
                somaDosDivisiveisPor5 += matriz[i][j];
            }
        }
    }
    return somaDosDivisiveisPor5;
}
