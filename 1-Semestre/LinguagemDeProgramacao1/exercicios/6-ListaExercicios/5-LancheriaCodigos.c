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

  if (codigoLanche == 100)
    {
      strcpy (NomeDoLanche, "Cachorro quente");
      totalPedido = quantidade * 5.00;
      printf ("\nPedido:  %d unidade(s) de %s", quantidade, NomeDoLanche);
      printf ("\nTotal R$%f", totalPedido);
    }
  else
    {
      if (codigoLanche == 101)
	{
	  strcpy (NomeDoLanche, "Bauru simples");
	  totalPedido = quantidade * 6.00;
	  printf ("\nPedido:  %d unidade(s) de %s", quantidade, NomeDoLanche);
	  printf ("\nTotal R$%f", totalPedido);
	}
      else
	{
	  if (codigoLanche == 102)
	    {
	      strcpy (NomeDoLanche, "Bauru c/ovo");
	      totalPedido = quantidade * 8.00;
	      printf ("\nPedido:  %d unidade(s) de %s", quantidade,
		      NomeDoLanche);
	      printf ("\nTotal R$%f", totalPedido);
	    }
	  else
	    {
	      if (codigoLanche == 103)
		{
		  strcpy (NomeDoLanche, "Hamburger");
		  totalPedido = quantidade * 5.00;
		  printf ("\nPedido:  %d unidade(s) de %s", quantidade,
			  NomeDoLanche);
		  printf ("\nTotal R$%f", totalPedido);
		}
	      else
		{
		  if (codigoLanche == 104)
		    {
		      strcpy (NomeDoLanche, "Cheeseburger");
		      totalPedido = quantidade * 7.50;
		      printf ("\nPedido:  %d unidade(s) de %s", quantidade,
			      NomeDoLanche);
		      printf ("\nTotal R$%f", totalPedido);
		    }
		  else
		    {
		      if (codigoLanche == 105)
			{
			  strcpy (NomeDoLanche, "Refrigerante");
			  totalPedido = quantidade * 2.00;
			    printf ("\nPedido:  %d unidade(s) de %s",
				    quantidade, NomeDoLanche);
			  printf ("\nTotal R$%f", totalPedido);
			}
		      else
			{
			  printf ("\n Código não encontrado");
			}
		    }
		}
	    }
	}
    }

  return 0;
}
