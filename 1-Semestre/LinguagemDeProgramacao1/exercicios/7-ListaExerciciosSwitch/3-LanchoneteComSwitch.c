
#include <stdio.h>
#include <string.h>

int
main ()
{
  float totalPedido;
  char NomeDoLanche[20];
  int codigoLanche;
  int quantidade;
  totalPedido = 0;
  
    printf ("\nDigite o código do seu lanche: ");
    scanf ("%d", &codigoLanche);

    printf ("\nDigite a quantidade: ");
    scanf ("%d", &quantidade);
    
    switch (codigoLanche)
    {
    case 100:
      strcpy (NomeDoLanche, "Cachorro quente");
      totalPedido = quantidade * 10.00;
      printf ("\nPedido:  %d unidade(s) de %s", quantidade, NomeDoLanche);
      printf ("\nTotal R$%.2f", totalPedido);
      break;
    case 101:
      strcpy (NomeDoLanche, "Bauru Simples");
      totalPedido = quantidade * 13.00;
      printf ("\nPedido:  %d unidade(s) de %s", quantidade, NomeDoLanche);
      printf ("\nTotal R$%.2f", totalPedido);
      break;
    case 102:
      strcpy (NomeDoLanche, "Bauru c/ ovo");
      totalPedido = quantidade * 16.00;
      printf ("\nPedido:  %d unidade(s) de %s", quantidade, NomeDoLanche);
      printf ("\nTotal R$%.2f", totalPedido);
      break;
    case 103:
      strcpy (NomeDoLanche, "Hambuguer");
      totalPedido = quantidade * 14.00;
      printf ("\nPedido:  %d unidade(s) de %s", quantidade, NomeDoLanche);
      printf ("\nTotal R$%.2f", totalPedido);
      break;
    case 104:
      strcpy (NomeDoLanche, "Cheeseburguer");
      totalPedido = quantidade * 16.00;
      printf ("\nPedido:  %d unidade(s) de %s", quantidade, NomeDoLanche);
      printf ("\nTotal R$%.2f", totalPedido);  
      break;
    case 105:
      strcpy (NomeDoLanche, "Refrigerante");
      totalPedido = quantidade * 4.00;
      printf ("\nPedido:  %d unidade(s) de %s", quantidade, NomeDoLanche);
      printf ("\nTotal R$%.2f", totalPedido);  
      break;
    default:
      printf ("\nOpção inválida");
    }

  return 0;
}

