
#include <stdio.h>
#include <string.h>

int
main ()
{
  int retorno;
  char string1[20], string2[20], string3[20];
  printf ("\nDigite a primeira string: ");
  gets (string1);
  printf ("\nDigite a segunda string: ");
  gets (string2);
  
  retorno = strcmp (string1, string2);

  printf ("\nRetorno: %d", retorno); 
  
  if(retorno == 0){ 
	printf ("\nA primeira string (%s) é igual a segunda string (%s)", string1, string2); 
} else {
	printf ("\nA primera string (%s) e a segunda string (%s) são diferentes", string1, string2); 
}

	printf ("\nTamanho da primeira string: %d", strlen(string1)); 
	printf ("\nTamanho da primeira variável: %d", sizeof(string1));
	printf ("\nTamanho da primeira string: %d", strlen(string2)); 
	printf ("\nTamanho da primeira variável: %d", sizeof(string2));
	
	strcpy (string3, string1);
	
	printf ("\nA terceira string é copia da primeira string: %s", string3);
	
	strcat (string3, string2);

	printf ("\nConcatenadas elas ficam: %s", string3); 

  return 0;
}
