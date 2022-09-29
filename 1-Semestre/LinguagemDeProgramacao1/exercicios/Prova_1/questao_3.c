// Algoritmo criado para prova 1 da disciplina Linguagens de Programação 1
// Autor: Rodrigo Lorandi
// Professor: FABIO YOSHIMITSU OKUYAMA
// Porto Alegre, 29/09/2022

#include <stdio.h>

int
main ()
{
    // declaração das variáveis para dados dos vereadores;
    // optou-se por declarar em mais linhas para facilitar visualização e manutenção do código;
    // algumas variáveis foram iniciadas com 0 para ter esse valor caso não recebem outro valor 
    // no decorrer do Algoritmo
    int totalVotos, candidatoA = 0, candidatoB = 0, candidatoC = 0, candidatoD = 0;
    int votosBrancosVereadores = 0, votosNuloVereadores = 0, codigoVotoVereador;
    float votosValidosVereadores = 0;
    
    // declaração das variáveis para dados dos prefeitos;
    // optou-se por declarar em mais linhas pelos motivos já citados;
    // os valores de algumas variáveis já foi explicado acima;
    int candidatoX = 0, candidatoY = 0, candidatoZ = 0; 
    int votosBrancosPrefeitos = 0, votosNuloPrefeitos = 0, codigoVotoPrefeito;
    float votosValidosPrefeitos = 0;
    
    int vereadorMaisVotado, prefeitoMaisVotado;
    
    // Essa variável determina quantos eleitores irão votar
    int eleitores = 7;

    printf("Eleições 2022");
    
    //Lista dos vereadores
    printf ("\n Candidatos Vereadores:");
    printf ("\n 66666 - candidato A");
    printf ("\n 77777 - candidato B");
    printf ("\n 88888 - candidato C");
    printf ("\n 99999 - candidato D");
    printf ("\n 111 - Voto em Branco");
    printf ("\n Outro valor - Voto Nulo");
    printf("\n");
    
    //Lista dos prefeitos
    printf ("\n Candidatos Prefeitos:"); 
	printf ("\n 99 - candidato X");
    printf ("\n 88 - candidato Y");
    printf ("\n 77 - candidato Z");
    printf ("\n 111 - Voto em Branco");
    printf ("\n Outro valor - Voto Nulo");
    printf ("\n");
    
    //Esse for irá iterar de acordo com a quantidade de eleirores escolhida;
    for (int i = 1; i <= eleitores; i++){
        printf("\nEleitor %d" , i);

        printf("\n Digite o número do seu vereador: ");
        scanf ("%d", &codigoVotoVereador);
        
        //Esse switch contabiliza votos para vereador
        switch (codigoVotoVereador){
	        case 66666:
        	candidatoA++;
        	votosValidosVereadores++;
	        printf ("\n Voto no Candidato A.");
	        break;
	        
	        case 77777:
        	candidatoB++;
        	votosValidosVereadores++;
	        printf ("\n Voto no Candidato B.");
	        break;
	        
	        case 88888:
        	candidatoC++;
        	votosValidosVereadores++;
	        printf ("\n Voto no Candidato C.");
	        break;
	        
	        case 99999:
        	candidatoD++;
        	votosValidosVereadores++;
	        printf ("\n Voto no Candidato D.");
	        break;
	        
	        case 111:
        	votosBrancosVereadores++;
        	votosValidosVereadores++;
	        printf ("\n Voto em branco para vereador.");
	        break;
	        
	        default:
	        votosNuloVereadores++;
	        printf ("\n Voto nulo para vereador.");
        }
        
         printf ("\n");
	        
	    
        printf("\n Digite o número do seu prefeito: ");
        scanf ("%d", &codigoVotoPrefeito);
        
        //Esse switch contabiliza votos para prefeito
        switch (codigoVotoPrefeito){
	        case 99:
        	candidatoX++;
        	votosValidosPrefeitos++;
	        printf ("\n Voto no Candidato X.");
	        break;
	        
	        case 88:
        	candidatoY++;
        	votosValidosPrefeitos++;
	        printf ("\n Voto no Candidato Y.");
	        break;
	        
	        case 77:
        	candidatoZ++;
        	votosValidosPrefeitos++;
	        printf ("\n Voto no Candidato Z.");
	        break;
	        
	        case 111:
        	votosBrancosPrefeitos++;
        	votosValidosPrefeitos++;
	        printf ("\n Voto em branco para prefeito.");
	        break;
	        
	        default:
	        votosNuloPrefeitos++;
	        printf ("\n Voto nulo para prefeito.");
        }
        
        printf ("\n");
    }
    printf("\n  \nResultado para Vereadores");
    printf ("\n Candidato A teve %d votos sendo %.2f%% dos votos válidos", candidatoA, 100*candidatoA/votosValidosVereadores);
    printf ("\n Candidato B teve %d votos sendo %.2f%% dos votos válidos", candidatoB, 100*candidatoB/votosValidosVereadores);
    printf ("\n Candidato C teve %d votos sendo %.2f%% dos votos válidos", candidatoC, 100*candidatoC/votosValidosVereadores);
    printf ("\n Candidato D teve %d votos sendo %.2f%% dos votos válidos", candidatoD, 100*candidatoD/votosValidosVereadores);
    printf ("\n O total de votos brancos para vereadores foram %d.", votosBrancosVereadores);
    printf ("\n O total de votos nulos para vereadores foram %d.", votosNuloVereadores);
    
    
    printf("\n \nResultado para Prefeitura");
    printf ("\n Candidato X teve %d votos sendo %.2f%% dos votos válidos", candidatoX, 100*candidatoX/votosValidosPrefeitos);
    printf ("\n Candidato Y teve %d votos sendo %.2f%% dos votos válidos", candidatoY, 100*candidatoY/votosValidosPrefeitos);
    printf ("\n Candidato Z teve %d votos sendo %.2f%% dos votos válidos", candidatoZ, 100*candidatoZ/votosValidosPrefeitos);
    printf ("\n O total de votos brancos para Prefeitura foram %d.", votosBrancosPrefeitos);
    printf ("\n O total de votos nulos para Prefeitura foram %d.", votosNuloPrefeitos);
    
    printf("\n \nProgramador: Rodrigo Lorandi");

      return 0;
    }



