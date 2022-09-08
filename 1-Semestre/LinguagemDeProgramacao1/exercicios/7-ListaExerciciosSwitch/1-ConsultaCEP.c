
#include <stdio.h>

int
main ()
{

  char cep;

  printf ("\nCENTRAL DE ENTRGAS - CEPs");

  printf ("\nDigite o primeiro dígito do CEP: ");
  cep = getchar ();

  printf ("Enviar para: ");
  switch (cep)
    {
    case '0':
    case '1':
    case '2':
    case '3':
      printf ("\nSudeste (SP, RJ, ES, MG)");
      break;
    case '4':
      printf ("\nRegião 4 (BA, SE)");
      break;
    case '5':
      printf ("\nRegião 5 (PE, AL, PB, RN)");
      break;
    case '6':
      printf ("\nRegião 6 (CE, PI, MA, PA, AP, AM, RR, AC )");
      break;
    case '7':
      printf ("\nRegião 7 (DF, GO, TO, MT, RO, MS)");
      break;
    case '8':
    case '9':
      printf ("\nSul (PR, SC, RS)");
      break;
    default:
      printf ("\nOpção Inválida");
    }

  return 0;
}

