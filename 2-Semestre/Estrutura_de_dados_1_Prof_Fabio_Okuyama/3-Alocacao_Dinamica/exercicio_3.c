#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 100

typedef struct {
    char nome[50];
    char telefone[15];
    char celular[15];
    char endereco[100];
    char aniversario[10];
} Contato;

// Função para criar um novo contato
Contato *criar_contato() {
    Contato *contato = (Contato *) malloc(sizeof(Contato));
    if (contato == NULL) {
        printf("Erro ao alocar memória para o contato.\n");
        exit(1);
    }
    printf("Digite o nome: ");
    fgets(contato->nome, 50, stdin);
    printf("Digite o telefone: ");
    fgets(contato->telefone, 15, stdin);
    printf("Digite o celular: ");
    fgets(contato->celular, 15, stdin);
    printf("Digite o endereço: ");
    fgets(contato->endereco, 100, stdin);
    printf("Digite o aniversário (dd/mm/aaaa): ");
    fgets(contato->aniversario, 10, stdin);
    return contato;
}

// Função para exibir os dados de um contato
void exibir_contato(Contato *contato) {
    printf("Nome: %sTelefone: %sCelular: %sEndereço: %sAniversário: %s", 
    contato->nome, contato->telefone, contato->celular, contato->endereco, contato->aniversario);
}

// Função para inserir um novo contato na agenda
void inserir_contato(Contato **agenda, int *num_contatos) {
    if (*num_contatos == MAX_CONTATOS) {
        printf("Não é possível adicionar mais contatos. A agenda está cheia.\n");
        return;
    }
    Contato *novo_contato = criar_contato();
    agenda[*num_contatos] = novo_contato;
    (*num_contatos)++;
}

// Função para visualizar os dados de um contato na agenda
void visualizar_contato(Contato **agenda, int num_contatos) {
    int posicao;
    printf("Digite a posição do contato (1 a %d): ", num_contatos);
    scanf("%d", &posicao);
    getchar();  // Para limpar o caractere '\n' deixado pelo scanf
    if (posicao < 1 || posicao > num_contatos) {
        printf("Posição inválida.\n");
        return;
    }
    Contato *contato = agenda[posicao - 1];
    exibir_contato(contato);
}

int main() {
    Contato *agenda[MAX_CONTATOS] = {NULL};
    int num_contatos = 0;
    int opcao;

    do {
        printf("\nEscolha uma opção:\n");
        printf("1 - Inserir contato\n");
        printf("2 - Visualizar contato\n");
        printf("3 - Sair\n");
        printf("> ");
        scanf("%d", &opcao);
        getchar();  // Para limpar o caractere '\n' deixado pelo scanf
        switch (opcao) {
            case 1:
                inserir_contato(agenda, &num_contatos);
                break;
            case 2:
                visualizar_contato(agenda, num_contatos);
                break;
            case 3:
                printf("Saindo da agenda...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 3);

    for (int i = 0; i < 100; i++) {
        if (agenda[i] != NULL) {
            free(agenda[i]);
        }
    }

    return 0;
}