Algoritmo "par ou impar"

Var
   numero: inteiro

Inicio
   escreval("Escreva um numero")
   leia(numero)

   se ( numero MOD 2 ) = 0 entao
   // aceita tamb�m % no lugar de MOD
      escreval ("� um n�mero par")
   senao
      escreval("� um numero impar")
   fimse

Fimalgoritmo