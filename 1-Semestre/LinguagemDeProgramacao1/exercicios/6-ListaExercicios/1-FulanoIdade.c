
#include <stdio.h>
#include <string.h>

int
main ()
{
  int idade;
  char string1[20];
  
  printf ("\nDigite seu nome: ");
  gets (string1);
  
  printf ("\nDigite sua idade: ");
  scanf("%d", &idade);
  
  if(idade < 18){
      printf ("\n %s é menor de idade", string1);
  }else{
      printf ("\n %s é maior de idade", string1);
  }
  return 0;
}
