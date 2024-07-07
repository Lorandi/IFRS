#include <stdio.h>

/*
Fazer uma função recursiva que receba um valor
como parâmetro de mostre o somatório do
valor.
Exemplo: Valor = 5
Calcular 5+4+3+2+1 
*/

int somatorio (int x){ 
if (x ==1)
 return (1);
else
 return  x + somatorio(x-1);
 }


main () {	
 printf("%d ",somatorio(5));	 	
}
