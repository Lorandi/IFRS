

#include <stdio.h>

int main(int argc, char** argv) {

  //Declara a variável uc como sendo 8 bits puro (sem sinal).
  unsigned char uc;
 
  //Alguns exemplos de equivalência de valores:
  //Binário  - decimal - hexa - octal - catactere
  //01100001 =  97     = 61h  = 141o  = 'a'
  //01100010 =  98     = 62h  = 142o  = 'b'
  //01100011 =  99     = 63h  = 143o  = 'c'
  //...
  //01000001 =  65     = 41h  = 101o  = 'A'
    
  //Formatos para a função printf():
  //%d = decimal com sinal.
  //%u = decimal sem sinal.
  //%x = hexadecimal.
  //%o = octal.
  //%c = caractere.

  //Literal decimal
  uc = 65;
  printf("uc = %u = %Xh = %oo = %c\n", uc, uc, uc, uc);

  //Literal hexadecimal: iniciar com 0x
  uc = 0x61;
  printf("uc = %u = %Xh = %oo = %c\n", uc, uc, uc, uc);
  
  //Literal octal: iniciar com 0
  uc = 0141;
  printf("uc = %u = %Xh = %oo = %c\n", uc, uc, uc, uc);
  
  //Literal caractere: colocar entre apóstrofo (aspas simples)
  uc = 'a';
  printf("uc = %u = %Xh = %oo = %c\n", uc, uc, uc, uc);
    
  printf("pause");
}