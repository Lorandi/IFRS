#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <locale.h>

#define TAMANHO 1000

main()
{	
//****************Atividade 01********************** 
	typedef struct dados{
		int icodigo;
		char esfera[16]; 
		char solicitante[80]; 
		char situacao[10]; 
		char data[16]; 
		char motivo[80]; 
	}DADOS;
	
	int count = 0;
	int times = 1;
	
	//****************Atividade 02.1**********************
	DADOS *solicitantes;
	solicitantes = (DADOS *) malloc(19000 * sizeof(DADOS));	
	if(solicitantes == NULL){
		printf("Erro na alocação de memória");
		return 1;	
	}	
	
	DADOS *psolicitantes = solicitantes;
	

setlocale(LC_ALL, "Portuguese");

FILE *txt;


if((txt = fopen("dados.prn","r")) == NULL)
    {
        printf("Erro ao abrir arquivo");
    }
 else
     {
        while (!feof(txt)) {
        	//****************Atividade 02.2**********************
        	/*int temp;
        	fscanf(txt,"%d\n", &temp);
        	count++;        	
        	if(count == 999){
        		++times;        		
        		solicitantes = ((DADOS *) realloc(solicitantes, times * 1000 * sizeof(DADOS)));
        		count = 0;
			}*/
               fscanf(txt, "%d %10s %79[^\n] %8s %10s %80[^\n]",&psolicitantes->icodigo, psolicitantes->esfera, psolicitantes->solicitante, 
			   psolicitantes->situacao, psolicitantes->data, psolicitantes->motivo);
			   
			   /*printf("%d - %s - %s - %s - %s - %s\n", psolicitantes->icodigo, psolicitantes->esfera, psolicitantes->solicitante, 
			   psolicitantes->situacao, psolicitantes->data, psolicitantes->motivo);*/
			  psolicitantes++;
              }
        fclose(txt);
      }
      
      //****************Atividade 03.1********************** "
      FILE *bin;
      bin = fopen("dados.bin","wb");

	 for(int i = 0; i < 19000; i++){
	 	fwrite(solicitantes, sizeof(DADOS), 1, bin);
	 	solicitantes++;
	 }
      
      
      
      
      
system("pause"); 
}

    
