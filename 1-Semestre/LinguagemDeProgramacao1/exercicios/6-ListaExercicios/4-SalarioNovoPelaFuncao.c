#include <stdio.h>
#include <string.h>

int
main ()
{
  float salario;
  char string1[20];
  int funcao;

  printf ("\nDigite seu nome: ");
  gets (string1);

  printf ("\nDigite seu salário: ");
  scanf ("%f", &salario);

  printf ("\nDigite o código da sua função: ");
  scanf ("%d", &funcao);

  if (funcao == 1){
      printf ("\n %s teve seu salário aumentado para R$%.2f!", string1, salario *= 1.3);
    } else{
        if (funcao == 2){
        printf ("\n %s teve seu salário aumentado para R$%.2f!", string1, salario *= 1.25);
        }else{
            if (funcao == 3){
            printf ("\n %s teve seu salário aumentado para R$%.2f!", string1, salario *= 1.2);
            }else{
                if (funcao == 4){
                printf ("\n %s teve seu salário aumentado para R$%.2f!", string1, salario *= 1.10);
                }else{
                    if (funcao == 5){
                        printf ("\n %s teve seu salário aumentado para R$%.2f!", string1, salario *= 1.01);
                    }else{
                        printf ("\n Código não encontrado");
                    }
                }
            }
        }
    }

  return 0;
}
