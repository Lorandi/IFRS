
#include <stdio.h>

int main()
{
    int vetor[10]; 
int *ptr; vetor[0] = 1; 
ptr = vetor; //mesmo que &vetor[0]
printf("ptr = %p\n", ptr); 
ptr = &vetor[0]; 
printf("ptr = %p\n", ptr);
}
