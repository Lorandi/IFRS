
// Algoritmo criado para prova 1 da disciplina Linguagens de Programação 1
// Autor: Rodrigo Lorandi
// Professor: FABIO YOSHIMITSU OKUYAMA
// Porto Alegre, 29/09/2022

#include <stdio.h>
int main()
{
    float juros, depositoMensal, totalEsperado, totalEmConta;
    int meses = 0;
    
    printf("\nDigite a taxa de juros, utilizando .(ponto) para separar casa decimais: ");
    scanf("%f", &juros);
    
    printf("\nDigite o valor mensal a depositar: ");
    scanf("%f", &depositoMensal);
    
    printf("\nDigite a meta a ser atingida:  ");
    scanf("%f", &totalEsperado);   
    
    //enquano  valor na conta não for maior que o esparado, segue o laço
    while (totalEmConta < totalEsperado){
        // total é atualizado a cada iteração
        totalEmConta += depositoMensal + (totalEmConta * (juros/100));
        meses++;
        printf("\n Mês %d R$ %.2f", meses, totalEmConta);
    }
    
    printf("\nA meta será atingida em %d meses.", meses);
    printf("\nProgramador: Rodrigo Lorandi");

    return 0;
}


