// Algoritmo criado para prova 1 da disciplina Linguagens de Programação 1
// Autor: Rodrigo Lorandi
// Professor: FABIO YOSHIMITSU OKUYAMA
// Porto Alegre, 29/09/2022

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main ()
{
    // algumas variáveis foram inciadas com zero para manter esse valor em memória
    // caso o valor da variável não mude durante o algorítimo;
  int numero, quantosImpares = 0, quantosPares = 0, maiorPar = 0, iteracoes = 0;
  
  int maxAleatorio = 100;
  
  float somaImpares = 0.0;
  
  // estabelece que a seed do randon será diferente cada vez que rodar o código
   srand(time(NULL));//

    //se optou pelo do-while para que rode pelo menos uma vez o programa.
    do{
        iteracoes++;
        printf ("\nDigite um número inteiro positivo: ");
        // scanf ("%d", &numero); 
        
        // geracao numeros aleatorios
        numero = rand() % maxAleatorio;
        printf("%d \n", numero);
        
        if (numero != 0){
            
            //verifica se é par
            if (numero % 2 == 0){
                quantosPares++;
                printf ("Tabuada do nº:%d:", numero);
	            for (int i = 1; i <= 10; i++){
		            printf ("\n %d x %d = %d ", numero, i, numero * i);
		        }
		        
		        //Atualiza o maior número par
		        if (numero > maiorPar){
		            maiorPar = numero;
		        }
		    // entrará nesse else se for impar
	        }else{
	            printf ("Divisores do nº:%d:", numero);
	            for (int i = 1; i < numero; i++){
	                if(numero % i == 0){
	                printf ("%d, ", i);
	                }
		        }
		        quantosImpares++;
		        somaImpares += numero;
		    }
	   }
    }while (numero != 0 && iteracoes < (maxAleatorio * 2) );
    
    printf("\n");
    printf("\n Total de iteracoes: %d ", iteracoes);
    printf("\n Total de pares: %d ", quantosPares);
    printf("\n Total de impares: %d ", quantosImpares);
    printf("\n");

    // Esse if-else garante que será dado algum retorno sobre os impares
    if(quantosImpares > 0){
        printf ("\nMédia dos impares foi: %.2f", somaImpares / quantosImpares);
    }
    
    // Esse if-else garante que será dado algum retorno sobre os pares
    if(maiorPar > 0){
        printf("\nO maior número par digitado foi nº:%d", maiorPar);
    }
    
    printf("\n");
    
    //Adicionado pois estava no modelo a ser seguido da prova
    printf("\nBye-bye\n");

    printf ("\nProgramador: Rodrigo Lorandi");

  return 0;
}




