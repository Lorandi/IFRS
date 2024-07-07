/*
 Atividade 04
Escreva uma função recursiva que determine quantas
vezes um CARATERE X ocorre em um STRING Y.
Por exemplo, o caractere A ocorre 3 vezes em
"abacate".
Implementar usando laço de repetição (while ou for) e
outra usando recursividade. 
*/
#include <stdio.h>

int contar_caractere_laco(char caractere, char *string) {
    int contador = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == caractere) {
            contador++;
        }
    }
    return contador;
}

int contar_caractere_recursivo(char caractere, char *string, int contador) {
    if (*string == '\0') return contador;
    
    if (*string == caractere) contador++;

    return contar_caractere_recursivo(caractere, string + 1, contador);
}

int main() {
    char string[] = "abacate";
    char caractere = 'a';

    int ocorrencias_laco = contar_caractere_laco(caractere, string);
    printf("O caractere '%c' ocorre %d vezes na string \"%s\".\n", caractere, ocorrencias_laco, string);  
    
    int ocorrencias_recursiva = contar_caractere_recursivo(caractere, string, 0);
    printf("O caractere '%c' ocorre %d vezes na string \"%s\".\n", caractere, ocorrencias_recursiva, string);

    return 0;
}
