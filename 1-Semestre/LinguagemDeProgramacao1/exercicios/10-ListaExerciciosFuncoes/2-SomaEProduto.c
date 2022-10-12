
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int soma(int num1, int num2, int num3){
   return num1 + num2 + num3;
}

int produto(int num1, int num2, int num3){
   return num1 * num2 * num3;
}



int main()
{
    int num1, num2, num3, maxAleatorio = 100;
    
    // estabelece que a seed do randon será diferente cada vez que rodar o código
   srand(time(NULL));
   
   num1 = rand() % maxAleatorio;
   num2 = rand() % maxAleatorio;
   num3 = rand() % maxAleatorio;
    
   printf("\n A soma dos números %d, %d, %d é: %d.", num1, num2, num3, soma(num1, num2, num3));
   printf("\n O produto dos números %d, %d, %d é: %d.", num1, num2, num3, produto(num1, num2, num3));

    return 0;
}

