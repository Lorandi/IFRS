#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void portugues(char t){
    switch(t){
        case 'm': printf("\nBom dia!"); break;
        case 't': printf("\nBoa tarde!"); break;
        case 'n': printf("\nBoa noite!"); break;
    }
} 

void ingles(char t){
    switch(t){
        case 'm': printf("\nGood morning!"); break;
        case 't': printf("\nGood afternoom!"); break;
        case 'n': printf("\nGood night!"); break;
    }
} 

void espanhol(char t){
    switch(t){
        case 'm': printf("\nBuen día!"); break;
        case 't': printf("\nBuenas tardes!"); break;
        case 'n': printf("\nBuenas noches!"); break;
    }
} 

void italiano(char t){
    switch(t){
        case 'm': printf("\nBuongiorno!"); break;
        case 't': printf("\nBuon pomeriggio!"); break;
        case 'n': printf("\nBuona Notte!"); break;
    }
}

void alemao(char t){
    switch(t){
        case 'm': printf("\nGuten Morgen!"); break;
        case 't': printf("\nGuten Nachmittag!"); break;
        case 'n': printf("\nGute Nacht!"); break;
    }
}

char turno;
int lingua; 

int main()
{
    srand(time(NULL));
    char abc[3]="mtn";
    
    do{
        turno = abc[rand() % 3];
        lingua = rand() % 5;
        
        switch(lingua){
            case 1:
                portugues(turno);
                break;
            
            case 2:
                ingles(turno);
                break;
                
            case 3:
                espanhol(turno);
                break;
                
            case 4:
                italiano(turno);
                break;
                
            case 5:
                alemao(turno);
                break;
                
            default:
                printf("\n\nFIM!!!");
        }
    }while(lingua !=0);

    return 0;
}

