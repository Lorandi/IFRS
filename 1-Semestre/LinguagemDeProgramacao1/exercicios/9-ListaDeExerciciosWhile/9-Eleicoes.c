

#include <stdio.h>

int
main ()
{

  int totalVotos = 0;
  int votosDoZezinho = 0;
  int votosDoHuguinho = 0;
  int votosDoLuizinho = 0;
  int votosBrancos = 0;
  int votosNulo = 0;
  int codigoVoto = 0;
  int maisVotado =0; 
  int continuar = 1;

  do
    {
      printf ("\n 1 - Zezinho");
      printf ("\n 2 - Huguinho");
      printf ("\n 3 - Luizinho");
      printf ("\n 4 - Voto em Branco");
      printf ("\n 5 - Voto Nulo");
      printf ("\n Digite o código do seu candidato ou zero para sair: ");
      scanf ("%d", &codigoVoto);


      switch (codigoVoto)
	{
	case 1:
	  votosDoZezinho++;
	  printf ("\n Voto no Zezinho");
	  break;

	case 2:
	  votosDoHuguinho++;
	  printf ("\n Voto no Huguinho");
	  break;

	case 3:
	  votosDoLuizinho++;
	  printf ("\n Voto no Zezinho");
	  break;

	case 4:
	  votosBrancos++;
	  printf ("\n Voto em branco");
	  break;

	case 5:
	  votosNulo++;
	  printf ("\n Voto nulo");
	  break;

	case 0:
	  continuar = 0;
	  break;

	default:
	  printf ("\n Opção inválida");
	}
	}while (continuar);

	printf ("\n Zezinho teve %d votos.", votosDoZezinho);
      printf ("\n Huguinho teve %d votos.", votosDoHuguinho);
      printf ("\n Luizinho teve %d votos.", votosDoLuizinho);
      printf ("\n O total de votos brancos foram %d.", votosBrancos);
      printf ("\n O total de votos nulos foram %d.", votosNulo);

    if (votosDoZezinho > votosDoLuizinho && votosDoZezinho > votosDoHuguinho){
	  printf ("\n \nO vencedor foi Zezinho");
	} else{
	    if (votosDoLuizinho > votosDoZezinho && votosDoLuizinho > votosDoHuguinho){
	      printf ("\n \nO vencedor foi Luizinho");
	    }else{
	        if (votosDoHuguinho > votosDoZezinho && votosDoHuguinho > votosDoLuizinho){
	            printf ("\n \nO vencedor foi Huguinho");
	    	}else{
		  printf ("\n \nNão houve vencedor.");
		    }
	    }
	}

      return 0;
    }

