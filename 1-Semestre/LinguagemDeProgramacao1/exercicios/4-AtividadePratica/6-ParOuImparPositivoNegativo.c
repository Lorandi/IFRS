
#include <stdio.h>

int
main ()
{
  int numero1;

  printf ("\nDigite um número: ");
  scanf ("%d", &numero1);

  if (numero1 == 0)
    {
    printf ("\nVocê digitou zero!!!");
    }else{
        if (numero1 > 0){
	        if (numero1 % 2 == 0){
	            printf ("\nVocê digitou um número positivo e par ! ! !");
	       }else{
	            printf("\nVocê digitou um número positivo e impar ! ! !");
	       }
	    }else{
	        if (numero1 % 2 == 0){
	            printf ("\nVocê digitou um número negativo e par ! ! !");
	       }else{
	            printf("\nVocê digitou um número negativo e impar ! ! !");
	       }
    	}
    }
  return 0;
}
