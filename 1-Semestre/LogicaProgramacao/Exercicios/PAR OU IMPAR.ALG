Algoritmo "par ou impar"

Var
   numero: inteiro

Inicio
   escreval("Escreva um numero")
   leia(numero)

   se ( numero MOD 2 ) = 0 entao
   // aceita também % no lugar de MOD
      escreval ("É um número par")
   senao
      escreval("É um numero impar")
   fimse

Fimalgoritmo