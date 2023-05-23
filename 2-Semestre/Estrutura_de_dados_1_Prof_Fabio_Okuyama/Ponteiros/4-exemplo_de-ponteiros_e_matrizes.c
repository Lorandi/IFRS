#include <stdio.h>
int main(){
	int vet[10] = {0,1,2,3,4,5,6,7,8,9};
	int *ptr;
	ptr = vet;
	
	printf ("%p\n", &ptr);
	printf ("%p\n", ptr);
	printf ("%p\n", &ptr[0]);
	printf ("%p\n", &vet[0]);
	printf ("%p\n\n", vet);


	int i;
	for(i = 0; i < 10; i++){
		printf ("%d\n", *(ptr+i));
		printf ("%d\n", ptr[i]);
		printf ("%d\n\n", vet[i]);
	}
	return 0;
}
