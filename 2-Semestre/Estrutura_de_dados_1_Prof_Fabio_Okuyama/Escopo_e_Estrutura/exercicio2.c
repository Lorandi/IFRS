#include <stdio.h>
#include <string.h>

#define TOTAL_ALUNOS 5
#define TAMANHO_NOME 50
#define TAMANHO_TELEFONE 30

typedef struct {
  char nome[TAMANHO_NOME];
  char telefone[TAMANHO_TELEFONE];
  int idade;
  char contato[TAMANHO_NOME];
}Aluno;

Aluno alunos[TOTAL_ALUNOS];

void salvarAluno(); 

void imprimirAlunos();


int main() {

  salvarAluno();
  printf("\n");
  imprimirAlunos();
  
  return 0;
}

void salvarAluno() {
    Aluno a;
    
    for (int i = 0; i < TOTAL_ALUNOS; i++) {
        printf("\n Escreva as informações do aluno %d:", i + 1);
        printf("\nNome: ");
        fgets(a.nome, TAMANHO_NOME, stdin);
        printf("Telefone de emergência : ");
        fgets(a.telefone, TAMANHO_TELEFONE, stdin);
        printf("Idade: ");
        scanf("%d", &a.idade);
        getchar();
        printf("Contato de emergência: ");
        fgets(a.contato, TAMANHO_NOME, stdin);
        alunos[i] = a;
    }
}

void imprimirAlunos() {
    for (int i = 0; i < TOTAL_ALUNOS; i++) {
      printf("Informações do aluno %d:", i + 1);
      printf("\nNome: %s", alunos[i].nome);
      printf("Telefone de emergência: %s", alunos[i].telefone);
      printf("Idade: %d", alunos[i].idade);
      printf("\nContato: %s", alunos[i].contato);
      printf("\n");
    }
}

