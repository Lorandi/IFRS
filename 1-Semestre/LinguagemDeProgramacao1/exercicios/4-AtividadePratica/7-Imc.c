#include <stdio.h>

int
main ()
{
  float peso, altura, imc;

  printf ("\nEntre com o pesoo: ");
  scanf ("%f", &peso);

  printf ("\nEntre com a altura: ");
  scanf ("%f", &altura);

  imc = peso / (altura * altura);

  printf ("\nSeu imc C) %f ", imc);

  if (imc <= 39.9)
    {
      if (imc <= 34.9)
	{
	  if (imc <= 29.9)
	    {
	      if (imc <= 24.9)
		{
		  if (imc < 18.5)
		    {
		      printf ("\nVocê está abaixo do peso ideal");
		    }
		  else
		    {
		      printf
			("\nParabéns você está em seu peso normal!");
		    }

		}
	      else
		{
		  printf ("\nVocê está acima de seu peso (sobrepeso)");
		}
	    }
	  else
	    {
	      printf ("\nObesidade grau I");
	    }
	}
      else
	{
	  printf ("\n	Obesidade grau II");
	}
    }
  else
    {
      printf ("\n	Obesidade grau III");
    }

  return 0;
}
