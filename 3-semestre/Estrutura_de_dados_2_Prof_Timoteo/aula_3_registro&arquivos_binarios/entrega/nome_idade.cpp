#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

typedef struct Cpessoa {
    char nome[21]; // Permitindo até 20 caracteres + '\0'
    int idade; 
} Cpessoa;

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int verifica_nome(const char *nome) {	
    size_t len = strlen(nome);
    
    for (int i = 0; i < len; i++) {	  
        if (!isalpha(nome[i]) && nome[i] != ' ' ) {
            printf("Nome tem caracteres não permitidos\n");
            limpar_buffer();
            return 0;
        }
    }    
    return 1;
}


void inserir(FILE *bin) {
    Cpessoa pessoa; 
    int verificaNome = 0;
    int verificaIdade = 0;
    
    while (verificaNome < 1) {
        printf("Informe o nome: ");
        scanf("%20[^\n]", pessoa.nome);                 
        
        if (!verifica_nome(pessoa.nome)) {
            printf("O nome deve conter apenas letras ou espacos e ter no maximo 20 caracteres.\n");  
        } else {
            verificaNome = 1;
            limpar_buffer();
        }   
    }
    
    while (verificaIdade < 1) {
        printf("Informe a idade: ");
        if (scanf("%d", &pessoa.idade) != 1 || pessoa.idade < 0) {
            printf("Entrada invalida para idade.\n");
            limpar_buffer();
        } else {
            verificaIdade = 1;
            limpar_buffer();
        }
    }    
    
    fwrite(&pessoa, sizeof(Cpessoa), 1, bin); 
}

void visualizar(FILE *bin) {
    Cpessoa pessoa;

    rewind(bin);

    printf("\n");
    while (fread(&pessoa, sizeof(Cpessoa), 1, bin) == 1) {
        printf("Nome: %s\n", pessoa.nome);
        printf("Idade: %d\n", pessoa.idade);
        printf("\n");
    }
}

int main() {
    FILE *bin = fopen("arquivos_binarios_nome_idade.bin", "ab+");
    if (bin == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    
    char opcao;

    while (1) {
    	printf("\n\n  ---   MENU   ---\n");
        printf(" [1] - Inserir\n");
        printf(" [2] - Listar\n");
        printf(" [3] - Sair\n");
        
        while (1) {
            printf("Digite a opcao: ");
            scanf(" %c", &opcao);
            limpar_buffer();
            
            if (opcao == '1' || opcao == '2' || opcao == '3') {
                break; 
            } else {
                printf("Opcao invalida! Digite novamente.\n");
            }
        }        
        
        if (opcao == '1') {  
			printf("\n   Inserir   \n");          
            inserir(bin);
        } else if (opcao == '2') {
            printf("\n   Lista   \n");
            visualizar(bin);
        } else if (opcao == '3') {
            printf("\n   Sair   \n");
            break; 
        }
    }   

    fclose(bin);
    return 0;
}

