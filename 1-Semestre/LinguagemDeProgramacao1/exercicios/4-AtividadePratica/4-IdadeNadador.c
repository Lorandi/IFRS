
#include <stdio.h>

int
main ()
{
  float idadeDoAluno;
  printf ("\nEntre com a idade do aluno: ");
  scanf ("%f", &idadeDoAluno);

  if (idadeDoAluno < 18)
    {
      if (idadeDoAluno <= 17)
	{
	  if (idadeDoAluno <= 13)
	    {
	      if (idadeDoAluno <= 10)
		{
		  if (idadeDoAluno <= 7)
		    {
		      if (idadeDoAluno < 5)
			{
			  printf ("\nAluno muito novo");
			}
		      else
			{
			  printf ("\nInfantil A");
			}

		    }
		  else
		    {
		      printf ("\nInfantil B");
		    }
		}
	      else
		{
		  printf ("\nJuvenil A");
		}
	    }
	  else
	    {
	      printf ("\nJuvenil B");
	    }
	}
    }
  else
    {
      printf ("\nAdulto");
    }
  return 0;
}
