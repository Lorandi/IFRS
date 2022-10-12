#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int main()
{
    int notas[7] = {100,50,20,10,5,2,1} ,valor; 

    srand(time(NULL));

    printf ("\nEntre com o valor a sacar: ");
    valor = rand() % 1000;
    
    printf("\nValor: R$ %d,00", valor);
  
    for(int i = 0; i < 7; i++){
        if(valor >= notas[i]){
        printf("\nNotas de R$ %d = %d", notas[i], valor/ notas[i] );
        valor = valor - (valor/ notas[i]) * notas[i];
      }
    }

    return 0;
}
