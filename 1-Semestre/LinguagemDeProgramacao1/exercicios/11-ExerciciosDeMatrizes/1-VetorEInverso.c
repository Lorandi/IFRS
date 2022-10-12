#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    int vetor[10];
    
    srand(time(NULL));
    
    for (int i = 0; i < 10; i++){
        vetor[i] = rand() % 10;
        printf("%d ", vetor[i]);
    }
    
    printf("\n");
    
    for (int i = 10; i > 0;){
        printf("%d ", vetor[--i]);
    }

    return 0;
}

