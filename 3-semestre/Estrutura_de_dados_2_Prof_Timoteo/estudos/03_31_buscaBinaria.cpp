#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_ELEMENTOS 100000

// Função para realizar a busca binária
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

    return -1; // Valor não encontrado
}

// Função para ordenar um mapa por valor em ordem decrescente
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

    // Criando um array com números de 1 até o total de elementos
    int array[TOTAL_ELEMENTOS];
    for (int i = 0; i < totalElementos; i++) {
        array[i] = i + 1;
    }

    // Criando um mapa para armazenar o valor buscado e o total de iterações
    int iteracoesPorValor[TOTAL_ELEMENTOS];

    // Criando um mapa para armazenar a contagem de cada total de iterações
    int contagemIteracoes[TOTAL_ELEMENTOS];
    memset(contagemIteracoes, 0, sizeof(contagemIteracoes));

    // Calculando e armazenando a quantidade de iterações necessárias para encontrar cada valor
    for (int i = 1; i <= totalElementos; i++) {
        int iteracoes = buscaBinaria(array, totalElementos, i);
        iteracoesPorValor[i - 1] = iteracoes;
        totalIteracoes += iteracoes;

        // Atualiza a contagem de iterações
        contagemIteracoes[iteracoes - 1]++;
    }

    // Ordena o mapa de iterações por valor em ordem decrescente
    sortByValue(array, iteracoesPorValor, totalElementos);

    printf("Valor Buscado | Total de Iterações\n");

    if (totalElementos > 2000) {
        // Imprime os primeiros 1000 elementos
        for (int i = 0; i < 1000; i++) {
            printf("%d\t\t|\t%d\n", array[i], iteracoesPorValor[i]);
        }

        // Imprime os últimos 1000 elementos
        for (int i = totalElementos - 1000; i < totalElementos; i++) {
            printf("%d\t\t|\t%d\n", array[i], iteracoesPorValor[i]);
        }
    } else {
        for (int i = 0; i < totalElementos; i++) {
            printf("%d\t\t|\t%d\n", array[i], iteracoesPorValor[i]);
        }
    }

    // Calcula a média de iterações
    int mediaIteracoes = (int)(totalIteracoes / totalElementos);
    printf("\nMédia de iterações: %d\n", mediaIteracoes);

    // Imprime a contagem de iterações em ordem crescente
    printf("Contagem de iterações:\n");
    for (int i = 0; i < TOTAL_ELEMENTOS; i++) {
        if (contagemIteracoes[i] > 0) {
            printf("Total de iterações %d: %d\n", i + 1, contagemIteracoes[i]);
        }
    }
    // Comando para manter a janela do console aberta no Windows
    system("pause");

    return 0;
}

