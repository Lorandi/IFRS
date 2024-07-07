/*
Atividade 05 (D)
Qual será a saída gerada das funções dos algoritmos abaixo,
considerando o valor inicial de n=4:
d) func (int n)
{
if (n == 0)
printf(“fim”);
else
{
func(n-1);
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
		func(n-1);
	}
} 

int main() {
	
	func(4);   
	
/*
fim
1
fim
2
fim
1
fim
3
fim
1
fim
2
fim
1
fim
4
fim
1
fim
2
fim
1
fim
3
fim
1
fim
2
fim
*/

    return 0;
}


