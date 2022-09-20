/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
    int bate = 1;
    char martelo[9] = "martelo";
    
    while(bate <= 5){
        if(bate > 1){
            strcpy (martelo, "martelos");
        }
        printf("\n Guto bate com %d %s", bate, martelo);
        printf("\n %d %s, %d %s", bate, martelo, bate, martelo);
        printf("\n Guto bate com %d %s", bate, martelo);
        
        if(bate < 5){
            printf("\n Então bate com %d", ++bate);
        } else{
            printf("\n E depois vai dormir");
            bate++;
        }
        printf("\n");
      
    }


    return 0;
}
