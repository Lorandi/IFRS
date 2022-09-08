
#include <stdio.h>

int
main ()
{

  float nota1, nota2, nota3, nota4, media;


  printf ("\nEntre com a nota 1: ");
  scanf ("%f", &nota1);

  printf ("\nEntre com a nota 2: ");
  scanf ("%f", &nota2);

  printf ("\nEntre com a nota 3: ");
  scanf ("%f", &nota3);

  printf ("\nEntre com a nota 4: ");
  scanf ("%f", &nota4);

  nota2 *= 2;
  nota3 *= 3;
  nota4 *= 4;
  media = (nota1 + nota2 + nota3 + nota4) / 10.0;

  if (media >= 7)
    {
      printf ("\nParabéns vocC* foi aprovado");
    }
  else
    {
      printf ("\nAluno reprovado");
    }
  printf ("\nA média de notas foi %f", media);
  return 0;
}
