Algoritmo "Lachonete"
// Disciplina   : [Linguagem e Lógica de Programação]
// Professor   : Antonio Carlos Nicolodi

Var
   codigo, quantidade: real
   faltaEscolherCombo: logico

Inicio
   faltaEscolherCombo <- verdadeiro

   enquanto (faltaEscolherCombo = verdadeiro) faca
      escreval("Peça pelo número ")
      escreval("1 - X-Salada ")
      escreval("2 - X-Calabresa ")
      escreval("3 - X-Fritas ")
      escreval("4 - X-Molho ")
      escreval("5 - X-Bacon ")
      escreva("Insira o código do seu combo: ")
      leia(codigo)
      
      escolha codigo
      caso 1, 2, 3, 4, 5
         escreval(" ")
         faltaEscolherCombo <- falso
      outrocaso
         escreval(" ")
         escreval("Combo não encontrado")
      fimescolha

   fimenquanto

   escreva("Insira a quantidade: ")
   leia(quantidade)
   escreval(" ")

   enquanto (quantidade <= 0) faca
      escreval("Valor inserido para quantidade inválido")
      escreva("Insira a quantidade, devendo ser um número maior que zero: ")
      leia(quantidade)
      escreval(" ")
   fimenquanto

   escolha codigo
   caso 1
      escreval("Você escolheu ", quantidade, " combos de X-Salada")
      escreval("Valor total: ", quantidade * 13.8)
   caso 2
      escreval("Você escolheu ", quantidade, " combos de X-Calabresa")
      escreval("Valor total: ", quantidade * 15.8)
   caso 3
      escreval("Você escolheu ", quantidade, " combos de X-Fritas")
      escreval("Valor total: ", quantidade * 18.9)
   caso 4
      escreval("Você escolheu ", quantidade, " combos de X-Molho")
      escreval("Valor total: ", quantidade * 13.5)
   caso 5
      escreval("Você escolheu ", quantidade, " combos de X-Bacon")
      escreval("Valor total: ", quantidade * 17.9)
   outrocaso
      escreval("Combo não encontrado")
   fimescolha

Fimalgoritmo