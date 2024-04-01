#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 20000


int main() {
    clock_t start, end, start_total, end_total;
    double cpu_time_used;
    static float matrix[SIZE][SIZE];    
    //float **matrix;
    int i, j;
    double times = SIZE * SIZE;    
    float *p;
    unsigned long count = 0;   
    int ite = 10;

    /*
    // Alocação dinâmica da matriz
    matrix = (float **)malloc(SIZE * sizeof(float *));
    for (i = 0; i < SIZE; i++) {
        matrix[i] = (float *)malloc(SIZE * sizeof(float));
    }
    */  
    
    // Parte 1:     
    printf("Inicia parte 1\n"); 
	start_total = clock();   
	
	for(int k = 0; k < ite; k++){
		start = clock();
		printf("   %d/%d", k+1, ite);
		for (i = 0; i < SIZE; i++) {
	        for (j = 0; j < SIZE; j++) {
	            matrix[i][j] = 0.0;		
	            //count++;   
	        }
    	}
	end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;	
	printf(": %f segundos\n", cpu_time_used);  
    //printf("Iteracoes:%d\n\n",count);
	//count=0;	
	}    
    end_total = clock();
    cpu_time_used = ((double)(end_total - start_total)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao total parte 1: %f segundos\n\n", cpu_time_used);   

   
    //Parte 2   
	printf("Inicia parte 2\n"); 
    start_total = clock();
    
    count= 0;
	for(int k = 0; k < ite; k++){
		start = clock();
		printf("   %d/%d", k+1, ite);
		p = &matrix[0][0]; 	
    	for(i= 0; i < times; i++){   	
	    	*p=0.0;
	    	p++;
	    	count++;
		}
		end = clock();
		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;	
		printf(": %f segundos\n", cpu_time_used);  
    //printf("Iteracoes:%d\n\n",count);
	//count=0;	
	}	
	end_total = clock();
    cpu_time_used = ((double)(end_total - start_total)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao total parte 1: %f segundos\n\n", cpu_time_used);   
    
    /*
	 // Liberar memória alocada
    for (i = 0; i < SIZE; i++) {
        free(matrix[i]);
    }
    free(matrix);  
	*/     

    return 0;
}

