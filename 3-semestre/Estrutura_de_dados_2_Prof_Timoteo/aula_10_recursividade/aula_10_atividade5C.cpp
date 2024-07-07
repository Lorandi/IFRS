/*
Atividade 05 (C)
Qual será a saída gerada das funções dos algoritmos abaixo,
considerando o valor inicial de n=4:
c) func (int n)
{
if (n == 0)
printf(“fim”);
else
{
printf(n);
func(n-1);
printf(n);
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
		printf("%d\n", n);
		func(n-1);
		printf("%d\n", n);
	}
} 

int main() {
	
	func(4);   
	
/*
4
3
2
1
fim
1
2
3
4
*/

    return 0;
}


