Algoritmo "Média Escolar com faltas"
//


Var
   prova1,prova2,provaRecuperacao,faltas :inteiro
   media: real
   mediaRecuperacao: real
   emRecuperacao: logico


Inicio

   escreval("Digite a primeira nota")
   leia(prova1)
   escreval("Digigite a segunda nota")
   leia(prova2)
   escreval("Digigite o total de faltas")
   leia(faltas)

   emRecuperacao <- falso

   media <- (prova1 + prova2)/2

   escreval ("A média do aluno foi: ", media)

   se (media >= 7) e (faltas < 8) entao
      se media >= 9 entao
         escreval("Aluno Aprovado com honra")
      senao
         escreval("Aluno aprovado")
      fimse
   senao
      emRecuperacao <- verdadeiro
      se (media < 7) entao
         escreval("Aluno em recuperacao em função das notas")
      senao
         escreval("Aluno em recuperacao em função das faltas")
      fimse
   fimse

   se emRecuperacao = verdadeiro entao
      escreval("A prova será dia 16/08")
      
      escreval("Digigite a nota da recuperacao")
      
      leia(provaRecuperacao)
      
      mediaRecuperacao <- ( media + provaRecuperacao)/2

      se mediaRecuperacao >= 7 entao
         escreval ("Aluno Aprovado")
      senao
         escreval("Aluno Reprovado")
      fimse
      escreval ("A média do aluno foi: ", mediaRecuperacao)
   fimse


Fimalgoritmo
