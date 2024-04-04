#include <stdio.h>
#include<stdlib.h>

int main(){
	FILE *arq = fopen("teste_fwrite_fread.bin",  "rb");
	if(arq==NULL){
		perror("Erro ao abrir o arquivo");
		return 1;
	}
	int n;
	fread(&n, sizeof(int), 1, arq);
	printf("n = %d\n", n);
	
	int *vet = (int*) malloc(n*sizeof(int));
	fread(vet, sizeof(int),n,arq);
	
	int i;
	for(i=0; i<n; i++){
		printf("%d) %d\n", i, vet[i]);		
	}
	
	free(vet);
	fclose(arq);
	return 0;
}
