/*
Atividade 05 (B)
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
		printf("fim\n");
	else
	{
		func(n-1);
		printf("%d\n", n);
	}
} 

int main() {
	
	func(5);   
	
/*
fim
1
2
3
4
5
*/

    return 0;
}


