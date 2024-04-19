#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <locale.h>
#define TAMANHO 1000
#define MAXLINHA 999

	//****************Atividade 01**********************
	typedef struct {
		int icodigo;
		char esfera[16];
		char solicitante[80];
		char situacao[10];
		char data[16];
		char motivo[80];
	} DADOS;

void busca(int x, DADOS *  vetor, int tamanho)
{
  	int meio=0, esquerda = -1, direita = tamanho; 
   	while (esquerda < direita-1) {  
    	  int meio = (esquerda + direita)/2;
      	if (vetor[meio].icodigo < x) 
  	esquerda = meio;
	      else 
  	direita = meio; 
   	}

	if (vetor[direita].icodigo==x)
    	printf("\nValor Localizado: %d %s ", vetor[direita].icodigo, vetor[direita].solicitante); 
	else
    	printf("\nValor NAO Localizado"); 
}


int main() {

	FILE *txt;
	
	/* Não é necessário
	int icodigo;
	char esfera[16];
	char solicitante[80];
	char situacao[10];
	char data[16];
	char motivo[80];
	*/
	
	//char linha[MAXLINHA];
	int count = 0;
	int milhar =1;

	DADOS *solicitantes;
	DADOS *solicitantes_inicio;
	
	setlocale(LC_ALL, "Portuguese");
	
	
	//****************Atividade 02.1**********************
	
	solicitantes_inicio = (DADOS*)malloc(TAMANHO * sizeof(DADOS));
	solicitantes = solicitantes_inicio; 
	
	if (!solicitantes) {
		printf("** Erro: Memória Insuficiente **");
	} 
	else 
	{
		printf("Memória alocada com sucesso!!!");
	
		if ((txt = fopen("dados.prn","rb")) == NULL) {
			printf("Erro ao abrir arquivo");
		} 
		else 
		{
			while (!feof(txt)) 
			{
				fscanf(txt, "%d %10s %79[^\n] %8s %10s %80[^\n]", &solicitantes->icodigo, solicitantes->esfera, solicitantes->solicitante, solicitantes->situacao, solicitantes->data, solicitantes->motivo);
				solicitantes++;
				count++;

				//Realocação Dinamicar de 1000 em 1000 --2
				if (count >= (TAMANHO * milhar)-1)
				{
					milhar++; 
					// realloc ---2.1
					solicitantes_inicio = (DADOS*)realloc(solicitantes_inicio, (TAMANHO * milhar) * sizeof(DADOS)); // Aumenta o Bloco Reservado
				
					solicitantes = solicitantes_inicio + count;  // Posiciona o Ponteiro para Continuar de onde parou
					
					printf ("\nAumentando o tamanho para: %d Posicoes", milhar * TAMANHO ); 
				}				

			}

			printf("\nO número de linhas lidas foi %d\n", count);
			fclose(txt);
		}
	}



	// Criação do Arquivo binário. 
	FILE *bin;

	bin = fopen("dados.bin","wb+");

	solicitantes = solicitantes_inicio;  // Posiciona no Inicio do Bloco de Memória
	int linhas=0;

	//Escrevendo no Arquivo Binário
	while (linhas < count )
	{
		fwrite(&solicitantes, 1, sizeof(solicitantes), bin);
		solicitantes++;
		linhas++;
	}
	
	fclose(bin);

	
	//Implementando Busca binária - Repare, o ponteio pode ser usado como Vetor. 
	int codigo =-1; 
	while (codigo != 0)
	{
		printf("\nQual codigo deseja buscar? Zero [0] para Finalizar busca: ");
		scanf("%d", &codigo);
	
		if (codigo != 0 )
			busca(codigo, solicitantes_inicio, count); // Passando o codigo, o Bloco de Memoria e o tamanho de posicoes
		
	}

	
	// Lendo o Arquivo Binário e Monstrando na Tela - Verificação Somente
	printf("Deseja mostrar o arquivo binário na tela? [1]-SIM [0]-NAO: ");
	scanf("%d", &codigo);
	if (codigo ==1)
	{
		count=0;
		bin = fopen("dados.bin","rb+");
		//lendo no Arquivo Binário
		while (!feof(bin))
		{
			fread(&solicitantes, 1, sizeof(solicitantes), bin);
			count++; 
			printf("\n %d %d %s",count, solicitantes->icodigo, solicitantes->solicitante );
		}
	fclose(bin);
	}

	free(solicitantes);
	free(solicitantes_inicio);
	
	return 0;
}
