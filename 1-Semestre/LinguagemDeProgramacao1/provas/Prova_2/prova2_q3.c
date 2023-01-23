// Prova de Linguagem de Programação I
// Curso Sistemas para Internet - 01/12/2022
// Prof. Fabio Okuyama

// Autor: Rodrigo Lorandi
// Questão 3

#include <stdio.h>

int
main ()
{
    // declaração das variáveis para dados dos vereadores;
    // optou-se por declarar em mais linhas para facilitar visualização e manutenção do código;
    // algumas variáveis foram iniciadas com 0 para ter esse valor caso não recebem outro valor 
    // no decorrer do Algoritmo 
    int totalVotos, candidatoA = 0, candidatoB = 0, candidatoC = 0, candidatoD = 0, candidatoE = 0;
    int votosBrancosVereadores = 0, votosNuloVereadores = 0, codigoVotoVereador = 0; 
    
    
    // declaração das variáveis para dados dos prefeitos;
    int candidatoX = 0, candidatoY = 0, candidatoZ = 0; 
    int votosBrancosPrefeitos = 0, votosNuloPrefeitos = 0, codigoVotoPrefeito;
    
    //variável utilizada para caracterizar o eleitor nas iterações da votação
    int eleitor = 1;
    
    printf("Eleições 2022");
    
    //Lista dos vereadores
    printf ("\n Candidatos Vereadores:");
    printf ("\n 91111 - candidato A");
    printf ("\n 91112 - candidato B");
    printf ("\n 91113 - candidato C");
    printf ("\n 91114 - candidato D");
    printf ("\n 91115 - candidato E");
    printf ("\n 77777 - Voto em Branco");
    printf ("\n Outro valor - Voto Nulo");
    printf("\n");
    
    //Lista dos prefeitos
    printf ("\n Candidatos Prefeitos:"); 
	printf ("\n 91 - candidato X");
    printf ("\n 92 - candidato Y");
    printf ("\n 93 - candidato Z");
    printf ("\n 77 - Voto em Branco");
    printf ("\n Outro valor - Voto Nulo");
    printf ("\n");
    
    //Esse while irá iterar de enquanto o codigoVotoVereador for diferente de 12345;
    while(codigoVotoVereador != 12345){
        printf("\nEleitor %d" , eleitor++);

        printf("\n Digite o número do seu vereador: ");
        scanf ("%d", &codigoVotoVereador);
        
        //Esse switch contabiliza votos para vereador
        switch (codigoVotoVereador){
	        case 91111:
        	candidatoA++;
	        printf ("\n Voto no Candidato A.");
	        break;
	        
	        case 91112:
        	candidatoB++;
	        printf ("\n Voto no Candidato B.");
	        break;
	        
	        case 91113:
        	candidatoC++;
	        printf ("\n Voto no Candidato C.");
	        break;
	        
	        case 91114:
        	candidatoD++;
	        printf ("\n Voto no Candidato D.");
	        break;
	        
	        case 91115:
        	candidatoE++;
	        printf ("\n Voto no Candidato E.");
	        break;
	        
	        case 77777:
        	votosBrancosVereadores++;
	        printf ("\n Voto em branco para vereador.");
	        break;
	        
	        case 12345:
	        break;
	        
	        default:
	        votosNuloVereadores++;
	        printf ("\n Voto nulo para vereador.");
        }
        
         printf ("\n");
	        
	    if(codigoVotoVereador != 12345){
    	    printf("\n Digite o número do seu prefeito: ");
            scanf ("%d", &codigoVotoPrefeito);
            
            //Esse switch contabiliza votos para prefeito
            switch (codigoVotoPrefeito){
    	        case 91:
            	candidatoX++;
    	        printf ("\n Voto no Candidato X.");
    	        break;
    	        
    	        case 92:
            	candidatoY++;
    	        printf ("\n Voto no Candidato Y.");
    	        break;
    	        
    	        case 93:
            	candidatoZ++;
    	        printf ("\n Voto no Candidato Z.");
    	        break;
    	        
    	        case 77:
            	votosBrancosPrefeitos++;
    	        printf ("\n Voto em branco para prefeito.");
    	        break;
    	        
    	        default:
    	        votosNuloPrefeitos++;
    	        printf ("\n Voto nulo para prefeito.");
            }
	        
	    }
        printf ("\n");
    }
    
    printf ("\n\n **** VOTAÇÃO ENCERRADA ****");
    
    printf("\n  \nResultado para Vereadores");
    printf ("\n Candidato A teve %d votos.", candidatoA);
    printf ("\n Candidato B teve %d votos.", candidatoB);
    printf ("\n Candidato C teve %d votos.", candidatoC);
    printf ("\n Candidato D teve %d votos.", candidatoD);
    printf ("\n Candidato E teve %d votos.", candidatoE);
    printf ("\n O total de votos brancos para vereadores foram %d.", votosBrancosVereadores);
    printf ("\n O total de votos nulos para vereadores foram %d.", votosNuloVereadores);
    
    
    printf("\n \nResultado para Prefeitura");
    printf ("\n Candidato X teve %d votos.", candidatoX);
    printf ("\n Candidato Y teve %d votos.", candidatoY);
    printf ("\n Candidato Z teve %d votos.", candidatoZ);
    printf ("\n O total de votos brancos para Prefeitura foram %d.", votosBrancosPrefeitos);
    printf ("\n O total de votos nulos para Prefeitura foram %d.", votosNuloPrefeitos);
    
    printf("\n");
    
    if(candidatoX > candidatoY && candidatoX > candidatoZ){
        printf("O vencedor para prefeitura foi o candidatoX com %d votos", candidatoX);
    }
    
    if(candidatoY > candidatoX && candidatoY > candidatoZ){
        printf("O vencedor para prefeitura foi o candidatoY com %d votos", candidatoY);
    } 
    
    if(candidatoZ > candidatoY && candidatoZ > candidatoX){
        printf("O vencedor para prefeitura foi o candidatoZ com %d votos", candidatoZ);
    } 
    
    printf("\n \nProgramador: Rodrigo Lorandi");

      return 0;
    }



