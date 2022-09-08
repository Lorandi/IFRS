#include <stdio.h>

int
main ()
{

  float preco, quantidade, total, premio;
 
  
  printf ("\nEntre com a preço:R$ ");
  scanf ("%f", &preco);

  printf ("\nEntre com a quantidade: ");
  scanf ("%f", &quantidade);

  total = preco * quantidade;
  premio = total * 2;
  
  printf ("\nA total gasto foi R$ %.2f", total);
  printf ("\nO prêmio foi de R$ %.2f", premio);
  return 0;
}

