#include <stdio.h>

int
main ()
{

  float prova1, prova2, trabalho, faltas, media;

  printf ("\nEntre com a prova 1: ");
  scanf ("%f", &prova1);
  printf ("\nEntre com a prova 2: ");
  scanf ("%f", &prova2);
  printf ("\nEntre com a nota do trabalho: ");
  scanf ("%f", &trabalho);
  printf ("\nEntre com o total de faltas: ");
  scanf ("%f", &faltas);


  media = (prova1 + prova2 + trabalho) / 3.0;

  if (faltas >= 5.0)
    {
      printf ("\nConceito E. Aluno Reprovado por faltas");
    }
  else
    {
      if (media > 0)
	{
	  if (media >= 6)
	    {
	      if (media >= 7)
		{
		  if (media >= 8)
		    {
		      printf ("\nConceito A");
		    }
		  else
		    {
		      printf ("\nConceito B");
		    }
		}
	      else
		{
		  printf ("\nConceito C");
		}
	    }
	  else
	    {
	      printf ("\nConceito D");
	    }
	}
    }


  return 0;
}
