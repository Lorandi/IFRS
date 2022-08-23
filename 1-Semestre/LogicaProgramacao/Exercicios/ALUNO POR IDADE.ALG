Algoritmo "Aluno por idade"
// Disciplina   : [Linguagem e Lógica de Programação]
// Professor   : Antonio Carlos Nicolodi

Var
   idade: caracter

Inicio
   escreval("Escreva a idade do aluno ")
   leia(idade)

   escolha idade
   caso "0", "1", "2", "3"
      escreval("Bebê")
   caso "4", "5", "6", "7", "8", "9", "10", "11"
      escreval("Criança")
   caso "12", "13", "14", "15", "16", "17"
      escreval("Adolescente")
   caso "18", "19", "20"
      escreval("Adulto")
   outrocaso
      escreval("Valor inválido")
   fimescolha
Fimalgoritmo