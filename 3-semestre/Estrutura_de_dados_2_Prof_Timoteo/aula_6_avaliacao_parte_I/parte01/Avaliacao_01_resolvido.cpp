#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAMANHO 1000

//****************Atividade 01**********************
typedef struct dados{
    int icodigo;
    char esfera[16];
    char solicitante[80];
    char situacao[10];
    char data[16];
    char motivo[80];
} DADOS;

//****************Atividade 04.2**********************
// Função de busca binária
int buscaBinaria(int codigo, DADOS *solicitantes, int num_solicitantes, int *total_buscas) {
    int esquerda = 0, direita = num_solicitantes;

    
    while (esquerda <= direita - 1) {
    	(*total_buscas)++; // Atualiza o valor do total de buscas
        int meio = (esquerda + direita) / 2;
        
        if (solicitantes[meio].icodigo == codigo) {
            return meio;
        }        
        
        if (solicitantes[meio].icodigo < codigo){
        	esquerda = meio;
		}else{
        	direita = meio; 	
		} 
    }
    
    if (solicitantes[direita].icodigo == codigo)
        return direita; // Retorna a posição se o código for encontrado
    else
        return -1; // Retorna -1 se o código não for encontrado
}

void imprimir(DADOS *ponteiro, int num_solicitantes) {
    for (int i = 0; i < num_solicitantes; i++) {
        printf("%d - %s - %s - %s - %s - %s\n",ponteiro->icodigo, ponteiro->esfera, ponteiro->solicitante, 
			ponteiro->situacao, ponteiro->data, ponteiro->motivo);   
		ponteiro++;	
	}		 	
}   

void imprimirComIndice(DADOS *ponteiro, int num_solicitantes) {
    for (int i = 0; i < num_solicitantes; i++) {
        printf("[%d] %d \n", i, ponteiro->icodigo);   
		ponteiro++;	
		
		if(i!=0 && i % 8500 == 0 ){
			system("pause");
		}	
	}		 	
} 

main(){
setlocale(LC_ALL, "Portuguese");
FILE *txt;
int opcao;

//****************Atividade 02.1**********************
//Aloca 1000 pocições
DADOS *solicitantes = (DADOS *)malloc(TAMANHO * sizeof(DADOS));
DADOS *psolicitantes = solicitantes;
int num_solicitantes = 0; 

if((txt = fopen("dados.prn","r")) == NULL)
    {
        printf("Erro ao abrir arquivo");
    }else{  	
        while (!feof(txt)) {
            fscanf(txt, "%d %10s %79[^\n] %8s %10s %80[^\n]",&psolicitantes->icodigo, psolicitantes->esfera, psolicitantes->solicitante, 
			   psolicitantes->situacao, psolicitantes->data, psolicitantes->motivo);
			   
			   //****************Atividade 02.2********************** 
			   //Reserva mais 1000 espaços de memória			   
			if (num_solicitantes % 999 == 0) {
                solicitantes = (DADOS *)realloc(solicitantes, (num_solicitantes + TAMANHO) * sizeof(DADOS));
	            if (solicitantes == NULL) {
	                printf("Erro ao realocar memória");
	                return 1;
	            }
                // Atualizar o ponteiro para apontar para a nova área de memória realocada
                psolicitantes = solicitantes + num_solicitantes;
            }
            psolicitantes++;
			num_solicitantes++;			   
        }
        num_solicitantes--;	//Decrementado em um pois última posicao não foi utilizada
        fclose(txt);        
    }  

      
//****************Atividade 03.1**********************      
//****************Gravação do Arquivo Binário**********************
    FILE *bin;
    if ((bin = fopen("dados.bin", "wb")) == NULL) {
        printf("Erro ao abrir arquivo");
        return 1;
    } else {
        // Escrever os dados no arquivo binário
        fwrite(solicitantes, sizeof(DADOS), num_solicitantes, bin);    
		fclose(bin);    
    }
    
    
//****************Atividade 03.2********************** 
//****************Leitura do Arquivo Binário**********************		
	DADOS *solicitantes_bin = (DADOS *)malloc(num_solicitantes * sizeof(DADOS));
	if (solicitantes_bin == NULL) {
            printf("Erro ao alocar memória para leitura do arquivo binário");
            return 1;
    }        
	DADOS *psolicitantes_bin = solicitantes_bin;
	
	if ((bin = fopen("dados.bin", "rb")) == NULL) {
        printf("Erro ao abrir arquivo binário para leitura");
        return 1;
    }
    
    // Ler os dados do arquivo binário
    int num_lidos = fread(solicitantes_bin, sizeof(DADOS), num_solicitantes, bin);
    if (num_lidos != num_solicitantes) {
        printf("Erro ao ler os dados do arquivo binário");
        return 1;
    }  
	
	while (1) {
        printf("\nEscolha uma opção:\n");
        printf("1 - Imprimir conteúdo do arquivo TXT\n");
        printf("2 - Imprimir conteúdo do arquivo BIN\n");
        printf("3 - Realizar busca binária\n");
        printf("4 - Imprimir cada icodigo com seu número de índice\n");
        printf("0 - Encerrar programa\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:            	
            	psolicitantes = solicitantes;
                imprimir(psolicitantes, num_solicitantes);
                break;
            case 2:
            	psolicitantes_bin = solicitantes_bin;
                imprimir(psolicitantes_bin, num_solicitantes);
                break;
            case 3:
            	//****************Atividade 04.1**********************
				// Chamar a função de busca binária
				int numero, posicao, temp;
				int *total_buscas;
				temp = 0;
				total_buscas = &temp;
                printf("Intervalo válido para busca binária: [%d, %d]\n", solicitantes_bin[0].icodigo, solicitantes_bin[num_solicitantes - 1].icodigo);
                printf("Informe um número para busca: ");
                scanf("%d", &numero);
                posicao = buscaBinaria(numero, solicitantes_bin, num_solicitantes, total_buscas);
                if (posicao >= 0)
                    printf("Valor %d localizado na posição %d após %d buscas\n", numero, posicao, *total_buscas);
                else
                    printf("Valor %d NÃO Localizado após %d buscas\n", numero, *total_buscas);
                break;
            case 4:
            psolicitantes = solicitantes;
            imprimirComIndice(psolicitantes, num_solicitantes);
            break;
            case 0:
                free(solicitantes);
                free(solicitantes_bin);
                return 0;
            default:
                printf("Opção inválida.\n");
                break;
        }
    }
    return 0;
	
system("pause"); 
}

    
