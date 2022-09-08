#include <stdio.h>

int
main ()
{

  float cotacaoDolar, quantidadeDeReais, total;
 
  
  printf ("\nEntre com a cotação 1U$ = R$: ");
  scanf ("%f", &cotacaoDolar);

  printf ("\nEntre quantos reais quer converter: R$ ");
  scanf ("%f", &quantidadeDeReais);

  total = quantidadeDeReais / cotacaoDolar;
  
  printf ("\nCom R$ %.2f é possível comprar U$ %.2f", quantidadeDeReais, total);
  
  return 0;
}
