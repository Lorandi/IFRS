#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ROWS 10
#define COLS 10

int main() {
    int *ptr;
    int vetor[ROWS];
    ptr = &vetor[0]; // Ou simplesmente ptr = vetor;

    // Preenchimento do vetor com valores de 1 a ROWS
    for (int i = 0; i < ROWS; i++) {
        *(ptr + i) = i + 1;
    }

    // Exibindo o vetor para verificação
    printf("Vetor populado:\n");
   for (int i = 0; i < ROWS; i++) {
        printf("Vetor[%d]: %d\t", i, vetor[i]);
        printf("*(ptr + %d): %d\t  &ptr[%d]:%d\t",i, *(ptr + i), i, &ptr[i]);
		printf("*(vetor + %d): %d   &vetor[%d]:%d\t\n",i, *(vetor + i),i, &vetor[i]);
    }
    
    printf("\nVerificacoes:\n");    
    printf("ptr %s     \t%p\n", "%p",ptr);
    printf("vetor %s   \t%p\n", "%p",vetor);
    printf("&ptr %s    \t%p\n","%p", &ptr);
    printf("&vetor %s  \t%p\n", "%p",&vetor);
    
    printf("&ptr %s    \t%d\n","%d", &ptr);
    printf("&vetor %s  \t%d\n","%d", &vetor);
    
    printf("*ptr %s     \t%d\n","%d", *ptr);
    printf("*vetor %s   \t%d\n\n","%d", *vetor);
    
    int index = 8;
    
    printf("ptr[0]  %s \t%d\n","%d", ptr[0]);
    printf("vetor[0] %s \t%d\n", "%d",vetor[0]);
    printf("&ptr[0] %s  \t%d\n", "%d",&ptr[0]);
    printf("&vetor[0] %s \t%d\n", "%d",&vetor[0]);
    printf("&ptr[%d] %s  \t%p\n",index, "%p",&ptr[index]);
    printf("&vetor[%d] %s \t%p\n",index, "%p", &vetor[index]);
    
    
    return 0;
}

