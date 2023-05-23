#include <stdio.h>
int trocaValor(int a,int b){
	int temp = a;
	a = b;
	b = temp;
	printf ("\nDentro troca valor: a = %d e b = %d", a, b);
}
int trocaReferencia(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	printf ("\nDentro troca referencia: a = %d e b = %d", *a, *b);
}
int main(){
	int a = 0, b = 1;
	printf ("\nInicio: a = %d e b = %d", a, b);
	trocaValor(a, b);
	printf ("\nDepois troca valor: a = %d e b = %d", a, b);
	trocaReferencia(&a, &b);
	printf ("\nDepois troca referencia: a = %d e b = %d", a, b);
	return 0;
}
