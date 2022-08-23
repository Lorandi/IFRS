Algoritmo "Média Escolar"
//  
//  


Var
   prova1,prova2,provaRecuperacao :inteiro
   media: real
   mediaRecuperacao: real

Inicio

   escreval("Digite a primeira nota")
   leia(prova1)
   escreval("Digigite a segunda nota")
   leia(prova2)

   media <- (prova1 + prova2)/2

   escreval ("A média do aluno foi: ", media)

   se media >= 7 entao
      se media >= 9 entao
         escreval("Aluno Aprovado com honra")
      senao
         escreval("Aluno aprovado")
      fimse
   senao
      escreval("Aluno em recuperação")
      escreval("A prova será dia 16/08")
      escreval("Digigite a nota da recuperacao")
      leia(provaRecuperacao)
   fimse

   mediaRecuperacao <- ( media + provaRecuperacao)/2

   se media < 7 entao
      se mediaRecuperacao >= 7 entao
         escreval ("Aluno Aprovado")
      senao
         escreval("Aluno Reprovado")
      fimse
      escreval ("A média do aluno foi: ", mediaRecuperacao)
   fimse


Fimalgoritmo
