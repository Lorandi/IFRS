#include <stdio.h>

int
main ()
{

  float nota1, nota2, nota3, nota4, media;
  int p1, p2, p3, p4;
  
  printf ("\nEntre com a nota 1: ");
  scanf ("%f", &nota1);

  printf ("\nEntre com a nota 2: ");
  scanf ("%f", &nota2);

  printf ("\nEntre com a nota 3: ");
  scanf ("%f", &nota3);

  printf ("\nEntre com a nota 4: ");
  scanf ("%f", &nota4);

  printf ("\nEntre com o peso 1: ");
  scanf ("%d", &p1);

  printf ("\nEntre com o peso 2: ");
  scanf ("%d", &p2);

  printf ("\nEntre com o peso 3: ");
  scanf ("%d", &p3);

  printf ("\nEntre com o peso 4: ");
  scanf ("%d", &p4);

  media =
    (nota1 * p1 + nota2 * p2 + nota3 * p3 + nota4 * p4) / (p1 + p2 + p3 +
							   p4) * 1.0;

  printf ("\nA média de notas foi %f", media);
  return 0;
}
