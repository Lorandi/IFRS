#include<stdio.h>

int main(){
int x , *px; //cria a variável x e o ponteiro px
x = 1; //atribui 1 a variavel x
px = &x; //armazena o endereço de x em px
printf("01. x= %d\n", x); //mostra conteúdo de x
printf("02. px= %p\n", px); //mostra conteúdo de px (endereço de x)
printf("03. *px+1= %d\n", *px+1); //apresenta o conteúdo apontado por px+1
printf("04. px= %p\n", px); //mostra o conteúdo de px (inalterado)
printf("05. *px= %d\n", *px); //mostra o valor apontado pelo ponteiro (x)
printf("06. *px+=1= %d\n", *px+=1); //acrescenta 1 à variável apontada pelo ponteiro px
printf("07. px= %p\n", px); //mostra o endereço armazenado por px (inalterado)
printf("08. (*px)++= %d\n", (*px)++);//mostra valor apontado por px; depois de mostrar, incrementa em uma unidade;
printf("09. px= %p\n", px); //mostra o valor armazendo em px (inalterado)
printf("10. *(px++)= %d\n", *(px++)); //incrementa o valor de px e mostra o conteúdo apontado;
printf("11. px= %p\n", px); //mostra o valor armazenado em px (mudou!)
printf("12. *px++= %d\n", *px++); //incrementa o valor de px e mostra o conteúdo apontado; (mesmo que 10)
printf("13. px= %p\n", px); //mostra o valor armazenado em px (mudou de novo!)
}
