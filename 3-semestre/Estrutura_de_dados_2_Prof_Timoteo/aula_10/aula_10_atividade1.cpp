#include <stdio.h>

/*
Fazer uma fun��o recursiva que receba um valor
como par�metro de mostre o somat�rio do
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
