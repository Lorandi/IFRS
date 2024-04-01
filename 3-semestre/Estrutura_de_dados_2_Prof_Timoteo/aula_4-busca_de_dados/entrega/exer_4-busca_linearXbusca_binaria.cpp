#include <stdio.h>
#include <stdlib.h>

// Função para busca linear
int buscaLinear(int *array, int tamanho, int chave, int *contagem) {
    for (int i = 0; i < tamanho; ++i) {
        (*contagem)++;
        if (array[i] == chave) {
            return i;
        }
        if(array[i]  > chave){
        	return -1; //Retorna -1 se o valor no array for maior que a chave
		}
    }
    return -1; // Retorna -1 se não encontrar a chave
}

// Função para busca binária
int buscaBinaria(int *array, int tamanho, int chave, int *contagem) {
    int esquerda = 0, direita = tamanho - 1;
    while (esquerda <= direita) {
        (*contagem)++;
        int meio = esquerda + (direita - esquerda) / 2;
        if (array[meio] == chave) {
            return meio;
        }
        if (array[meio] < chave) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1; // Retorna -1 se não encontrar a chave
}

int main() {
    FILE *arquivo;
    int *numeros;
    int tamanho = 0, chave;
    int contagem = 0;
    int totalBuscasLinear = 0;
    int totalBuscasBinarias = 0;
    

    // Abre o arquivo
    arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return EXIT_FAILURE;
    }

    // Conta o número de linhas no arquivo
    while (!feof(arquivo)) {
        int temp;
        fscanf(arquivo, "%d\n", &temp);
        tamanho++;
    }

    // Volta ao início do arquivo
    rewind(arquivo);

    // Aloca memória para armazenar os números
    numeros = (int *)malloc(tamanho * sizeof(int));
    if (numeros == NULL) {
        perror("Erro de alocação de memória");
        fclose(arquivo);
        return EXIT_FAILURE;
    }

    // Lê os números do arquivo e os armazena no array
    for (int i = 0; i < tamanho; i++) {
        fscanf(arquivo, "%d\n", &numeros[i]);
    }

    // Fecha o arquivo
    fclose(arquivo);

    // Valores para buscar
    int valores[] = {7341488, 85, 265654, 732765, 8313596, 45744};
    int numValores = sizeof(valores) / sizeof(valores[0]);
    

    // Realiza as buscas e conta os acessos
    for (int i = 0; i < numValores; ++i) {
        int contagem = 0;
        chave = valores[i];
        int posicaoLinear = buscaLinear(numeros, tamanho, chave, &contagem);
        if (posicaoLinear != -1) {
            printf("Busca linear: O numero %d foi encontrado na posicao %d apos %d acessos.\n", chave, posicaoLinear, contagem);
        } else {
            printf("Busca linear: O numero %d nao foi encontrado apos %d acessos.\n", chave, contagem);
        }
        totalBuscasLinear += contagem;

        contagem = 0;
        int posicaoBinaria = buscaBinaria(numeros, tamanho, chave, &contagem);
        if (posicaoBinaria != -1) {
            printf("Busca binaria: O numero %d foi encontrado na posicao %d apos %d acessos.\n", chave, posicaoBinaria, contagem);
        } else {
            printf("Busca binaria: O numero %d nao foi encontrado apos %d acessos.\n", chave, contagem);
        }
         totalBuscasBinarias += contagem;
        
        printf("\n");
    }
    printf("\nConsiderando todos as pesquisas, quantas acessos (no total) cada metodo de busca teve?");
    printf("\nBuscas lineares: %d", totalBuscasLinear);
    printf("\nBuscas binarias: %d", totalBuscasBinarias);
    
    printf("\n\nQual foi o ganho de desempenho do algoritmo mais eficiente em relacao ao algoritmo menos eficiente?\n");
    float ganhoDesempenho = (float)(totalBuscasLinear - totalBuscasBinarias) / totalBuscasLinear * 100;
    printf("Ganho de desempenho da busca binaria em relacao a busca linear: %.2f%%\n", ganhoDesempenho); 

    // Libera memória alocada
    free(numeros);

    return 0;
}

