


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int quadrado(int num){
   return num*num;
}



int main()
{
    int numero, maxAleatorio = 100;
    // estabelece que a seed do randon será diferente cada vez que rodar o código
   srand(time(NULL));
   
   numero = rand() % maxAleatorio;
    
   printf("\n O número %d ao quadrado é: %d.", numero, quadrado(numero));

    return 0;
}

