#include <stdio.h>

int
main ()
{

    int numeroDoFuncionario;
    
  float salario, INPC, produtividade, aumentoSalario;

  printf ("\nEntre com o numero do funcionario: ");
  scanf ("%d", &numeroDoFuncionario);

  printf ("\nEntre com o salario: ");
  scanf ("%f", &salario);

  printf ("\nEntre com a produtividade: ");
  scanf ("%f", &produtividade);
  
  INPC = 1.30;
  
  aumentoSalario = salario*0.75*INPC/100  + salario*produtividade/100;
  
  printf ("\nO aumento no salario foi de  R$%.2f", aumentoSalario);
  
  salario = salario + aumentoSalario;
  
  printf ("\nO novo salario é de  R$%.2f", salario);
  return 0;
}


