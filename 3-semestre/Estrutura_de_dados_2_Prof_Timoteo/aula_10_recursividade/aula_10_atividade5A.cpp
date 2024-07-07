/*
Qual será a saída gerada das funções dos algoritmos abaixo, considerando
o valor inicial de n=4:
a) func (int n)
{
	if (n == 0)
		printf(“fim”);
	else
	{
		printf(n);
		func(n-1);
	}
} 
*/
#include <stdio.h>

func (int n)
{
	if (n == 0)
		printf("fim");
	else
	{
		printf("%d\n", n);
		func(n-1);
	}
} 

int main() {
	
	func(5);   
	
/*
5
4
3
2
1
fim
*/

    return 0;
}


