#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[500];
    char telefone[15];
} contato;

int main(int argc, char *argv[]) {
    contato *teste;

    // Verifica se a alocação de memória foi bem sucedida
    if ((teste = (contato*)malloc(sizeof(contato))) == NULL) {
        printf("Erro: não foi possível alocar memória.\n");
        exit(1);
    }
    
    printf("memória alocada: %lu bytes\n", sizeof(contato));

    fgets(teste->nome, sizeof(teste->nome), stdin);
    teste->nome[strcspn(teste->nome, "\n")] = '\0';
    strcpy(teste->telefone, "1234567");
    printf("Nome = %s\nTelefone = %s\n", teste->nome, teste->telefone);

    free(teste);
    return 0;
}

