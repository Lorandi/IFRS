
#include <stdio.h>
#define TOTAL 3

typedef struct{
    char nome[50];
    char telefone_fixo[15];
    char celular[15];
    char endereco[50];
    char aniversario[10];
} Pessoa;

int main()
{
    Pessoa agenda[TOTAL];
    
    int contato = 0;
    
    int continua;
    
    
    for(int i=0;i<TOTAL;i++){
        printf("\n");
        printf("Insira os dados do contato %d: \n", i + 1);
        printf("Nome: ");
        gets(agenda[i].nome);
        
        printf("Telefone fixo: ");
        gets(agenda[i].telefone_fixo);
        
        printf("Celular: ");
        gets(agenda[i].celular);
        
        printf("Endereco: ");
        gets(agenda[i].endereco);
        
        printf("Aniversário: ");
        gets(agenda[i].aniversario);
        printf("\n");
    }
    
    do{
        continua = 0;
        printf(" Qual contato quer ver?");
        scanf("%d", &contato);
        getchar();
        
        if(contato > 0 && contato <= TOTAL){
            contato--;
            printf("%s, %s, %s, %s, %s \n ", 
            agenda[contato].nome,
            agenda[contato].telefone_fixo,
            agenda[contato].celular,
            agenda[contato].endereco,
            agenda[contato].aniversario);
            continua = 1;
        } else{
            printf("Contato não encontrado \n\n");
        }
    }while(continua == 1);
    
    printf("Programa foi terminado \n");

    return 0;
}


