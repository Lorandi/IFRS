#include <stdio.h>
#include <string.h>

int
main ()
{
  float salario, fatorDeAumento;
  char nomeDoCargo[20];
  char codigoFuncao;
  char verifica = 'n';

  printf ("\nDigite o código da função:  ");
  codigoFuncao = getchar ();

  printf ("\nDigite o salário: R$ ");
  scanf ("%f", &salario);
  getchar ();

  switch (codigoFuncao)
    {

    case '1':
      fatorDeAumento = 1.3;
      strcpy (nomeDoCargo, "Escriturário");
      verifica = 's';
      break;
    case '2':
      fatorDeAumento = 1.25;
      strcpy (nomeDoCargo, "Secretário");
      verifica = 's';
      break;
    case '3':
      fatorDeAumento = 1.2;
      strcpy (nomeDoCargo, "Caixa");
      verifica = 's';
      break;
    case '4':
      fatorDeAumento = 1.1;
      strcpy (nomeDoCargo, "Gerente");
      verifica = 's';
      break;
    case '5':
      fatorDeAumento = 1.0;
      strcpy (nomeDoCargo, "Direto");
      verifica = 's';
      break;
    default:
      printf ("\nOpção inválida");
    }

  if (verifica == 's')
    {
      printf ("\nO novo salário do %s é %.2f", nomeDoCargo,
	      salario * fatorDeAumento);
    }
  else
    {
      printf ("\nNão foi possível calcular novo salário");
    }


  return 0;
}

