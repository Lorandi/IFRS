#include <stdio.h>
#include <stdlib.h>

#define tamanho 1730000000


unsigned long int posicoes_alocadas = 0;
double *posicao0;

int total_alocado(unsigned long int size){
	printf("\nTentativa com: %lu", size);
	
		double *a;
		a = (double *)malloc(sizeof(double) * size);
		
				
		if(a==NULL){
			printf(" Falhou");
			free(a);
		}else
		{	
			posicoes_alocadas = size;
			for(unsigned long int i = 0; i < size; i++){
			a[i]=0;
			}
			posicao0 = a;			

			free(a);
			printf(" Passou!");
			
			total_alocado(size *1.1);
		}
		return 1;
}

int main(){
	
	total_alocado(tamanho);		
	unsigned long long bytesReservados = (long long)(sizeof(double)*posicoes_alocadas);
	double megabytesReservados = (double)bytesReservados / (1024 * 1024);
	double gigabytesReservados = (double)bytesReservados / (1024 * 1024 * 1024);
	
	printf("\n\n\na) Quantos posicoes de memoria voce conseguiu ocupar?");	
	printf("\n Posicoes ocupadas %lu", posicoes_alocadas);
	
	printf("\n\nb) Quantos MB ou GB o seu programa reservou? ");
	printf("\nBytes reservados: %lld bytes", bytesReservados );
	printf("\nMegabytes reservados: %.2f Mb", megabytesReservados );
	printf("\nGigabytes reservados: %.2f Gb", gigabytesReservados );
	
	printf("\n\nc) Quais sao os cinco primeiros enderecos de memoria? ");
	for(int i = 0; i < 5; i++){
		printf("\nPosicao %d: %p",  i, posicao0+i);
	}
	
	printf("\n\nd) O deslocamento de cada endereço é de quantos bytes? Explique. ");
	printf("\nPor se tratar de um double, o deslocamento é de 8 bytes, apesar de");
	printf("\nparecer por vezes 8 e por vezes 2 conforme os 5 primeiros enderecos de memoria");


		
	return (0);
}
