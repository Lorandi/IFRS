
#include <stdio.h>

float mediaDeDoisPonteiros(int *a, int *b){
    return (*a + *b) / 2.0;
}

int maiorValor(int *a, int *b, int *c){
    int maior = *a;
    
    if(*b > maior){
        maior = *b;
    }
    
    if(*c > maior){
        maior = *c;
    }
    
    return maior;
}

int* enderecoDaMaiorValor(int *a, int *b, int *c){
    int maior = *a;
    int* endereco = a;
    
    if(*b > maior){
        maior = *b;
        endereco = b;
    }
    
    if(*c > maior){
        maior = *c;
        endereco = c;
    }
    
    return endereco;
}




int main(){
    float var[4] = {4.54, 6.77, 3.13, 7.04};
    int a = 15, b = 26, c = 19;
    
    printf("\n Crie um programa que leia 4 variáveis float, informe o endereço e o conteúdo de cada uma delas.");
     
    for(int i = 0; i < 4; i++){
        printf("\n Variável %d = %.2f", i, var[i]);
        printf("\n Endereço da variável %d é %p", i, &var[i]);
        printf("\n"); 
    }
    
    printf("\n");
    printf("\nCrie uma função que recebe dois ponteiros inteiros como parâmetros e devolva a media aritmética destes números (float)");
    printf("\n Média dos ponteiros de a e b = %.2f", mediaDeDoisPonteiros(&a,&b));
    
    
    printf("\n");
    printf("\nCrie uma função que receba como parâmetro 3 ponteiros variáveis inteiras e devolva o maior valor");
    printf("\nMaior valor = %d", maiorValor(&a, &b, &c));
    
    
    printf("\n");
    printf("\n Crie uma função que receba como parâmetro 3 ponteiros para inteiro e devolva o endereço que aponta para a variável de maior valor;");
    printf("\nEndereço da maior variável é = %p", enderecoDaMaiorValor(&a, &b, &c));
    printf("\n a = %p", &a);
    printf("\n b = %p", &b);
    printf("\n c = %p", &c);

    

    return 0;
}

