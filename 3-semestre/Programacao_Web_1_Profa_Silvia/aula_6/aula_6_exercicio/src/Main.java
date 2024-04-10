import contatos.Telefone;
import documentos.Cpf;
import pessoas.Funcionario;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.TreeSet;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        LinkedList<Telefone> telefones = new LinkedList<>();
        telefones.add(new Telefone(51, 123456789));
        telefones.add(new Telefone(51, 987654321));

        TreeSet<Funcionario> funcionarios = new TreeSet<>();

        Funcionario funcionario1 = new Funcionario("João", telefones, new Cpf(321321,25), "123", 1000.0);
        Funcionario funcionario2 = new Funcionario("Maria", telefones, new Cpf(123123,25), "456", 2000.0);
        Funcionario funcionario3 = new Funcionario("José", telefones, new Cpf(456456,25), "789", 3000.0);
        Funcionario funcionario4 = new Funcionario("Ana", telefones, new Cpf(456455,25), "789", 5000.0);
        Funcionario funcionario5 = new Funcionario("Carlos", telefones, new Cpf(456454,25), "789", 4000.0);

        funcionarios.add(funcionario1);
        funcionarios.add(funcionario2);
        funcionarios.add(funcionario3);
        funcionarios.add(funcionario4);
        funcionarios.add(funcionario5);



        while (true) {
            System.out.println("Menu:");
            System.out.println("1 - Cadastrar Funcionário");
            System.out.println("2 - Listar todos os funcionários");
            System.out.println("3 - Sair");
            System.out.print("Escolha uma opção: ");
            int opcao = scanner.nextInt();
            scanner.nextLine(); // Consumir a quebra de linha após o número

            switch (opcao) {
                case 1:
                    System.out.print("Digite o nome do funcionário: ");
                    String nomeFuncionario = scanner.nextLine();
                    Funcionario novoFuncionario = new Funcionario(nomeFuncionario);
                    funcionarios.add(novoFuncionario);
                    break;
                case 2:
                    System.out.println("Lista de funcionários:");
                    for (Funcionario funcionario : funcionarios) {
                        System.out.println(funcionario.toString());
                    }
                    break;
                case 3:
                    System.out.println("Saindo...");
                    System.exit(0);
                default:
                    System.out.println("Opção inválida!");
            }
        }

    }
}
