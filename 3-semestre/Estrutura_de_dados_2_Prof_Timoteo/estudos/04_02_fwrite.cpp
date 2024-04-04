#include <stdio.h>
#include<string.h>

int main(){
	FILE *arq = fopen("teste_fwrite_fread.bin",  "wb");
	if(arq==NULL){
		perror("Erro ao abrir o arquivo");
		return 1;
	}
	
	int vet[]={1,2,3,4,5};
	int n = 5;
	
	fwrite(&n, sizeof(int), 1, arq);
	fwrite(&vet[0], sizeof(int), n, arq);
	
	fclose(arq);
	return 0;
}
