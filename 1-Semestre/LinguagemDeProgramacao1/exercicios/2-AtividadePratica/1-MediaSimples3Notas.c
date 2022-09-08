#include <stdio.h>

int
main ()
{

  float nota1, nota2, nota3, media;

  printf ("\nEntre com a nota 1: ");
  scanf ("%f", &nota1);
  printf ("\nEntre com a nota 2: ");
  scanf ("%f", &nota2);
  printf ("\nEntre com a nota 3: ");
  scanf ("%f", &nota3);

  media = (nota1 + nota2 + nota3) / 3;

  printf ("\nA média de notas foi %f", media);

  return 0;
}

