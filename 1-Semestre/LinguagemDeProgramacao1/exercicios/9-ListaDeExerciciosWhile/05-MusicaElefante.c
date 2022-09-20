
#include <stdio.h>
#include <string.h>

int main()
{
    int quantos = 1;
    char elefante[10] = "elefante";
    char foi[6] = "Foi";
    char balancava[12] = "balançava";
    int repete;
    
    printf ("\nDigite o total de elefantes: ");
    scanf ("%d", &repete);

    
    while(quantos <= repete){
        if(quantos > 1){
            strcpy (elefante, "elefantes");
            strcpy (balancava, "balançavam");
            strcpy (foi, "Foram");
        }

        printf("\n %d %s se %s, numa teia de aranha", quantos++, elefante, balancava);
        printf("\n Mas como a teia não se arrebentou,");
       
        
        if(quantos > repete){
            printf("\n Todos foram para o chão!");
        } else{
             printf("\n %s chamar outro elefante.", foi);
        }
        printf("\n");
      
    }

    return 0;
}


