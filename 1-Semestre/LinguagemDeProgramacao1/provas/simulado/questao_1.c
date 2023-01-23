// Algoritmo criado para simulado 2 da disciplina Linguagens de ProgramaC'C#o 1
// Autor: Rodrigo Lorandi
// Professor: FABIO YOSHIMITSU OKUYAMA
// Porto Alegre, 17/11/2022

#include <stdio.h>
#define PRINCIPAL 4
#define N_LINHAS PRINCIPAL
#define N_COLUNAS PRINCIPAL
#define N_MULTIPLICADOR 4


float mediaMatriz (int matriz[N_LINHAS][N_COLUNAS], int linhas, int colunas);

int somaDosDivisiveisPor5(int matriz[N_LINHAS][N_COLUNAS], int linhas, int colunas);


int main (){
  int numeroBase = N_MULTIPLICADOR, somaDiagonalPrincipal = 0, somaDiagonalSecundaria = 0;
  int somaColuna0 = 0, somaColuna1 = 0, somaColuna2 = 0, somaColuna3 = 0;
  int matriz[N_LINHAS][N_COLUNAS];
  int somaLinhas[N_LINHAS];
  int somaColunas[N_COLUNAS];
  float mediaDiagonalSecundaria;
  
  // Preencher o vetor somaColunas[N_COLUNAS] com valores 0;
   for (int j = 0; j < N_COLUNAS; j++){
    somaColunas[j] = 0; 
  }
  
  // Preencher o vetor somaLinhas[N_LINHAS] com valores 0;
   for (int i = 0; i < N_LINHAS; i++){
    somaLinhas[i] = 0; 
  }

  printf
    ("\na) Preenchimento correto da matriz/exibir corretamente a matriz\n");
  for (int i = 0; i < N_LINHAS; i++)
    {
      for (int j = 0; j < N_COLUNAS; j++)
	{
	  matriz[i][j] = numeroBase;
	  printf ("%d  ", matriz[i][j]);
	  numeroBase += N_MULTIPLICADOR;
	  if ((i + j) == PRINCIPAL - 1){
	      somaDiagonalSecundaria += matriz[i][j];
	   }

	  if (i == j){
	      somaDiagonalPrincipal += matriz[i][j];
	   }
	   
	   somaColunas[j] = somaColunas[j] + matriz[i][j];

	}
      printf ("\n");
    }

  mediaDiagonalSecundaria = somaDiagonalSecundaria / PRINCIPAL;

  printf ("\nb) Média dos elementos da diagonal secundária é %.2f.\n",
	  mediaDiagonalSecundaria);

  printf ("\nc) SOMA dos elementos da diagonal principal %d.\n", somaDiagonalPrincipal);

  printf ("\nd) Média dos elementos de cada coluna:");
  for (int j = 0; j < N_COLUNAS; j++){
    printf ("\n     Coluna %d: %d", j, somaColunas[j]/PRINCIPAL); 
  }
  printf ("\n");

  
  printf ("\ne) Média da matriz: %.2f \n", mediaMatriz (matriz, N_LINHAS, N_COLUNAS));
  
  printf ("\nf) Soma dos divisíveis por 5 é %d \n", somaDosDivisiveisPor5 (matriz, N_LINHAS, N_COLUNAS));

  printf ("\nProgramador: Rodrigo Lorandi\n");

  return 0;
}

float mediaMatriz (int matriz[N_LINHAS][N_COLUNAS], int linhas, int colunas){
  float somaTodosOsNumeros = 0;

  for (int i = 0; i < linhas; i++)
    {
      for (int j = 0; j < colunas; j++){
          somaTodosOsNumeros += matriz[i][j];

	    }
    }
    return somaTodosOsNumeros/(linhas * colunas);
}

int somaDosDivisiveisPor5 (int matriz[N_LINHAS][N_COLUNAS], int linhas, int colunas){
  int somaDosDivisiveisPor5 = 0;

  for (int i = 0; i < linhas; i++)
    {
      for (int j = 0; j < colunas; j++){
          if(matriz[i][j] % 5 == 0){
            somaDosDivisiveisPor5 += matriz[i][j];  
          }

	    }
    }
    return somaDosDivisiveisPor5;
}



