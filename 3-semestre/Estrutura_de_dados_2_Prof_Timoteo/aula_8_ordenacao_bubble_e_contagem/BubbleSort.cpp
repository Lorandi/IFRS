#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>
int main() {
//Inicializa�� do Vetor
 int v[5]= {9,5,4,6,2}, n=5;
 int i, j = 0,  aux;
//Algoritmo de Ordena��o 
	while (j < n)
	{
		for(i = 0; i < n-1; i++)
			if(v[i] > v[i + 1])
			{
             			aux=v[i];
             			v[i] = v[i+1];
             			v[i+1] = aux;
			}
		j++;}
//La�o de impress�o do Vetor
	for (int q=0; q<5; q++)
	{
        printf("%d \n",v[q]);
    }
    system("pause");  
}
