#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 1
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
float mediaNotas(Aluno *a);

int main() {
    
    Aluno *a = alunos;
    
    salvarAluno(a);
    
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


void salvarAluno(Aluno *a) {
    for (int i = 0; i < MAX_ALUNOS; i++) {
      printf("\nAluno %d\n", i + 1);
      printf("Nome: ");
      fgets(a->nome, TAMANHO_NOME, stdin);
      printf("Matricula: ");
      scanf("%s", a->matricula);
      getchar();
      printf("Digitar as notas : ");
          for (int j = 0; j < NOTAS; j++) {
            printf("\n Nota %d de %d: ", j + 1, NOTAS);
            scanf("%f", &a->notas[j]);
            getchar();
          }
      printf("\nFaltas: ");
      scanf("%d", &a->faltas);
      getchar();
    }
}

void imprimirAlunos() {
    Aluno *a;
    for (int i = 0; i < MAX_ALUNOS; i++) {
        a = &alunos[i];
        printf("\nDados do aluno %d\n", i + 1);
        printf("Nome: %s", a->nome);
        printf("Matricula: %s\n",  a->matricula);
        printf("Notas: ");
        for (int j = 0; j < NOTAS; j++) {
            printf("\n Nota %d : %.2f ", j+1, a->notas[j]);
        }
        printf("\nFaltas: %d\n",  a->faltas);
    }
}

float mediaNotas(Aluno *a) {
  float soma = 0;
  for (int i = 0; i < NOTAS; i++) {
    soma += a -> notas[i];
  }
  return soma / NOTAS;
}

void situacaoAluno() {
   Aluno *a;
    for (int i = 0; i < MAX_ALUNOS; i++) {
         a = &alunos[i];
        printf("\nSituacao do aluno %s", a->nome);
        printf("Media: %.1f\n", mediaNotas(a));
        printf("Faltas: %d\n", a->faltas);
        if (mediaNotas(a) >= 7.0 && a->faltas <= 10) {
            printf("Situacao: Aprovado\n");
        } else {
            printf("Situacao: Reprovado\n");
        }
    }
}

