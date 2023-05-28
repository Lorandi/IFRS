
#include <stdio.h>

int main()
{
    char texto[20] = "composto";
    char *text = "composto";
    char txt[] = "composto";
    printf("%s %s %s",texto, text, txt); 
    printf("\n"); 
    printf("%p\n%p\n%p",&texto, &text, &txt); 

    return 0;
}
