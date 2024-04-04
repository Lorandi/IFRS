#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINHA 100

int main() {
    FILE *arquivo_ascii, *arquivo_binario;
    char linha[MAX_LINHA];
    clock_t inicio, fim;
    double tempo_ascii, tempo_binario;

    // Abre o arquivo ASCII para leitura
    arquivo_ascii = fopen("arquivo_texto.txt", "r");
    if (arquivo_ascii == NULL) {
        perror("Erro ao abrir arquivo ASCII");
        return 1;
    }

    // Inicia a contagem de tempo para leitura do arquivo ASCII
    inicio = clock();

    // Lê o arquivo ASCII
    while (fgets(linha, sizeof(linha), arquivo_ascii) != NULL);

    // Finaliza a contagem de tempo para leitura do arquivo ASCII
    fim = clock();
    tempo_ascii = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // Fecha o arquivo ASCII
    fclose(arquivo_ascii);

    // Abre o arquivo binário para leitura
    arquivo_binario = fopen("arquivo_binario.bin", "rb");
    if (arquivo_binario == NULL) {
        perror("Erro ao abrir arquivo binário");
        return 1;
    }

    // Inicia a contagem de tempo para leitura do arquivo binário
    inicio = clock();

    // Lê o arquivo binário
    while (fread(linha, sizeof(char), sizeof(linha), arquivo_binario));

    // Finaliza a contagem de tempo para leitura do arquivo binário
    fim = clock();
    tempo_binario = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // Fecha o arquivo binário
    fclose(arquivo_binario);

    // Exibe os tempos de leitura
    printf("Tempo de leitura do arquivo ASCII: %.6f segundos\n", tempo_ascii);
    printf("Tempo de leitura do arquivo binário: %.6f segundos\n", tempo_binario);

    return 1;
}
