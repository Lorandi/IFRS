#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO 100

typedef struct Cpessoa
{
	int codigo;
	char nome[20];
	int saldo;
}DADOS;

int main(void)
{
	int condicao = 0;
	DADOS *correntistas = (DADOS*)malloc( TAMANHO * sizeof(DADOS));
	int num_correntistas = 0;
	int num_lidos;
	FILE *bin;
	
   //Abre o Arquivo Bin?rio	
	if((bin = fopen("correntistas.bin","a+b")) == NULL)
    {
        printf("Erro ao abrir arquivo");
        return 1;
    }else	{
    	
    	int num_lidos = fread(correntistas, sizeof(DADOS), TAMANHO ,bin);
    	num_correntistas += num_lidos;
		
		while (true)
		{
			system("cls");
			printf("[1] - Inserir correntista\n"); 
			printf("[2] - Listar\n"); 
			printf("[3] - Fazer uma operacao\n"); 
		
			printf ("Digite a opcao: ");
  			scanf("%d", &condicao);
	
			switch  (condicao)
			{
			case 1:
						
						printf("Informe o codigo do correntista:"); 
						scanf("%d", &correntistas->codigo);
						
						printf("Informe o nome:"); 
						scanf("%s", correntistas->nome);
		 
						printf("Informe o saldo :"); 
						scanf("%d", &correntistas->saldo);	
						fwrite(correntistas, sizeof(DADOS), 1, bin);
						break;
				
			case 2 :
					rewind(bin);
					while ( fread(&correntistas[0], sizeof(DADOS), 1, bin)!=0)
					{
						printf("-> %d   %-20s %d \n", correntistas[0].codigo, correntistas[0].nome, correntistas[0].saldo);
					}					 
					
					fflush(stdin);
					getchar();	
					break;
			case 3:
				rewind(bin);
				int codigoCorrentista;
				int operacao;
				int valor;
					printf("Informe o codigo do correntista:"); 
					scanf("%d", &codigoCorrentista);
					while(1){
						printf("Operação Débito [1] ou Crédito [2]:");
						scanf("%d", &operacao);					
						if(operacao == 1){
							printf("Quanto quer debitar: ");
							scanf("%d", &valor);
							valor = valor * (-1);
							break;
							
						}else if (operacao == 2){
							printf("Quanto quer depositar: ");
							scanf("%d", &valor);
							break;
							
						}else{
							printf("Operacao invalida");
						}						
					}					
					rewind(bin);
					while ( fread(&correntistas , sizeof(DADOS), 1, bin)!=0)
					{
						if(correntistas[0].codigo == codigoCorrentista){
							correntistas[0].saldo = valor;
						}
					}			
				
					
					
			default:
				printf("Opcao desconhecida. Tente novamente!"); 
				fflush(stdin);
				getchar();
			}
			
		}
	
	}
}
