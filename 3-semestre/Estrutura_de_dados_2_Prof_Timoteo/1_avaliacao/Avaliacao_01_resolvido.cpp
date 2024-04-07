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
// Fun��o de busca bin�ria
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
        return direita; // Retorna a posi��o se o c�digo for encontrado
    else
        return -1; // Retorna -1 se o c�digo n�o for encontrado
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
//Aloca 1000 poci��es
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
			   //Reserva mais 1000 espa�os de mem�ria			   
			if (num_solicitantes % 999 == 0) {
                solicitantes = (DADOS *)realloc(solicitantes, (num_solicitantes + TAMANHO) * sizeof(DADOS));
	            if (solicitantes == NULL) {
	                printf("Erro ao realocar mem�ria");
	                return 1;
	            }
                // Atualizar o ponteiro para apontar para a nova �rea de mem�ria realocada
                psolicitantes = solicitantes + num_solicitantes;
            }
            psolicitantes++;
			num_solicitantes++;			   
        }
        num_solicitantes--;	//Decrementado em um pois �ltima posicao n�o foi utilizada
        fclose(txt);        
    }  

      
//****************Atividade 03.1**********************      
//****************Grava��o do Arquivo Bin�rio**********************
    FILE *bin;
    if ((bin = fopen("dados.bin", "wb")) == NULL) {
        printf("Erro ao abrir arquivo");
        return 1;
    } else {
        // Escrever os dados no arquivo bin�rio
        fwrite(solicitantes, sizeof(DADOS), num_solicitantes, bin);    
		fclose(bin);    
    }
    
    
//****************Atividade 03.2********************** 
//****************Leitura do Arquivo Bin�rio**********************		
	DADOS *solicitantes_bin = (DADOS *)malloc(num_solicitantes * sizeof(DADOS));
	if (solicitantes_bin == NULL) {
            printf("Erro ao alocar mem�ria para leitura do arquivo bin�rio");
            return 1;
    }        
	DADOS *psolicitantes_bin = solicitantes_bin;
	
	if ((bin = fopen("dados.bin", "rb")) == NULL) {
        printf("Erro ao abrir arquivo bin�rio para leitura");
        return 1;
    }
    
    // Ler os dados do arquivo bin�rio
    int num_lidos = fread(solicitantes_bin, sizeof(DADOS), num_solicitantes, bin);
    if (num_lidos != num_solicitantes) {
        printf("Erro ao ler os dados do arquivo bin�rio");
        return 1;
    }  
	
	while (1) {
        printf("\nEscolha uma op��o:\n");
        printf("1 - Imprimir conte�do do arquivo TXT\n");
        printf("2 - Imprimir conte�do do arquivo BIN\n");
        printf("3 - Realizar busca bin�ria\n");
        printf("4 - Imprimir cada icodigo com seu n�mero de �ndice\n");
        printf("0 - Encerrar programa\n");
        printf("Op��o: ");
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
				// Chamar a fun��o de busca bin�ria
				int numero, posicao, temp;
				int *total_buscas;
				temp = 0;
				total_buscas = &temp;
                printf("Intervalo v�lido para busca bin�ria: [%d, %d]\n", solicitantes_bin[0].icodigo, solicitantes_bin[num_solicitantes - 1].icodigo);
                printf("Informe um n�mero para busca: ");
                scanf("%d", &numero);
                posicao = buscaBinaria(numero, solicitantes_bin, num_solicitantes, total_buscas);
                if (posicao >= 0)
                    printf("Valor %d localizado na posi��o %d ap�s %d buscas\n", numero, posicao, *total_buscas);
                else
                    printf("Valor %d N�O Localizado ap�s %d buscas\n", numero, *total_buscas);
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
                printf("Op��o inv�lida.\n");
                break;
        }
    }
    return 0;
	
system("pause"); 
}

    
