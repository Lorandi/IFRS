#include <stdio.h>

int
main ()
{

  float nota1, nota2, nota3, nota4, media, faltas;

  printf ("\nEntre com a nota 1: ");
  scanf ("%f", &nota1);
  printf ("\nEntre com a nota 2: ");
  scanf ("%f", &nota2);
  printf ("\nEntre com a nota 3: ");
  scanf ("%f", &nota3);
  printf ("\nEntre com a nota 4: ");
  scanf ("%f", &nota4);
  printf ("\nEntre com total de faltas: ");
  scanf ("%f", &faltas);

  nota2 *= 2;
  nota3 *= 3;
  nota4 *= 4;

  media = (nota1 + nota2 + nota3 + nota4) / 10.0;

  if (faltas >= 5.0)
    {
      printf ("\nAluno reprovado por faltas");
    }
  else
    {
      if (media < 7)
	{
	  printf ("\nAluno reprovado por média menor que 7");
	}
      else
	{
	  printf ("\nParabéns você foi aprovado");
	}
    }

  printf ("\nA média de notas foi %f", media);

  return 0;
}
