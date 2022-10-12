#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    int vetor[10], soma = 1;
    
    srand(time(NULL));
    
    for (int i = 0; i < 10; i++){
        vetor[i] = rand() % 10 + 1;
        printf("%d ", vetor[i]);
        soma *= vetor[i];
    }
    
    printf("\n A multiplicação é: %d ", soma);

    return 0;
}

