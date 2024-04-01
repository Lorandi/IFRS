#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void StrCopy(char *destino, char *origem){
	while(*origem){
		*destino = *origem;
		origem++;
		destino++;
	}
	*destino = '\0';
	}
	
int main() {
	char str1[100], str2[100], str3[100];
	printf("Entre com uma string: ");
	gets(str1);
	StrCopy(str2, str1);
	StrCopy(str3, "Voce digitou a  string :");
	printf("\n%s%s\n\n", str3, str2);
	system("pause");
	return(0);       
}

