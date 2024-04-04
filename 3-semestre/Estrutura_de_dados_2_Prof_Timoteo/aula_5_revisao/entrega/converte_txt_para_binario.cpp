#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *entrada, *saida;
    char linha[1024];
    size_t bytes_lidos;

    // Abre o arquivo de entrada para leitura
    entrada = fopen("arquivo_texto.txt", "r");
    if (entrada == NULL) {
        perror("Erro ao abrir arquivo de entrada");
        return 1;
    }

    // Abre o arquivo de saída para escrita binária
    saida = fopen("arquivo_binario.bin", "wb");
    if (saida == NULL) {
        perror("Erro ao abrir arquivo de saída");
        fclose(entrada);
        return 1;
    }
   
    // Lê e escreve o conteúdo do arquivo de entrada em blocos
    while ((bytes_lidos = fread(linha, sizeof(char), 1024, entrada)) > 0) {
        // Escreve os bytes lidos no arquivo binário
        fwrite(linha, sizeof(char), bytes_lidos, saida);
    }

    // Fecha os arquivos
    fclose(entrada);
    fclose(saida);

    printf("Arquivo binario gerado com sucesso.\n");

    return 0;
}
