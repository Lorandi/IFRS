#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO 100

typedef struct Cpessoa
{
	int codigo;
	char nome[20];
	int saldo;
}DADOS;

int main(void)
{
	int condicao = 0;
	DADOS *correntistas = (DADOS*)malloc( TAMANHO * sizeof(DADOS));
	DADOS *pcorrentistas = correntistas;
	int num_correntistas = 0;
	int num_lidos;
	FILE *bin;
	
   
		while (condicao != 4){
			system("cls");
			printf("[1] - Inserir correntista\n");
            printf("[2] - Listar correntistas\n");
            printf("[3] - Fazer uma operacao\n");
            printf("[4] - Sair\n");
		
			printf ("Digite a opcao: ");
  			scanf("%d", &condicao);
	
			switch  (condicao){
			case 1:
				if((bin = fopen("correntistas.bin","a+b")) == NULL){
        			printf("Erro ao abrir arquivo");
       				return 1;
   				}else{    	
			    	num_lidos  = fread(pcorrentistas, sizeof(DADOS), TAMANHO ,bin);    	
			    	num_correntistas += num_lidos;
								
	                printf("\nInforme o codigo do correntista:");
	                scanf("%d", &pcorrentistas[num_correntistas].codigo);
	
	                printf("\nInforme o nome:");
	                scanf("%s", pcorrentistas[num_correntistas].nome);
	
	                printf("\nInforme o saldo :");
	                scanf("%d", &pcorrentistas[num_correntistas].saldo);
	                    
	                printf("\nCorrentista adicionado:\n ");
	                printf(" cod\t| Nome                 | Saldo\n");
					printf("  %d   | %-20s | R$ %d \n", pcorrentistas[num_correntistas].codigo, correntistas[num_correntistas].nome, correntistas[num_correntistas].saldo);					
					
					printf("\n Aperte <Enter> para continuar.\n"); 
					                   
	                fwrite(&pcorrentistas[num_correntistas], sizeof(DADOS), 1, bin);
	                
	                fclose(bin); 
        			
        			pcorrentistas =correntistas;
	                
	                fflush(stdin);
					getchar();
	                break;
	            }

				
			case 2 :				
				if((bin = fopen("correntistas.bin","a+b")) == NULL){
        			printf("Erro ao abrir arquivo");
       				return 1;
   				}else{	 
				   num_correntistas = 0; 
				   	num_lidos  = fread(pcorrentistas, sizeof(DADOS), TAMANHO ,bin);    	
			    	num_correntistas += num_lidos; 	
									
					printf("\nCorrentistas: \n");
									
					if(num_correntistas == 0){
						printf("\n Nao ha correntistas cadastrados.\n");					
					}else{
						printf(" cod\t| Nome                 | Saldo\n");
					}
					
					for (int i = 0; i < num_correntistas; i++) {
						printf("--------------------------------------\n");
					    printf("  %d\t| %-20s | R$ %d \n", pcorrentistas[i].codigo, pcorrentistas[i].nome, pcorrentistas[i].saldo);
	
	    			}
	    			printf("\n Aperte <Enter> para continuar.\n");
					fflush(stdin);
					getchar();
					fclose(bin);
					break;
				}
				
			case 3:
				if((bin = fopen("correntistas.bin","wb")) == NULL){
        			printf("Erro ao abrir arquivo");
       				return 1;
   				}else{	  
				   	num_lidos  = fread(pcorrentistas, sizeof(DADOS), TAMANHO ,bin);    	
			    	num_correntistas += num_lidos; 	
				
					int codigoCorrentista;
					int operacao;
					int valor;
					printf("\nInforme o codigo do correntista: "); 
					scanf("%d", &codigoCorrentista);
					
					for (int i = 0; i < num_correntistas; i++) {
					    if (pcorrentistas[i].codigo == codigoCorrentista) {
					        printf("Correntista escolhido: \n");
					        printf(" cod\t| Nome                 | Saldo\n");
							printf("  %d   | %-20s | R$ %d \n", pcorrentistas[i].codigo, correntistas[i].nome, correntistas[i].saldo);
					        break;
					    }
	    			}
					
					while(1){
						printf("\nOperação Debito [1] ou Credito [2]: ");
						scanf("%d", &operacao);					
						if (operacao == 1) {
	                        printf("\nQuanto quer debitar: ");
	                        scanf("%d", &valor);
	                        valor = valor * (-1);
	                        break;
	                    } else if (operacao == 2) {
	                        printf("\nQuanto quer depositar: ");
	                        scanf("%d", &valor);
	                        break;
	                    } else {
	                            printf("\nOperacao invalida.");
	                    }				
					}					
						
					for (int i = 0; i < num_correntistas; i++) {
					    if (pcorrentistas[i].codigo == codigoCorrentista) {
					        pcorrentistas[i].saldo += valor; 				        	
					        fwrite(pcorrentistas, sizeof(DADOS), num_correntistas, bin);
					        printf("\nOperacao realizada com sucesso.\n ");
					        printf(" cod\t| Nome                 | Saldo\n");
					        printf("  %d   | %-20s | R$ %d \n", pcorrentistas[i].codigo, correntistas[i].nome, correntistas[i].saldo);					        
					        break;
					    }
	    			}
					printf("\n Aperte <Enter> para continuar.\n"); 
					fclose(bin);  
					fflush(stdin);
					getchar(); 		

    				break;
    			}
    			
    			case 4:
                    printf("Saindo do programa.\n");
                    break;

                default:
                    printf("Opcao desconhecida. Tente novamente!");
                    fflush(stdin);
                    getchar();
            }
        }
        fclose(bin); 
        free(correntistas);
    
    return 0;
}

