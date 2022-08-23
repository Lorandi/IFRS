Algoritmo "Calculadora"

Var
   n1,n2:real
   operador:caracter

Inicio
   escreval("Informe dois valores")
   leia(n1,n2)
   escreval("Informe um operador aritmético")
   leia(operador)
   escolha operador
   caso "+"
      escreval("n1+n2=", n1+n2)
   caso "-"
      escreval("n1-n2=", n1-n2)
   caso "/"
      escreval("n1/n2=", n1/n2)
   caso "*"
      escreval("n1*n2=", n1*n2)
   outrocaso
      escreval("Operador inválido")
   fimescolha
Fimalgoritmo