#include <stdio.h>
#include <stdlib.h>

void counting_sort(int *array, int size)
{
 int i, min, max;
 int j=0; 
 min = max = array[0];
 //Identifica o Maior Elemento
 for(i = 1; i < size;  i++) 
 {
  if (array[i] < min)
     min = array[i];
  else if (array[i] > max)
     max = array[i];  }
  int range = max - min + 1;
  int *count = (int *) malloc(range * sizeof(int));
//Marca Todas as posições com Zero
  for(i = 0; i < range; i++)
          count[i] = 0;
//Marca as posições ocupadas
  for(i = 0; i < size; i++)
         count[array[i] - min]++;
 int indice;
 indice=0; 
//Array recebe as posicoes ocupadas
        for(i = min; i <= max; i++)
           for(j = 0; j < count[ i - min ]; j++)
           {
            array[indice] = i;
            indice++;
		   }
        free(count);
}

main ()
{
//Inicializaçã do Vetor
    int v[5]= {10,7,4,3,5};
    int n=5;
    int i, j = 0,  aux;
//Algoritmo de Ordenação 
 counting_sort(v,n);
//Laço de impressão do Vetor
    for (int q=0; q<5; q++)
    {
        printf("%d\n",v[q]);
    }
}

