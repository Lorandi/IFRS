
#include <stdio.h>
#include <string.h>

int
main ()
{
  float totalPedido = 0;
  char NomeDoLanche[20];
  int codigoLanche;
  int quantidade;
  totalPedido = 0;
  int continuar = 1;

  do
    {

      printf ("\n Digite o código do seu lanche ou zero para sair: ");
      scanf ("%d", &codigoLanche);

      if (codigoLanche != 0)
	{
	  printf ("\n Digite a quantidade: ");
	  scanf ("%d", &quantidade);
	}

      switch (codigoLanche)
	{
	case 100:
	  strcpy (NomeDoLanche, "Cachorro quente");
	  totalPedido += quantidade * 10.00;
	  printf ("\n Pedido:  %d unidade(s) de %s", quantidade, NomeDoLanche);
	  break;
	case 101:
	  strcpy (NomeDoLanche, "Bauru Simples");
	  totalPedido += quantidade * 13.00;
	  printf ("\n Pedido:  %d unidade(s) de %s", quantidade, NomeDoLanche);
	  break;
	case 102:
	  strcpy (NomeDoLanche, "Bauru c/ ovo");
	  totalPedido += quantidade * 16.00;
	  printf ("\n Pedido:  %d unidade(s) de %s", quantidade, NomeDoLanche);
	  break;
	case 103:
	  strcpy (NomeDoLanche, "Hambuguer");
	  totalPedido += quantidade * 14.00;
	  printf ("\n Pedido:  %d unidade(s) de %s", quantidade, NomeDoLanche);
	  break;
	case 104:
	  strcpy (NomeDoLanche, "Cheeseburguer");
	  totalPedido += quantidade * 16.00;
	  printf ("\n Pedido:  %d unidade(s) de %s", quantidade, NomeDoLanche);

	  break;
	case 105:
	  strcpy (NomeDoLanche, "Refrigerante");
	  totalPedido += quantidade * 4.00;
	  printf ("\n Pedido:  %d unidade(s) de %s", quantidade, NomeDoLanche);
	  break;
	case 0:
	  continuar = 0;
	  break;
	default:
	  printf ("\n Opção inválida");
	  
	  
	}
	
	printf ("\n");

    }
  while (continuar);

  printf ("\nTotal R$%.2f", totalPedido);

  return 0;
}

