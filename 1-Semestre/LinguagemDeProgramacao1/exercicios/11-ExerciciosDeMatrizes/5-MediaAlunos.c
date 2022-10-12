#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

double randf( double min, double max )
{
    return min + (rand() / ( RAND_MAX / ( max - min) ) ) ;  
}

int main()
{
    int n = 100, aprovados=0, reprovados=0;
    float notas[n], media = 0, mediaAprovados = 0, mediaReprovados = 0, maiorNota = 0, menorNota = 101, somaTodasNotas = 0;
    srand(time(NULL));
    
    for (int i = 0; i < n; i++){
        // notas[i] = rand() % 11;
        notas[i] = randf(0.00, 10.00);
        
        printf("%.2f ", notas[i]);
        
        somaTodasNotas += notas[i];
        
        if(notas[i] >= 7){
            mediaAprovados +=notas[i];
            aprovados++;
        }else{
            mediaReprovados +=notas[i];
            reprovados++;
        }
        
        if(notas[i] > maiorNota ){
            maiorNota = notas[i];
        }
        
         if(notas[i] < menorNota ){
            menorNota = notas[i];
        }

    }
    
    printf("\nMédia da turma foi %.2f ", somaTodasNotas/n);
    printf("\nAprovados %d e sua média foi %.2f", aprovados, mediaAprovados/aprovados );
    printf("\nReprovados %d e sua média foi %.2f", reprovados, mediaReprovados/reprovados);
    printf("\nA maior nota foi %.2f ", maiorNota);
    printf("\nA menor nota foi %.2f ", menorNota);

    return 0;
}

