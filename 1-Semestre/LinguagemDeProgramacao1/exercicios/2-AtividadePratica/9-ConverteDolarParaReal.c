#include <stdio.h>

int
main ()
{

  float cotacaoDolar, quantidadeDeDolares, total;
 
  
  printf ("\nEntre com a cotação 1U$ = R$: ");
  scanf ("%f", &cotacaoDolar);

  printf ("\nEntre quantos dolares quer converter para reais. U$ ");
  scanf ("%f", &quantidadeDeDolares);

  total = quantidadeDeDolares * cotacaoDolar;
  
  printf ("\nCom U$ %.2f é possível comprar R$ %.2f", quantidadeDeDolares, total);
  
  return 0;
}
