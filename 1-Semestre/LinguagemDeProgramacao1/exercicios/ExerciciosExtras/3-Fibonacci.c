
#include <stdio.h>

int main()
{
    int valor = 0, passado = 0, presente = 0, futuro = 1;

  printf ("\nEntre quantos valores quer saber: ");
  scanf ("%d", &valor);
  do{
      
    printf("%d ", presente);
    passado = presente;
    presente = futuro;
    futuro = passado + presente;
    valor--;
  }
  while ( valor > 0);

    return 0;
}

