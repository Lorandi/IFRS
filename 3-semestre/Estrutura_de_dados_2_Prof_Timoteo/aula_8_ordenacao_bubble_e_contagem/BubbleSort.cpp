#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>
int main() {
//Inicializaçã do Vetor
 int v[5]= {8,1,13,19,28}, n=5;
 int i, j = 0,  aux, flag = 0;
//Algoritmo de Ordenação 
	while (j < n){
	
		printf("\nj=%d", j);
		flag = 0;
		for(i = 0; i < n-1; i++){
		
			if(v[i] > v[i + 1])
			{
             			aux=v[i];
             			v[i] = v[i+1];
             			v[i+1] = aux;
             			flag = 1;
			}
		}			
		if(flag==0)
		 break;
		j++;}
//Laço de impressão do Vetor
	printf("\nVector: ");
	for (int q=0; q<5; q++)
	{
        printf("%d ",v[q]);
    }
    system("pause");  
}
