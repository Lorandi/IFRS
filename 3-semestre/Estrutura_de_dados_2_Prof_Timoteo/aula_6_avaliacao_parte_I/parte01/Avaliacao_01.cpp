#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <locale.h>

main()
{
int icodigo;
char esfera[16]; 
char solicitante[80]; 
char situacao[10]; 
char data[16]; 
char motivo[80]; 

setlocale(LC_ALL, "Portuguese");

FILE *txt;

int count;

if((txt = fopen("dados.prn","r")) == NULL)
    {
        printf("Erro ao abrir arquivo");
    }
 else
     {
        while (!feof(txt)) {
               fscanf(txt, "%d %10s %79[^\n] %8s %10s %80[^\n]", &icodigo, esfera, solicitante, situacao, data, motivo);
			   printf("%d \t %d - %s - %s - %s - %s - %s\n",count++, icodigo, esfera, solicitante, situacao, data, motivo);
			   
              }
        fclose(txt);
      }
system("pause"); 
}

    
