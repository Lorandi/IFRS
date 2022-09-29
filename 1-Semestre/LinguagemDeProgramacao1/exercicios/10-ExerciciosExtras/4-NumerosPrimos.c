
#include <stdio.h>

int
main ()
{
  int primos = 0, valor = 1;
  while (primos < 20)
    {
      if (valor == 1 || valor == 2 || valor == 3 || valor == 5 || valor == 7)
	{
	  printf ("\n %d", valor);
	  primos++;
	}
      else
	{
	  if (!(valor % 2 == 0) && !(valor % 3 == 0) && !(valor % 5 == 0)
	      && !(valor % 7 == 0))
	    {
	      printf ("\n %d", valor);
	      primos++;
	    }
	}
      valor++;
    }


  return 0;
}

