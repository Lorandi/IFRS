#include <stdio.h>

int
main ()
{
  int valor = 0, cem = 0, cinquenta = 0, vinte = 0, dez = 0, cinco = 0, dois =
    0, um = 0;

  printf ("\nEntre com o valor a sacar: ");
  scanf ("%d", &valor);

  if (valor >= 100)
    {
      cem = valor / 100;
      valor = valor - cem * 100;
    }

  if (valor >= 50)
    {
      cinquenta = valor / 50;
      valor = valor - cinquenta * 50;
    }

  if (valor >= 20)
    {
      vinte = valor / 20;
      valor = valor - vinte * 20;
    }

  if (valor >= 10)
    {
      dez = valor / 10;
      valor = valor - dez * 10;
    }

  if (valor >= 5)
    {
      cinco = valor / 5;
      valor = valor - cinco * 5;
    }

  if (valor >= 2)
    {
      dois = valor / 2;
      valor = valor - dois * 2;
    }

  if (valor >= 1)
    {
      um = valor / 1;
      valor = valor - um * 1;
    }

  printf ("\n Notas de R$100: %d", cem);
  printf ("\n Notas de R$50: %d", cinquenta);
  printf ("\n Notas de R$20: %d", vinte);
  printf ("\n Notas de R$10: %d", dez);
  printf ("\n Notas de R$5: %d", cinco);
  printf ("\n Notas de R$2: %d", dois);
  printf ("\n Notas de R$1: %d", um);


  return 0;
}

