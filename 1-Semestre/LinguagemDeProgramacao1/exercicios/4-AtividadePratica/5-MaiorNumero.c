
#include <stdio.h>

int
main ()
{
  int numero1, numero2, numero3;

  printf ("\nEntre com a número 1: ");
  scanf ("%d", &numero1);
  printf ("\nEntre com a número 2: ");
  scanf ("%d'", &numero2);
  printf ("\nEntre com a número 3: ");
  scanf ("%d", &numero3);

  if (numero1 > numero2 && numero1 > numero3)
    {
      printf ("O maior é o número 1: %d", numero1);
    }
  else
    {
      if (numero2 > numero1 && numero2 > numero3)
	{
	  printf ("O maior é o número 2: %d", numero2);
	}
      else
	{
	  printf ("O maior é o número 3: %d", numero3);
	}
    }

  return 0;
}
