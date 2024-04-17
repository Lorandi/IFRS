package agenda;

import pessoas.Funcionario;
import pessoas.Pessoa;

import java.util.Scanner;

public class MenuAgenda {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Agenda<Pessoa> agenda = new Agenda<>();

        while (true) {
            System.out.println("Menu:");
            System.out.println("1 - Cadastrar uma pessoa");
            System.out.println("2 - Listar todas as pessoas ordenadas pelo nome");
            System.out.println("3 - Listar o número total de contatos");
            System.out.println("4 - Pesquisar uma pessoa na agenda");
            System.out.println("5 - Remover uma pessoa da agenda");
            System.out.println("6 - Sair");
            System.out.print("Escolha uma opção: ");
            int opcao = scanner.nextInt();
            scanner.nextLine(); // Consumir a quebra de linha após o número

            switch (opcao) {
                case 1:
                    System.out.print("\nDigite o nome do Pessoa: ");
                    String nomePessoa = scanner.nextLine();
                    if (agenda.cadastrar(new Pessoa(nomePessoa))) {
                        System.out.println(nomePessoa + " cadastrada\n");
                    } else {
                        System.out.println("Erro ao cadastrar\n");
                    }
                    break;

                case 2:
                    System.out.println("\nListar todas as pessoas ordenadas pelo nome:");
//                    for (Pessoa pessoa : agenda.listarTodos()) {
//                        System.out.println(pessoa.getNome());
//                    }
                    System.out.println(agenda.toString());
                    System.out.println("\n");
                    break;

                case 3:
                    System.out.println("\nListar o número total de contatos:");
                    System.out.println(agenda.totalizar() > 0 ? "Total de contatos: " + agenda.totalizar()  +"\n": "Agenda está vazia\n");
                    break;

                case 4:
                    System.out.println("\nPesquisar uma pessoa na agenda");
                    System.out.print("Digite o nome da pessoa: ");
                    String nome = scanner.nextLine();
                    System.out.println(agenda.pesquisar(new Pessoa(nome)) ? "Pessoa (" + nome + ") encontrada\n" : "Pessoa (" + nome + ")não encontrada\n");
                    break;

                case 5:
                    System.out.println("\nRemover uma pessoa da agenda");
                    System.out.print("Digite o nome da pessoa: ");
                    String nomeRemover = scanner.nextLine();
                    System.out.println(agenda.remover(new Pessoa(nomeRemover)) ? nomeRemover +" removida\n" : nomeRemover + " não encontrada\n");
                    break;

                case 6:
                    System.out.println("\nSaindo...");
                    System.exit(0);
                    break;

                default:
                    System.out.println("Opção inválida!");
            }
        }
    }
}
