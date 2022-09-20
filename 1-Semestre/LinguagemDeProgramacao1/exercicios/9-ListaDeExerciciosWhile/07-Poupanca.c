
#include <stdio.h>

int main()
{
    float juros = 0.005;
    float deposito = 100;
    float total = deposito;
    int mesesRendendo = 24;
    int iterar = 1;
    
    while (iterar <= mesesRendendo){
        printf("\n Mês %d R$ %.2f", iterar, total);
        
        total = total + (total * juros) + deposito;
        iterar++;
    }
    
    

    return 0;
}

