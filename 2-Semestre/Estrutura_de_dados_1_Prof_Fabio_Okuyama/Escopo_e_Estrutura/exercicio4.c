#include <stdio.h>
#include <string.h>
#define TOTAL 3

typedef struct{
    char nome[50];
    char telefoneFixo[15];
    char celular[15];
    char endereco[50];
    char aniversario[10];
} Pessoa;

int main()
{
    Pessoa pessoas[TOTAL];
    
    int contato = 0;

    int continua;
    
    Pessoa *p;
        
        for(int i=0;i<TOTAL;i++){
            p = &pessoas[i];
            
        printf("\n");
        printf("Insira os dados do contato %d:\n", i + 1);
        printf("Nome: ");
        fgets(p->nome, 50, stdin);
        p->nome[strcspn(p->nome, "\n")] = '\0'; // Remover quebra de linha

        printf("Telefone fixo: ");
        fgets(p->telefoneFixo, 15, stdin);
        p->telefoneFixo[strcspn(p->telefoneFixo, "\n")] = '\0'; // Remover quebra de linha

        printf("Celular: ");
        fgets(p->celular, 15, stdin);
        p->celular[strcspn(p->celular, "\n")] = '\0'; // Remover quebra de linha

        printf("Endereco: ");
        fgets(p->endereco, 50, stdin);
        p->endereco[strcspn(p->endereco, "\n")] = '\0'; // Remover quebra de linha

        printf("Aniversário: ");
        fgets(p->aniversario, 10, stdin);
        p->aniversario[strcspn(p->aniversario, "\n")] = '\0'; // Remover quebra de linha

        printf("\n");
        }
        
        do{
            continua = 0;
            printf(" Qual contato quer ver?");
            scanf("%d", &contato);
            getchar();
            
            if(contato > 0 && contato <= TOTAL){
                p = &pessoas[contato-1];
                printf("%s, %s, %s, %s, %s \n", p->nome, p->telefoneFixo, p->celular, p->endereco, p->aniversario);
                continua = 1;
            } else{
                printf("Contato não encontrado\n\n");
            }
        }while(continua == 1);
        
        printf("Programa foi terminado\n");
        
    return 0;
}
