#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(){
	int i = 10;
}

int main(){
	
	char *palavra = (char*)"Amigo";
	printf("%s", palavra);
	
	/*
	int num[5]= {5,4,3,2,1}, tam=5;
  	int i, j, min;
	for (i = 0; i < (tam-1); i++) {
	    min = i;
		for (j = (i+1); j < tam; j++) {
		   	if(num[j] < num[min]) {
		    	min = j;
			}
		}
		if (i != min) {
	    	int swap = num[i];
		    num[i] = num[min];
		   num[min] = swap;
		}
	}
	for (int q=0; q<5; q++){
    	printf("%d \n",num[q]);
    }
    system("pause");
    */
	
	
	/*
	int x[10]= {10,11,21,31,41,51,61,71,81,91};
	int *p, a, *i;
	i=x;
	*i = 10;
	a = 10;
	i = &a;
	p=&a;
	a = 30;
	p = x;
	
	p=(int*) malloc(a*sizeof(int));
	
	if(!p){
		printf("Erro memoria insuficiente");
		exit(1);
	}
	
	printf("%d\n", *i);
	printf("%d\n", *p);
	*/	
	
	/*
	int i =20;
	func();
	
	printf("i = %d ", i);
	
	if (i >= 20){
		i = 30;
		func();
		printf("i = %d ", &i);		
	}
	*/	
	
	/*
	int x[10]= {10,11,21,31,41,51,61,71,81,91};
	int *p, a, *i;
	i=&a;
	p=&a;
	a = 30;
	printf("%d\n", p[0]);
	printf("%d\n", *p);
	printf("%d\n", *(p+9));

	p=x;
	
	printf("%d\n", p[0]);
	printf("%d\n", *p);
	printf("%d\n", *(p+9));
	printf(" \n");
	printf("%d\n", (*p+9));
	printf("%d\n", p[0]);
	printf("%d\n", *p);
	printf("%d\n", (*p+9));
	*/	
}
