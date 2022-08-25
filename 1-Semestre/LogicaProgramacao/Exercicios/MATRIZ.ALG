Algoritmo "Matriz"

var

   i, j: inteiro
   linha, coluna: real
   matrizA : vetor [1..15,1..5] de real

inicio


   Para i de 1 ate 15 faca
      Para j de 1 ate 5 faca
         matrizA[i,j] <- RandI(10)
      fimpara
   fimpara

   escreval("Matriz A:")

   para i de 1 ate 15 faca
      para j de 1 ate 5 faca
         escreva (matrizA[i,j]:4)
      fimPara
      escreval("")
   fimPara

   para i de 1 ate 15 faca
      para j de 1 ate 5 faca
         linha <- linha + matrizA[i,j]
      fimPara
      escreval("Linha ", i, " somou: ", linha)
      linha <- 0
      escreval("")
   fimPara

   para j de 1 ate 5 faca
      para i de 1 ate 15 faca
         coluna <- coluna + matrizA[i,j]
      fimPara
      escreval("Coluna ", j, " somou: ", coluna)
      coluna <- 0
      escreval("")
   fimPara

fimalgoritmo