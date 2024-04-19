#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cpessoa
{
	
	int codigo;
	char nome[20];
	float saldo;
};

int main(void)
{
	int condicao = 0;
	Cpessoa aluno[1000];
	FILE *bin;
	
	int icodigo = -1;
	char operacao; 
	float valor; 
	int contador, indice = 0; 

	//Abre o Arquivo Binario	
	if((bin = fopen("arquivo_dados.txt","ab+")) == NULL)
    {
        printf("Erro ao abrir arquivo");
    }
 	else
	{
		//Carrega o Arquivo no Memoria
		rewind(bin);
		while ( fread(&aluno[indice] ,1, sizeof(Cpessoa), bin)!=0)
		{
			indice++;
		} 
		fclose(bin); 


		//menu Principal
		while (true)
		{
			system("cls");
			printf("[1] - Inserir\n"); 
			printf("[2] - Listar\n"); 
			printf("[3] - Operacao\n"); 
			printf("[4] - Sair\n"); 
		
			printf ("Digite a opcao: ");
  			scanf("%d", &condicao);
	
			switch  (condicao)
			{
			case 1:
				
						printf("Informe o Codigo:"); 
						scanf("%d", &aluno[indice].codigo);

						fflush(stdin); 

						printf("Informe o nome:"); 
						scanf("%[A-Z a-z0-9]s", aluno[indice].nome);
		
						printf("Informe o Saldo:"); 
						scanf("%f", &aluno[indice].saldo);
					
						//Atualiza o Arquivo -- Pode ser criado um Procedimento - m?todo						
						bin = fopen("arquivo_dados.txt","wb");
						contador=0;
						indice++;	

						while (contador < indice )
						{
							fwrite(&aluno[contador], 1, sizeof(Cpessoa), bin);
							contador++;
						}
						fclose(bin);
	
						break;
				
			case 2 :
					contador=0;
					while (contador < indice )
					{
						printf("->%d \t %-20s %f\n", aluno[contador].codigo, aluno[contador].nome, aluno[contador].saldo);
						contador++;
					} 
					
					fclose(bin); 
					fflush(stdin);
					getchar();	
					break;
			case 3:
					printf("Informe o Codigo do Cliente..............:"); 
					scanf("%d", &icodigo);
					fflush(stdin);
					
					printf("Informe a Operacao [D]edito ou  [C]redito:"); 
					scanf("%c", &operacao);
					fflush(stdin);
					
					printf("Informe o Valor:.........................:"); 
					scanf("%f", &valor);
					
					contador=0;
					
					while (contador < indice )
					{
						if (aluno[contador].codigo == icodigo)
						{
							//Atualiza o saldo
							if ((operacao == 'D') or (operacao == 'd' ))						
								aluno[contador].saldo = aluno[contador].saldo - valor; 
							else
								aluno[contador].saldo = aluno[contador].saldo + valor; 
							
						}
						contador++;
					}
					
					//Atualiza o Arquivo -- Pode ser criado um Procedimento - m?todo
					bin = fopen("arquivo_dados.txt","wb");
					contador=0;
					while (contador < indice )
					{
						fwrite(&aluno[contador], 1, sizeof(Cpessoa), bin);
						contador++;
					}
					fclose(bin);		
					break;
			case 4:
					return(0);
			default:
				printf("Opcao desconhecida. Tente novamente!"); 
				fflush(stdin);
				getchar();
			}
			
		}
	
	}
}
