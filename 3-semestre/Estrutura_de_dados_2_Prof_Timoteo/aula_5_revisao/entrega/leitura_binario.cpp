#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE  1024

int countLines(FILE *file) {
    int count = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            count++;
        }
    }
    rewind(file); // Retorna ao início do arquivo
    return count;
}

main()
{
	FILE *txt;
    char buffer[1024];
    size_t bytes_lidos;
    

    char linha[MAX_SIZE];
    char palavra[MAX_SIZE];
    int  numFrases = 0, c,contadorA = 0, contadorPalavras = 0, maiorPalavra = 0;
    char *maiorPalavraEncontrada = NULL; 
    char **frases;

	if((txt = fopen("arquivo_binario.bin","rb")) == NULL)
    {
        printf("Erro ao abrir arquivo");
    }
    
        // Conta o número de frases no arquivo
    numFrases = countLines(txt);

        
    // Aloca memória para armazenar as frases
    frases = (char **)malloc(numFrases * sizeof(char *));
    if (frases == NULL) {
        printf("Erro ao alocar memória");
        return 1;
    }
    
    
    // Lê as frases do arquivo e as armazena no array de frases
    for (int i = 0; i < numFrases; i++) {
        if (fgets(linha, MAX_SIZE, txt) != NULL) {
            int tamanho = strlen(linha);
            frases[i] = (char *)malloc((tamanho + 1) * sizeof(char));
            if (frases[i] == NULL) {
                printf("Erro ao alocar memória");
                return 1;
            }
            strcpy(frases[i], linha);
        }
    }
    
    // Imprime as frases de trás para frente
    for (int i = 0 ; i < numFrases; i++) {
        printf("%s", frases[i]);
        free(frases[i]); // Libera a memória alocada para a frase
    }    
    
    
    fclose(txt);
      
system("pause"); 
}
