
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

float totalPedido = 0, totalDia = 0;
char NomeDoLanche[20];
int codigoLanche, quantidade, operacao;
  
void incluirItem(){
        // printf ("\n Digite o código do seu lanche ou zero para sair: ");
        codigoLanche = rand () % 5 + 100;
        // printf ("\n Digite a quantidade: ");
        quantidade = rand () % 5 + 1;
        
        switch (codigoLanche)	{
	    case 100:
	        strcpy (NomeDoLanche, "Cachorro quente");
    	    totalPedido += quantidade * 10.00;
    	    printf ("\n Pedido:  %d unidade(s) de %s", quantidade, NomeDoLanche);
    	    break;
    	
    	case 101:
    	    strcpy (NomeDoLanche, "Bauru Simples");
    	    totalPedido += quantidade * 13.00;
    	      printf ("\n Pedido:  %d unidade(s) de %s", quantidade, NomeDoLanche);
    	    break;
    	
    	case 102:
    	    strcpy (NomeDoLanche, "Bauru c/ ovo");
    	    totalPedido += quantidade * 16.00;
    	    printf ("\n Pedido:  %d unidade(s) de %s", quantidade, NomeDoLanche);
    	    break;
    	    
    	case 103:
    	    strcpy (NomeDoLanche, "Hambuguer");
    	    totalPedido += quantidade * 14.00;
    	    printf ("\n Pedido:  %d unidade(s) de %s", quantidade, NomeDoLanche);
    	    break;
    	    
    	case 104:
    	    strcpy (NomeDoLanche, "Cheeseburguer");
    	    totalPedido += quantidade * 16.00;
    	    printf ("\n Pedido:  %d unidade(s) de %s", quantidade, NomeDoLanche);
    	    break;
    	  
    	case 105:
    	    strcpy (NomeDoLanche, "Refrigerante");
    	    totalPedido += quantidade * 4.00;
    	    printf ("\n Pedido:  %d unidade(s) de %s", quantidade, NomeDoLanche);
    	    break;
    	  
    	default:
    	  printf ("\n Opção inválida");
    	}
    }

void novoPedido(){
    totalPedido = 0;
}

void fecharPedido(){
    printf ("\n Total do pedido R$ %.2f \n", totalPedido);
    totalDia += totalPedido;
    totalPedido = 0;
}

void calculaTotalDia(){
    printf ("\n Resultado total do dia foi R$ %.2f \n", totalDia);
}
    

int main () {
    srand (time (NULL));

 do{
      
    operacao = rand () % 3;
    if(operacao == 0|| operacao == 2){
        operacao = rand () % 3;
    }

	printf ("\n Digite a operação que quer fazer ou zero para sair: ");
// 	scanf ("%d", &operacao);
    printf ("\n 1 - Novo pedido");
    // printf ("\n 2 - Incluir Item e quantidade");
    // printf ("\n 3 - Fechar pedido e Imprimir total");
    printf ("\n 2 - Total do Dia");
    printf ("\n 0 - sair");
    printf ("\n");
    // printf ("\n Valor digitado %d \n", operacao);
    
    switch (operacao){
        case 1:
            printf ("\n Iniciando novo pedido");
            novoPedido();
        // case 2:
            // printf ("\n Incluindo novo item");
            incluirItem();
            int pedirMais = rand () % 5;
            
            while(pedirMais < 3){
                incluirItem();
                pedirMais = rand () % 5;
            }
         
            fecharPedido();
        	break;
        	
        // case 3:
        //     printf ("\n Fechando pedido...\n");
        //     fecharPedido();
        // 	break;
        	
        case 2:
            printf ("\n Calculando o total do dia...");
            calculaTotalDia();
        	break;
        	
        case 0:
            calculaTotalDia();
        	printf ("\n Saindo do programa...");
        	printf ("\n Até logo.");
        	break;
        
    }
    
 }while(operacao != 0);

  return 0;
}



