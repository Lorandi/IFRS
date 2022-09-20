
#include <stdio.h>
#include <string.h>

int main()
{
    int quantos = 1;
    int check = 2;
    char elefante[10] = "elefante";
    char incomoda[10] = "incomoda";
    int repete = 10;
    int totalIncomoda = 0;
    
    while(quantos < repete){
        
        printf("\n %d %s %s muita gente", quantos++, elefante, incomoda);
        totalIncomoda++;
         if(quantos > 1){
            strcpy (elefante, "elefantes");
            strcpy (incomoda, "incomodam");
        }
        printf("\n %d %s %s", quantos++, elefante, incomoda);
        totalIncomoda++;
        
        while(check < quantos){
            printf(", %s", incomoda);
            totalIncomoda++;
            check++;
        }
        
        printf(" muito mais");
        check = 2;
    }
    
    quantos = repete;
    check = 0;
    
    while(quantos >= 1){
        
        printf("\n %d %s %s muita gente", quantos--, elefante, incomoda);
        totalIncomoda++;
         if(quantos < 2){
            strcpy (elefante, "elefante");
            strcpy (incomoda, "incomoda");

        }
        printf("\n %d %s %s", quantos--, elefante, incomoda);
        totalIncomoda++;
        
        while(check < quantos){
            printf(", %s", incomoda);
            totalIncomoda++;
            check++;
        }
        printf(" muito menos");
        check = 0;
    }
    
    printf("\n \n Incomoda apareceu %d vezes.", totalIncomoda);

    return 0;
}


