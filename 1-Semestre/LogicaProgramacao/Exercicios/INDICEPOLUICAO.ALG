Algoritmo "IndicePoluicao"
// Disciplina   : [Linguagem e Lógica de Programação]
// Professor   : Antonio Carlos Nicolodi

Var
   valor: real

Inicio

   escreva("Insira o valor do indice de poluicao: ")
   leia(valor)

   se valor >= 0.1 entao
      se valor >= 0.25 entao
         se valor >= 0.26 entao
            se valor >= 0.4 entao
               se valor >= 0.5 entao
                  escreval("Todos os grupos de empresas devem suspender atividades")
               senao
                  escreval("Empresas do grupo 1 e 2 devem suspender atividades")
               fimse
            senao
               escreval ("Empresas do grupo 1 devem suspender atividades")
            fimse
         senao
            escreval("Níveis aceitaveis de poluição")
         fimse
      senao
         escreval(" Valor de indice invalido")
      fimse
   fimse
Fimalgoritmo