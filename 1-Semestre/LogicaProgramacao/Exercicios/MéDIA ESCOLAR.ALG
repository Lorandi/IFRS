Algoritmo "Média Escolar"


Var
   a,b :inteiro
   c: real

Inicio

   escreval("Digite a primeira nota")
   leia(a)
   escreval("Digigite a segunda nota")
   leia(b)

   c <- (a + b)/2

   se c >= 7 entao
      escreval("Aluno Aprovado")
   senao
      escreval("Aluno Reprovado")
   fimse
   
   escreval ("A média do aluno foi: ", c)

Fimalgoritmo