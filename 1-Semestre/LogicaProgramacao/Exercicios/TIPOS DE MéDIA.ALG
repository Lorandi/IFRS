Algoritmo "Tipos de média"
// Disciplina   : [Linguagem e Lógica de Programação]
// Professor   : Antonio Carlos Nicolodi

Var
   nota1, nota2, nota3: real
   tipoDeMedia: caracter

Inicio
   escreval("Escreva a nota 1")
   leia(nota1)
   escreval("Escreva a nota 2")
   leia(nota2)
   escreval("Escreva a nota 3")
   leia(nota3)
   escreval("Escolha o tipo de média")
   escreval("Digite 1 para média aritmética ou digite 2 para média ponderada")
   leia(tipoDeMedia)

   escolha tipoDeMedia
   caso "1"
      escreval("Você selecionou média aritmética")
      escreval("O resultado é: ",(nota1+nota2+nota3)/3)
   caso "2"
      escreval("Você selecionou média ponderada")
      escreval("O resultado é: ", (nota1 *3 +nota2 * 3 + nota3 * 4)/10)
   outrocaso
      escreval("Valor inválido")
   fimescolha
Fimalgoritmo