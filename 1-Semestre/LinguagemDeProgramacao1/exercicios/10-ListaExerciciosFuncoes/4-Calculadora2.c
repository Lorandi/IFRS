
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

float fatorial(float num1)
{
    int total = num1;
    for(int i = num1 - 1; i > 1; i--){
        total*=i;
    }
  return total;
}

float potencia(float num1, float num2)
{
  int total = num1;
    for(int i = 1; i < num2; i++){
        total*=num1;
    }
  return total;
}


int
main ()
{
  float num1, num2, num3;
  int operacao, continuar = 1, maxAleatorio = 10;
  
  srand (time (NULL));

  do{
      
    operacao = rand () % 7;
    num1 = rand () % maxAleatorio + 1;
    num2 = rand () % maxAleatorio + 1;
    
    if(operacao == 0){
        operacao = rand () % 7;
    }

	printf ("\n Digite a operação que quer fazer ou zero para sair: ");
    printf ("\n 1 - Somar 2 números");
    printf ("\n 2 - Subtrair 2 números");
    printf ("\n 3 - Dividir 2 números");
    printf ("\n 4 - Multiplicar 2 números");
    printf ("\n 5 - Fatorial do número");
    printf ("\n 6 - Elevar à portência");
    printf ("\n 0 - sair");
    printf ("\n");
    printf ("\nValor digitado %d \n", operacao);

    
      switch (operacao)
    	{
    	case 1: printf ("\n A soma dos numeros %.2f e %.2f  é %.2f \n", num1, num2, soma(num1, num2)); break;
    
    	case 2: printf ("\n A multiplicação de %.2f por %.2f  é %.2f \n", num1, num2, multiplica(num1, num2)); break;
    
    	case 3: printf ("\n A divisão de %.2f por %.2f é %.2f \n", num1, num2, divide(num1, num2));break;
    
    	case 4: printf ("\n A subtração de %.2f - %.2f  é %.2f \n", num1, num2, subtrai(num1, num2)); break;
    	
    	case 5: printf ("\n O fatorial do número %.2f  é %.2f \n", num1,  fatorial(num1)); break;
    	
    	case 6: printf ("\n %.2f elevados a %.2f  é %.2f \n", num1, num2, potencia(num1, num2)); break;
    	
    	case 0: 
    	    printf("\nAté logo");
    	    continuar = 0; break;
    	}
	
    }while (operacao != 0);
  
  return 0;
}


