
#include <stdio.h>

int main()
{
    int i = 0; 
    printf("i = %d \n",i);
    int *x[10]; 
    x[2] = &i;
    printf("x[2] = &i -> i = %d \n",i);
    *x[2] = 20;
    printf("se *x[2] = 20 -> i = %d e *x[2] = %d\n",i, *x[2]);
    i = 30;
    printf("se i = 30 -> i = %d e *x[2] = %d\n",i, *x[2]);
    

    printf("O endereço de x[2] é %p e o endereço de i é %p\n", x[2], &i);
    
    
    printf("\n");
    
    
    char *erro[] = {"arquivo não encontrado\n", "erro de leitura\n"}; 
    printf("%s", erro[0]); 
    printf("%s", erro[1]);
    
    erro[0] = "mudou";
    printf("%s", erro[0]); 
}
