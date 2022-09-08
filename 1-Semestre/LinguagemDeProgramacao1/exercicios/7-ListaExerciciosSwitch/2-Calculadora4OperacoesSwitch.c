
#include <stdio.h>

int
main ()
{

  char sinal;
  float number1, number2;


  printf ("\nCALCULADORA");

  printf ("\nDigite o primeiro valor: ");
  scanf ("%f", &number1);

  printf ("\nDigite o segundo valor: ");
  scanf ("%f", &number2);
  
  //esse getchar() serve para fazer limpeza de buffer do scanf
  getchar();
  
  printf ("\nDigite o tipo de operação: ");
  sinal = getchar ();

  switch (sinal)
    {
    case '+':
      printf ("\n Valor final é %.2f!", number1 + number2);
      break;
    case '-':
      printf ("\n Valor final é %.2f!", number1 + -number2);
      break;
    case '/':
      printf ("\n Valor final é %.2f!", number1 / number2);
      break;
    case '*':
      printf ("\n Valor final é %.2f!", number1 * number2);
      break;
    default:
      printf ("\nOpção inválida");
    }

  return 0;
}


