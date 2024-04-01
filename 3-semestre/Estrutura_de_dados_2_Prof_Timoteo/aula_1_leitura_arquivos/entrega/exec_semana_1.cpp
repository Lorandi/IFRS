#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE  1024

//conta o n�mero de linhas em um arquivo de texto
int countLines(FILE *file) {
    int count = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            count++;
        }
    }
    rewind(file); // Retorna ao in�cio do arquivo
    return count;
}

// Fun��o para converter uma string para min�sculas
void converterParaMinusculas(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    FILE *arquivo;
    char linha[MAX_SIZE];
    char palavra[MAX_SIZE];
    int  numFrases = 0, c,contadorA = 0, contadorPalavras = 0, maiorPalavra = 0;
    char *maiorPalavraEncontrada = NULL; 
    char **frases;

    // Abre o arquivo para leitura
    arquivo = fopen("arquivo_texto.txt", "r");    
     
	//Retorna caso tenha erro na abertura do arquivo
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo");
        return 1;
    }    
    
    // Conta o n�mero de frases no arquivo
    numFrases = countLines(arquivo);
    
    // Aloca mem�ria para armazenar as frases
    frases = (char **)malloc(numFrases * sizeof(char *));
    if (frases == NULL) {
        printf("Erro ao alocar mem�ria");
        return 1;
    }
    
    
    // L� as frases do arquivo e as armazena no array de frases
    for (int i = 0; i < numFrases; i++) {
        if (fgets(linha, MAX_SIZE, arquivo) != NULL) {
            int tamanho = strlen(linha);
            frases[i] = (char *)malloc((tamanho + 1) * sizeof(char));
            if (frases[i] == NULL) {
                printf("Erro ao alocar mem�ria");
                return 1;
            }
            strcpy(frases[i], linha);
        }
    }
    
    // Imprime as frases de tr�s para frente
    for (int i = numFrases - 1; i >= 0; i--) {
        printf("%s", frases[i]);
        free(frases[i]); // Libera a mem�ria alocada para a frase
    }  
    
	// Retorna ao in�cio do arquivo
	rewind(arquivo) ;	
	
	
   // Conta os caracteres A (mai�sculo ou min�sculo)
	while ((c = fgetc(arquivo)) != EOF) {
        // Verifica se o caractere � 'A' (mai�sculo ou min�sculo)
        if (c == 'A' || c == 'a') {
            contadorA++;
        }
    }    
    printf("\n \n Total de 'a' e 'A': %d \n", contadorA); 
	// Retorna ao in�cio do arquivo
	rewind(arquivo) ;
	
	//// Verifica a quantidade de vezes que as palavras "Direito", "Dever" ou "Deveres" aparecem no texto
	const char *palavrasBusca[] = {"Direito", "Dever", "Deveres"};
	int tamanhoPalavrasBusca = sizeof(palavrasBusca) / sizeof(palavrasBusca[0]);


    while (fscanf(arquivo, "%s", palavra) != EOF) {
        // Converte a palavra para min�sculas para facilitar a compara��o  
		converterParaMinusculas(palavra);  

        // Verifica se a palavra � uma das palavras de busca
        for (int j = 0; j <tamanhoPalavrasBusca; j++) {
        	
        	char palavraBuscaMinuscula[MAX_SIZE];        	
        	strcpy (palavraBuscaMinuscula, palavrasBusca[j]);  
			
			converterParaMinusculas(palavraBuscaMinuscula);	
			        	
            if (strcmp(palavra, palavraBuscaMinuscula) == 0) {
                contadorPalavras++;
            }
        }
        // Verifica se a palavra � a maior at� agora
        int tamanhoPalavra = strlen(palavra);
        if (tamanhoPalavra > maiorPalavra) {
            maiorPalavra = tamanhoPalavra;
            // Libera a mem�ria alocada anteriormente
            free(maiorPalavraEncontrada);
            // Aloca mem�ria para armazenar a nova maior palavra
            maiorPalavraEncontrada = (char*)malloc((tamanhoPalavra + 1) * sizeof(char));
            // Copia a palavra para a �rea de mem�ria alocada
            strcpy(maiorPalavraEncontrada, palavra);
        }
    }
    printf("Total de vezes que 'Direito', 'Dever' ou 'Deveres' aparecem: %d\n", contadorPalavras);
    printf("Tamanho da maior palavra encontrada: %d\n", maiorPalavra);
    printf("Maior palavra encontrada: %s\n", maiorPalavraEncontrada);
     
    fclose(arquivo);

    return 0;
}
