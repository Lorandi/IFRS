#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_ELEMENTOS 100000

// Fun��o para realizar a busca bin�ria
int buscaBinaria(int array[], int tamanho, int valor) {
    int iteracoes = 0;
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        iteracoes++;

        if (array[meio] == valor) {
            return iteracoes;
        } else if (array[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1; // Valor n�o encontrado
}

// Fun��o para ordenar um mapa por valor em ordem decrescente
void sortByValue(int keys[], int values[], int tamanho) {
    int i, j, tempKey, tempValue;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = i + 1; j < tamanho; j++) {
            if (values[i] < values[j]) {
                // Troca os valores e as chaves
                tempValue = values[i];
                values[i] = values[j];
                values[j] = tempValue;

                tempKey = keys[i];
                keys[i] = keys[j];
                keys[j] = tempKey;
            }
        }
    }
}

int main() {
    int totalElementos = TOTAL_ELEMENTOS;
    long totalIteracoes = 0;

    // Criando um array com n�meros de 1 at� o total de elementos
    int array[TOTAL_ELEMENTOS];
    for (int i = 0; i < totalElementos; i++) {
        array[i] = i + 1;
    }

    // Criando um mapa para armazenar o valor buscado e o total de itera��es
    int iteracoesPorValor[TOTAL_ELEMENTOS];

    // Criando um mapa para armazenar a contagem de cada total de itera��es
    int contagemIteracoes[TOTAL_ELEMENTOS];
    memset(contagemIteracoes, 0, sizeof(contagemIteracoes));

    // Calculando e armazenando a quantidade de itera��es necess�rias para encontrar cada valor
    for (int i = 1; i <= totalElementos; i++) {
        int iteracoes = buscaBinaria(array, totalElementos, i);
        iteracoesPorValor[i - 1] = iteracoes;
        totalIteracoes += iteracoes;

        // Atualiza a contagem de itera��es
        contagemIteracoes[iteracoes - 1]++;
    }

    // Ordena o mapa de itera��es por valor em ordem decrescente
    sortByValue(array, iteracoesPorValor, totalElementos);

    printf("Valor Buscado | Total de Itera��es\n");

    if (totalElementos > 2000) {
        // Imprime os primeiros 1000 elementos
        for (int i = 0; i < 1000; i++) {
            printf("%d\t\t|\t%d\n", array[i], iteracoesPorValor[i]);
        }

        // Imprime os �ltimos 1000 elementos
        for (int i = totalElementos - 1000; i < totalElementos; i++) {
            printf("%d\t\t|\t%d\n", array[i], iteracoesPorValor[i]);
        }
    } else {
        for (int i = 0; i < totalElementos; i++) {
            printf("%d\t\t|\t%d\n", array[i], iteracoesPorValor[i]);
        }
    }

    // Calcula a m�dia de itera��es
    int mediaIteracoes = (int)(totalIteracoes / totalElementos);
    printf("\nM�dia de itera��es: %d\n", mediaIteracoes);

    // Imprime a contagem de itera��es em ordem crescente
    printf("Contagem de itera��es:\n");
    for (int i = 0; i < TOTAL_ELEMENTOS; i++) {
        if (contagemIteracoes[i] > 0) {
            printf("Total de itera��es %d: %d\n", i + 1, contagemIteracoes[i]);
        }
    }
    // Comando para manter a janela do console aberta no Windows
    system("pause");

    return 0;
}

