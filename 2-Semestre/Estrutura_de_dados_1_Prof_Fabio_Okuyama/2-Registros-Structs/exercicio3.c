#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 5
#define NOTAS 4
#define TAMANHO_NOME 50
#define TAMANHO_TELEFONE 30
#define TAMANHO_MATRICULA 10

typedef struct {
  char nome[TAMANHO_NOME];
  char matricula[TAMANHO_MATRICULA];
  float notas[NOTAS];
  int faltas;
} Aluno;

Aluno alunos[MAX_ALUNOS];

void salvarAluno(); 
void situacaoAluno();
void imprimirAlunos();
float mediaNotas(Aluno aluno);

int main() {
    salvarAluno();
    
    int operacao;

    do {
        printf("\nMenu\n\n");
        printf("\n1 - Informações dos alunos.\n");
        printf("\n2 - Situação dos alunos.\n");
        printf("\n3 - Encerrar.\n");
        printf("\nEscolha uma opção: ");
        scanf("%d",&operacao);
        getchar();
    
        switch (operacao){
            case 1:  imprimirAlunos();break;
            case 2:  situacaoAluno(); break;
            case 3: printf("\nEncerrando operação.\n"); break;
            default: printf("\nOperação não encontrada.\n");
        }

    } while (operacao != 3);

  return 0;
}


void salvarAluno() {
    Aluno a;
    for (int i = 0; i < MAX_ALUNOS; i++) {
      printf("\nAluno %d\n", i + 1);
      printf("Nome: ");
      fgets(a.nome, TAMANHO_NOME, stdin);
      printf("Matricula: ");
      scanf("%s", a.matricula);
      getchar();
      printf("Digitar as notas : ");
          for (int j = 0; j < NOTAS; j++) {
            printf("\n Nota %d de %d: ", j + 1, NOTAS);
            scanf("%f", &a.notas[j]);
            getchar();
          }
      printf("\nFaltas: ");
      scanf("%d", &a.faltas);
      getchar();
      alunos[i] = a;
    }
}

void imprimirAlunos() {
    for (int i = 0; i < MAX_ALUNOS; i++) {
        printf("\nDados do aluno %d\n", i + 1);
        printf("Nome: %s", alunos[i].nome);
        printf("Matricula: %s\n", alunos[i].matricula);
        printf("Notas: ");
        for (int j = 0; j < NOTAS; j++) {
            printf("\n Nota %d : %.2f ", j+1, alunos[i].notas[j]);
        }
        printf("\nFaltas: %d\n", alunos[i].faltas);
    }
}

float mediaNotas(Aluno aluno) {
  float soma = 0;
  for (int i = 0; i < NOTAS; i++) {
    soma += aluno.notas[i];
  }
  return soma / NOTAS;
}

void situacaoAluno() {
    for (int i = 0; i < MAX_ALUNOS; i++) {
        printf("\nSituacao do aluno %s", alunos[i].nome);
        printf("Media: %.1f\n", mediaNotas(alunos[i]));
        printf("Faltas: %d\n", alunos[i].faltas);
        if (mediaNotas(alunos[i]) >= 7.0 && alunos[i].faltas <= 10) {
            printf("Situacao: Aprovado\n");
        } else {
            printf("Situacao: Reprovado\n");
        }
    }
}
