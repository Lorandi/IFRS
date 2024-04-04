#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Cpessoa
{
	char nome[20];
	int idade;
}Cpessoa;

int main(void)
{
	//Cpessoa aluno[4];
	// Aloca memória para 4 structs Cpessoa
    Cpessoa *aluno = (Cpessoa *)malloc(4 * sizeof(Cpessoa));
    if (aluno == NULL) {
        printf("Erro na alocação de memória\n");
        return 1;
    }
	Cpessoa *paluno = aluno;
	
	strcpy(paluno->nome, "Celso de Melo");
	paluno->idade = 22;
	paluno++;
	
	strcpy(paluno->nome, "Augusto Nunes");
	paluno->idade = 22;
	paluno++;
	
	strcpy(paluno->nome, "Julia Cleria");
	paluno->idade = 23;
	paluno++;
	
	strcpy(paluno->nome, "Lucas Barroso");
	paluno->idade = 24;
	paluno++;
	
	paluno = aluno;
	
	for (int i = 0; i<4 ; i++)
	{
		printf("%s \t %d \n", paluno->nome, paluno->idade);
		paluno++;
	}
	
	// Libera a memória alocada
    free(aluno);
    
	getchar();
	
	return 0;
	
}
