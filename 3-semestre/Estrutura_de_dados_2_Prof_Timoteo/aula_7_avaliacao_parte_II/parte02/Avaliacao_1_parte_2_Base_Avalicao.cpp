#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cpessoa
{
	char nome[20];
	int idade;
};

int main(void)
{
	int condicao = 0;
	Cpessoa aluno;
	FILE *bin;

	//Abre o Arquivo Bin?rio	
	if((bin = fopen("arquivo_binario.txt","ab+")) == NULL)
    {
        printf("Erro ao abrir arquivo");
    }
 	else
	{
	
		//menu Principal
		while (true)
		{
			system("cls");
			printf("[1] - Inserir\n"); 
			printf("[2] - Listar\n"); 
			printf("[3] - Sair\n"); 
		
			printf ("Digite a opcao: ");
  			scanf("%d", &condicao);
	
			switch  (condicao)
			{
			case 1:
				
						printf("Informe o nome:"); 
						scanf("%s", aluno.nome);
		
						printf("Informe a idade:"); 
						scanf("%d", &aluno.idade);
	
						fwrite(&aluno, 1, sizeof(aluno), bin);
						break;
				
			case 2 :
					rewind(bin);
					while ( fread(&aluno ,1, sizeof(Cpessoa), bin)!=0)
					{
						printf("-> %-20s \t %d \n", aluno.nome, aluno.idade);
					} 
					
					fflush(stdin);
					getchar();	
					break;
			case 3:
					return(0);
			default:
				printf("Opcao desconhecida. Tente novamente!"); 
				fflush(stdin);
				getchar();
			}
			
		}
	
	}
}
