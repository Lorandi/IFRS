#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    int n = 10;
    int vetor[n], soma = 1;
    // char string[27] = "abcdefghijklmnopqrstuvwxyz", letras;
    char string[27] = "abcdefghijklmnopqrstuvwxyz", letras;
    
    srand(time(NULL));
    
    for (int i = 0; i < 10; i++){
        vetor[i] = rand() % 10 + 1;
        // letras = string[rand() % 26];
        letras = 96 + vetor[i];
        printf("%d", vetor[i]);
        printf("%c", letras);
    }

    return 0;
}

