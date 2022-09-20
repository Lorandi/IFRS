/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    
    int contador = 0;
    
    for(contador = 1; contador < 20; contador++)
  {
    if(contador % 2 == 0){
        printf("%d ", contador);
    }
  }
    
    return 0;
}
