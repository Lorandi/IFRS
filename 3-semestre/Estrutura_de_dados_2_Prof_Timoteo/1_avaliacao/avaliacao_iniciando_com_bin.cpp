#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAMANHO 1000

typedef struct dados {
    int icodigo;
    char esfera[16];
    char solicitante[80];
    char situacao[10];
    char data[16];
    char motivo[80];
} DADOS;

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
        printf("%d - %s - %s - %s - %s - %s\n", ponteiro->icodigo, ponteiro->esfera, ponteiro->solicitante, 
            ponteiro->situacao, ponteiro->data, ponteiro->motivo);   
        ponteiro++;    
    }           
}   

int main() {
    setlocale(LC_ALL, "Portuguese");
    FILE *bin;
    int opcao;

    DADOS *solicitantes = NULL;
    int num_solicitantes = 0; 

    if ((bin = fopen("dados.bin", "rb")) == NULL) {
        printf("Erro ao abrir arquivo binário para leitura");
        return 1;
    } else {
        // Ler os dados do arquivo binário
        while (!feof(bin)) {
            solicitantes = (DADOS *)realloc(solicitantes, (num_solicitantes + TAMANHO) * sizeof(DADOS));
            if (solicitantes == NULL) {
                printf("Erro ao realocar memória");
                return 1;
            }
            int num_lidos = fread(&solicitantes[num_solicitantes], sizeof(DADOS), TAMANHO, bin);
            if (num_lidos <= 0) {
                break;
      		}
            
            num_solicitantes += num_lidos;
        }
        fclose(bin);        
    } 
    
    // Criar o arquivo de texto      
    FILE *txt;
      
    if ((txt = fopen("dados.txt", "w")) == NULL) {
        printf("Erro ao criar arquivo de texto");
        return 1;
    } else {
        // Escrever os dados no arquivo de texto
        for (int i = 0; i < num_solicitantes; i++) {
            fprintf(txt, "%d %s %s %s %s %s\n", solicitantes[i].icodigo, solicitantes[i].esfera, solicitantes[i].solicitante, 
                solicitantes[i].situacao, solicitantes[i].data, solicitantes[i].motivo);   
        }
        fclose(txt);    
    }

    while (1) {
        printf("\nEscolha uma opção:\n");
        printf("1 - Imprimir conteúdo do arquivo BIN\n");
        printf("2 - Realizar busca binária\n");
        printf("0 - Encerrar programa\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                imprimir(solicitantes, num_solicitantes);
                break;
            case 2:
               	int numero, posicao, temp;
				int *total_buscas;
				temp = 0;
				total_buscas = &temp;              
				printf("Intervalo válido para busca binária: [%d, %d]\n", solicitantes[0].icodigo, solicitantes[num_solicitantes - 1].icodigo); 
                printf("Informe um número para busca: ");
                scanf("%d", &numero);
                posicao = buscaBinaria(numero, solicitantes, num_solicitantes, total_buscas);
                if (posicao >= 0)
                    printf("Valor %d localizado na posição %d após %d buscas\n", numero, posicao, *total_buscas);
                else
                    printf("Valor %d NÃO Localizado após %d buscas\n", numero, *total_buscas);
                break;
            case 0:
                free(solicitantes);
                return 0;
            default:
                printf("Opção inválida.\n");
                break;
        }
    }

    return 0;
}

