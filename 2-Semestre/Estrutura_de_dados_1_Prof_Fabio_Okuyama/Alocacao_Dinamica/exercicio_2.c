#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define MAX_NOME 150
#define MAX_TEL 15

typedef struct {
    char nome[MAX_NOME];
    char telefone[MAX_TEL];
    int idade;
    char contato[MAX_NOME];
} aluno;

void leitura(aluno *a) {
    printf("Digite o nome do aluno: ");
    fgets((*a).nome, MAX_NOME, stdin);
    printf("Digite a idade do aluno: ");
    scanf("%d", &(*a).idade);
    getchar(); // consumir o caractere de nova linha
    printf("Nome do Contato de emergencia: ");
    fgets((*a).contato, MAX_NOME, stdin);
    printf("Digite o Telefone do Contato: ");
    fgets(a->telefone, MAX_TEL, stdin);
    printf("\n");
}
void imprime(aluno a) {
    printf("Nome: %s\t Idade: %d anos\n", a.nome, a.idade);
    printf("Contato: %s \tTelefone:%s\n", a.contato, a.telefone);
}

int main(int argc, char *argv[]) {
    aluno* alunos[MAX];
    int i, num;
    

    for (i = 0; i < MAX; i++) {
        alunos[i] = NULL;
    }

    for (i = 0; i < MAX; i++) {
        alunos[i] = (aluno*) malloc(sizeof(aluno));
        if (alunos[i] != NULL) {
            leitura(alunos[i]);
        }
    }

    do {
        printf("Digite um numero de 1 a %d:", MAX);
        scanf("%d", &num);
        getchar(); // consumir o caractere de nova linha
        if (num >= 1 && num <= MAX) {
            imprime(*alunos[num - 1]);
        }
    } while (num);

    for (i = 0; i < MAX; i++) {
        if (alunos[i] != NULL) {
            free(alunos[i]);
        }
    }
    
    printf("Bytes ocupados pelo vetor alunos: %lu bytes\n", sizeof(alunos));
    printf("Bytes ocupados por uma vartiavel do tipo aluno: %lu bytes\n", sizeof(aluno));
    printf("Quanto de memória (em bytes) foi alocado para este programa: %lu bytes\n",(MAX * sizeof(aluno)) + sizeof(alunos));
    
    /*
    a) O vetor alunos ocupa 40 bytes, pois cada posição do vetor é um ponteiro para um aluno e o tamanho de um 
    ponteiro em um sistema de 64 bits é 8 bytes, então 8 x 5 = 40 bytes.

    b) Uma variável do tipo aluno ocupa 324 bytes. Isso pode ser calculado somando 
    o tamanho dos tipos de dados contidos na estrutura: 150 bytes para o nome, 15 bytes para o telefone, 
    4 bytes para a idade e 150 bytes para o contato de emergência. Como o sistema é de 64 bits, 
    o tamanho da estrutura é arredondado para um múltiplo de 8 bytes.

    c) Para este programa, foi alocado um total de 1660 bytes em memória. Cada posição do vetor alunos aloca 
    um bloco de memória com o tamanho de uma variável do tipo aluno, que é de 324 bytes então, 5 x 324 = 1620 bytes.
    Também é necessário somar os 40 bytes do vetor, totalizando 1660 bytes. 
    */

    return 0;
}

