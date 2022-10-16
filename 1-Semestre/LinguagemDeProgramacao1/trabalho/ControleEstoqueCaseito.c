// Algoritmo criado naa disciplina Linguagens de Programação 1
// Autor: Rodrigo Lorandi
// Professor: FABIO YOSHIMITSU OKUYAMA
// Porto Alegre, 16/10/2022

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char produtos[7][10] = {"arroz", "feijão", "pão", "macarrão", "leite", "banana", "maçã"};
int estoqueMaximo[7] = {5,5,5,5,5,5,5};
int estoqueMinimo[7] = {3,3,3,3,3,3,3};
int estoqueAtual[7] = {3,3,3,3,3,3,3};

//variável para contralar o modo automático do algoritmo
int automatico = 0;

//variável criada para definir o tempo entre execução de funções no modo automático
char tempo[9]="sleep 01";

void mostrarEstoqueAtual(){
    printf("\nEstoque atual:");
    for(int i = 0; i < 7; i++ ){
        printf("\n %s: %d ", produtos[i],estoqueAtual[i]);
    }
    printf("\n");
}

void mostrarEstoqueMinimo(){
    printf("\nEstoque mínimo:");
    for(int i = 0; i < 7; i++ ){
        printf("\n %s: %d ", produtos[i],estoqueMinimo[i]);
    }
    printf("\n");
}

void mostrarEstoqueMaximo(){
    printf("\nEstoque máximo:");
    for(int i = 0; i < 7; i++ ){
        printf("\n %s: %d ", produtos[i],estoqueMaximo[i]);
    }
    printf("\n");
}

void completarEstoqueAtualComMaximo(){
    printf("\nCompletando estoque com máximo de produtos:");
    int adicionar = 0;
    for(int i = 0; i < 7; i++ ){
        if(estoqueMaximo[i] > estoqueAtual [i]){
            adicionar++;
            int j = estoqueMaximo[i] - estoqueAtual [i];
            printf("\n %d - Adicionando %d unidadades de %s ao estoque atual.", adicionar, j, produtos[i]);
            estoqueAtual [i] = estoqueMaximo[i];
        }
    }
    if(adicionar == 0){
        printf("\nNão há produtos para serem adicionados.");
    }
    printf("\n");
}

void listaParaCompras(){
    int comprar = 0;
    printf("\nLista de compras:");
    for(int i = 0; i < 7; i++ ){
        if(estoqueMinimo[i] > estoqueAtual [i]){
            comprar++;
            int j = estoqueMinimo[i] - estoqueAtual [i];
            printf("\n %d - É necessário comprar %d unidadades de %s.",comprar, j, produtos[i]);
            
        }
    }
    
    if(comprar == 0){
        printf("\nNão há produtos para serem comprados.");
    }
    printf("\n");
    
}

void comprarProdutosDaLista(){
    int comprar = 0;
    printf("\nComprando produtos da lista:");
    for(int i = 0; i < 7; i++ ){
        if(estoqueMinimo[i] > estoqueAtual [i]){
            comprar++;
            int j = estoqueMinimo[i] - estoqueAtual [i];
            printf("\n %d - Comprando %d unidadades de %s.", comprar, j, produtos[i]);
            estoqueAtual [i] = estoqueMinimo[i];
        }
    }
     if(comprar == 0){
        printf("\nNão há produtos para serem comprados.");
    }
    printf("\n");
}

void subtrairProduto(int produto){
    if(estoqueAtual[produto]>0){
        estoqueAtual[produto]--;
    }else{
        printf("\nSem estoque suficiente de %s", produtos[produto]);
        printf("\n");
    }
}

void pegarProdutoDoEstoque(){
    int produto;
    int produtoEncontrado = 0;
    char continuar[10] = "sim";

    while(strcmp(continuar,"sim") == 0){
        printf("\nQual produto gostaria de pegar?");
        for(int i = 0; i < 7; i++){
            printf ("\n %d - %s", i , produtos[i]);
        }
        
        printf("\nDigite o index do produto: ");
        
        if(automatico == 0){
            scanf("%d",&produto);
            printf("\n\nProduto escolhido: %s\n", produtos[produto]);
        getchar();
        }else{
            produto = rand() % 7;
            printf("\n\nProduto escolhido: %s\n", produtos[produto]);
            system(tempo);
        }
     
        switch (produto){
            case 0: subtrairProduto(0); break;
            case 1: subtrairProduto(1); break;
            case 2: subtrairProduto(2); break;
            case 3: subtrairProduto(3); break;
            case 4: subtrairProduto(4); break;
            case 5: subtrairProduto(5); break;
            case 6: subtrairProduto(6); break;
            default: printf("\nProduto não encontrado.\n");
        }

        mostrarEstoqueAtual();
        
        do{
            printf("\nGostaria de pegar outro produto?");
            printf("\nEscreva sim ou não: ");
       
            if(automatico == 0){
                fgets(continuar, 10, stdin);
                continuar[strcspn(continuar, "\n")] = 0;
                 if(strcmp(continuar,"sim") != 0 && strcmp(continuar,"não") != 0){
                    printf("\nValor inválido!\n");
            }
            }else{
                int i = 0; 
                i = rand() % 2;
                if(i == 0){
                    strcpy (continuar, "não");
                }else{
                    strcpy (continuar, "sim");
                }
                printf("%s", continuar);
                system(tempo);
            }
            
        }while(strcmp(continuar,"sim") != 0 && strcmp(continuar,"não") != 0);
    }
   
}

void menuPrincipal(){
    int operacao;
        do{
        printf("\nMenu Principal: ");
        printf("\n 1 - Mostrar estoque atual.");
        printf("\n 2 - Mostrar estoque mínimo.");
        printf("\n 3 - Mostrar estoque máximo.");
        printf("\n 4 - Mostrar lista de compras.");
        printf("\n 5 - Comprar produtos da lista.");
        printf("\n 6 - Completar estoque.");
        printf("\n 7 - Pegar produto do estoque.");
        printf("\n 0 - Sair");
        
        printf("\nEscolha uma operação: ");
        
        if (automatico == 0){
            scanf("%d",&operacao);
            getchar();
        }else{
            operacao = rand() % 8 ;
            printf("%d\n", operacao);
            system(tempo);
        }
        
        switch (operacao){
            case 0: printf("\nSair"); break;
            case 1: mostrarEstoqueAtual(); break;
            case 2: mostrarEstoqueMinimo(); break;
            case 3: mostrarEstoqueMaximo(); break;
            case 4: listaParaCompras(); break;
            case 5: comprarProdutosDaLista(); break;
            case 6: completarEstoqueAtualComMaximo(); break;
            case 7: mostrarEstoqueAtual(); pegarProdutoDoEstoque(); break;
            default: printf("\nOperação não encontrada.\n");
        }
    }while(operacao != 0);
    printf("\n");
}

void automatizar(){
    char tecla;
    printf("\nGostaria de ver a demonstração automática do algorítimo?");
    printf("\n Aperte s para sim ou qualquer outra tecla para não: ");
    tecla = getchar();
    getchar();
    if(tecla == 's'){
        srand(time(NULL));
        automatico = 1;
    }

}

int main()
{
    
    automatizar();
    
    menuPrincipal();

    printf("\nAté logo!!!");
    
    printf("\n \nProgramador: Rodrigo Lorandi");
    
    return 0;
}




