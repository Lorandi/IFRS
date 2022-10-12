
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


float soma(float num1, float num2)
{
  return num1 + num2;
}

float multiplica(float num1, float num2)
{
  return num1 * num2;
}

float subtrai(float num1, float num2)
{
  return num1 - num2;
}

float divide(float num1, float num2)
{
  return num1 / num2;
}


int
main ()
{
  float num1, num2, num3;
  int operacao, continuar = 1, maxAleatorio = 100;
  
  srand (time (NULL));

  do{
      
    operacao = rand () % 5;
    num1 = rand () % maxAleatorio;
    num2 = rand () % maxAleatorio;

	printf ("\n Digite a operação que quer fazer ou zero para sair: ");
    printf ("\n 1 - Somar 2 números");
    printf ("\n 2 - Multiplicar 2 números");
    printf ("\n 3 - Dividir 2 números");
    printf ("\n 4 - Subtrair 2 números");
    printf ("\n 0 - sair");
    printf ("\n");
    printf ("\n\Valor digitado %d \n", operacao);

    
      switch (operacao)
    	{
    	case 1: printf ("\n A soma dos numeros %.2f e %.2f 2 números é %.2f \n", num1, num2, soma(num1, num2)); break;
    
    	case 2: printf ("\n A multiplicação dos numeros %.2f e %.2f 2 números é %.2f \n", num1, num2, multiplica(num1, num2)); break;
    
    	case 3: printf ("\n A divisão dos numeros %.2f e %.2f 2 números é %.2f \n", num1, num2, divide(num1, num2));break;
    
    	case 4: printf ("\n A subtração dos numeros %.2f e %.2f 2 números é %.2f \n", num1, num2, subtrai(num1, num2)); break;
    	
    	case 0: 
    	    printf("\nAté logo");
    	    continuar = 0; break;
    	}
	
    }while (operacao != 0);
  
  return 0;
}

