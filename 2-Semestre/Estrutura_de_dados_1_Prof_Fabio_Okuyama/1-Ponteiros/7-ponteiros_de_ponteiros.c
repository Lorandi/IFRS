
#include <stdio.h>


int main(){
    int x, *p, **q;
    x = 10;
    p = &x;
    q = &p;
    printf("O endereço do ponteiro q é = %p\n",q);
    printf("O valor que o ponteiro q guarda é = %p\n",*q);
    printf("que deve ser igual ao endereço de x (&x) = %p\n", &x);
    printf("%d é o valor que o endreço guardado no ponteiro q guarda \n",**q);
}

