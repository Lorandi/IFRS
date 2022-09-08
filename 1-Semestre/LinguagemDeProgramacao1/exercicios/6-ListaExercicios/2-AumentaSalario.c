
#include <stdio.h>
#include <string.h>

int
main ()
{
  float salario;
  char string1[20];
  
  printf ("\nDigite seu nome: ");
  gets (string1);
  
  printf ("\nDigite seu salario: ");
  scanf("%f", &salario);
  
  if(salario < 500){
      printf ("\n %s teve seu salário aumentado para R$%.2f!", string1, salario *= 1.3 );
  }else{
      printf ("\n %s não tem direito ao aumento do salário!", string1);
  }
  return 0;
}
