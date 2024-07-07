#include <stdio.h>

int somatorio (int x){ 
if (x ==1)
 return (1);
else
 return  x + somatorio(x-1);
 }


main () {	

 printf("%d ",somatorio(5));	
 	
}
