Algoritmo "Prefeitura"

Var
   salario: real
   numeroDeFilhos: inteiro
   entradaSalarios: inteiro
   entradaFilhos: inteiro
   tempSalario: real
   tempNumeroFilhos: inteiro
   mediaSalarioPopulacao: real
   mediaNumeroFilhos: real
   maiorSalario: real
   totalGanhamMenosDeCem: real


Inicio
   entradaSalarios <- 0
   entradaFilhos <- 0
   salario <- 0
   maiorSalario <- salario
   tempSalario <- 0
   tempNumeroFilhos <- 0
   totalGanhamMenosDeCem <- 0

   enquanto (salario >=0) faca
      escreval("Digite valor do sal�rio maior do que 0 para registar")
      escreva("ou negativo para sair:  ")
      leia(salario)

      se salario > 0 entao
         escreva("Digite o n�mero de filhos: ")
         leia(numeroDeFilhos)
         tempSalario <- tempSalario + salario
         tempNumeroFilhos <- tempNumeroFilhos +  numeroDeFilhos
         entradaSalarios <- entradaSalarios + 1
         entradaFilhos <- entradaFilhos + 1
         escreval(" ")
         se salario <= 100 entao
            totalGanhamMenosDeCem <- totalGanhamMenosDeCem + 1
         fimse
      fimse

      se salario > maiorSalario entao
         maiorSalario <- salario
      fimse

   fimescolha
   mediaSalarioPopulacao <- tempSalario/entradaSalarios
   mediaNumeroFilhos <-  tempNumeroFilhos/entradaFilhos

fimenquanto
escreval(" ")
escreval("A media dos salarios � R$",mediaSalarioPopulacao)
escreval("A m�dia dos numero de filhos � ",mediaNumeroFilhos)
escreval("O maior sal�rio � ",maiorSalario)
escreval((totalGanhamMenosDeCem/entradaSalarios)*100 ,"% da popula��o ganha at� R$100,00")


Fimalgoritmo