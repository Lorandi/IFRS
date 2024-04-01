package menu;

import contas.Agencia;
import contas.Conta;
import contas.ContaCorrente;
import contas.ContaEspecial;
import documentos.Cpf;
import pessoas.ClientePessoaFisica;

import javax.swing.*;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class MenuService {
    public static void start() {
        ArrayList<ClientePessoaFisica> clientePessoaFisicaList = new ArrayList<>();
        while (true) {
            switch (exibirMenu()) {
                case 1:
                    clientePessoaFisicaList.add(cadastrarClientePessoaFisica());
                    break;
                case 2:
                    pesquisarClientePessoaFisicaPeloNome(clientePessoaFisicaList);
                    break;
                case 3:
                    pesquisarClientePessoaFisicaPeloCpf(clientePessoaFisicaList);
                    break;
                case 4:
                    pesquisarClientePessoaFisicaPeloNumeroDaConta(clientePessoaFisicaList);
                    break;
                case 5:
                    listarTodosOsClientesDeUmaMesmaAgencia(clientePessoaFisicaList);
                    break;
                case 6:
                    listarTodosOsClientes(clientePessoaFisicaList);
                    break;
                case 7:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Opção inválida");
            }
        }
    }

    private static int exibirMenu() {
        String menu = MenuEnums.getMenu();
        return Integer.parseInt(JOptionPane.showInputDialog(menu));
    }

    private static ClientePessoaFisica cadastrarClientePessoaFisica() {
        String nome = JOptionPane.showInputDialog("Digite o nome do cliente");
        String cpf = JOptionPane.showInputDialog("Digite o ddd do cpf ");
        String numero = JOptionPane.showInputDialog("Digite o numero do cpf");
        return new ClientePessoaFisica(nome, new Cpf(Integer.parseInt(cpf), Long.parseLong(numero)), adicionarContas());
    }

    private static void pesquisarClientePessoaFisicaPeloNome(ArrayList<ClientePessoaFisica> clientePessoaFisicaList) {
        if (clientePessoaFisicaList.isEmpty()) {
            JOptionPane.showMessageDialog(null, "Nenhum cliente cadastrado");
        } else {
            String nome = JOptionPane.showInputDialog("Digite o nome do cliente");
            boolean clienteEncontrado = false;
            for (ClientePessoaFisica cliente : clientePessoaFisicaList) {
                if (cliente != null && cliente.getNome().equalsIgnoreCase(nome)) {
                    JOptionPane.showMessageDialog(null, cliente);
                    clienteEncontrado = true;
                    break;
                }
            }
            if (!clienteEncontrado) {
                JOptionPane.showMessageDialog(null, "Cliente não encontrado");
            }
        }
    }

    private static void pesquisarClientePessoaFisicaPeloCpf(ArrayList<ClientePessoaFisica> clientePessoaFisicaList) {
        if (clientePessoaFisicaList.isEmpty()) {
            JOptionPane.showMessageDialog(null, "Nenhum cliente cadastrado");
        } else {
            String cpfDdd = JOptionPane.showInputDialog("Digite o DDD do CPF");
            String cpfNumero = JOptionPane.showInputDialog("Digite o número do CPF");
            boolean clienteEncontrado = false;

            for (ClientePessoaFisica cliente : clientePessoaFisicaList) {
                if (cliente != null &&
                        cliente.getCpf().getDdd() == Integer.parseInt(cpfDdd) &&
                        cliente.getCpf().getNumero() == Long.parseLong(cpfNumero)) {
                    JOptionPane.showMessageDialog(null, cliente);
                    clienteEncontrado = true;
                    break;
                }
            }

            if (!clienteEncontrado) {
                JOptionPane.showMessageDialog(null, "Cliente não encontrado");
            }
        }
    }

    private static void pesquisarClientePessoaFisicaPeloNumeroDaConta(ArrayList<ClientePessoaFisica> clientePessoaFisicaList) {
        if (clientePessoaFisicaList.isEmpty()) {
            JOptionPane.showMessageDialog(null, "Nenhum cliente cadastrado");
        } else {
            int numeroDaConta = Integer.parseInt(JOptionPane.showInputDialog("Digite o número da conta"));
            boolean contaEncontrada = false;
            StringBuilder titularDaConta = new StringBuilder();
            titularDaConta.append("O titular da conta: \n");
            for (ClientePessoaFisica cliente : clientePessoaFisicaList) {
                if (cliente != null) {
                    for (Conta conta : cliente.getContas()) {
                        if (conta != null && conta.getNumero() == numeroDaConta) {
                            titularDaConta.append("Nome: ").append(cliente.getNome()).append("\n")
                                    .append("CPF: ").append(cliente.getCpf()).append("\n")
                                    .append("Agência: ").append(conta.getAgencia().getNome()).append("\n")
                                    .append("Número da conta: ").append(conta.getNumero()).append("\n")
                                    .append("Saldo: R$").append(conta.getSaldo()).append("\n");
                            contaEncontrada = true;
                            break;
                        }
                    }
                }
                if (contaEncontrada) {
                    break;
                }
            }

            if (contaEncontrada) {
                JOptionPane.showMessageDialog(null, titularDaConta);
            } else {
                JOptionPane.showMessageDialog(null, "Ninguém tem esta conta");
            }
        }
    }


    private static void listarTodosOsClientesDeUmaMesmaAgencia(ArrayList<ClientePessoaFisica> clientePessoaFisicaList) {
        if (clientePessoaFisicaList.isEmpty()) {
            JOptionPane.showMessageDialog(null, "Nenhum cliente cadastrado");
        } else {

            StringBuilder agencia = new StringBuilder()
                    .append("Escolha a agência").append("\n");

            for (int j = 0; j < Agencia.getAgencias().length; j++) {
                agencia.append(j + 1).append(" - ").append(Agencia.getAgencias()[j].getNome()).append("\n");
            }
            boolean agenciaAdicionada = false;
            Agencia agenciaEscolhida = null;
            while (!agenciaAdicionada) {
                switch (Integer.parseInt(JOptionPane.showInputDialog(agencia))) {
                    case 1:
                        agenciaEscolhida = Agencia.getAgencias()[0];
                        agenciaAdicionada = true;
                        break;
                    case 2:
                        agenciaEscolhida = Agencia.getAgencias()[1];
                        agenciaAdicionada = true;
                        break;
                    case 3:
                        agenciaEscolhida = Agencia.getAgencias()[2];
                        agenciaAdicionada = true;
                        break;
                    default:
                        JOptionPane.showMessageDialog(null, "Opção inválida");
                }
            }

            boolean clienteEncontrado = false;
            StringBuilder clientesDaAgencia = new StringBuilder();
            clientesDaAgencia.append("Os clientes da agência ").append(agenciaEscolhida.getNome()).append(" são: \n");
            for (ClientePessoaFisica cliente : clientePessoaFisicaList) {
                if (cliente != null) {
                    for (Conta conta : cliente.getContas()) {
                        if (conta != null &&
                                conta.getAgencia() != null &&
                                conta.getAgencia().getNumero() == Objects.requireNonNull(agenciaEscolhida).getNumero()) {
                            clientesDaAgencia.append("Nome: ").append(cliente.getNome()).append(" - ").append("CPF: ").append(cliente.getCpf()).append("\n");
                            clienteEncontrado = true;
                        }
                    }
                }
            }
            if (clienteEncontrado) {
                JOptionPane.showMessageDialog(null, clientesDaAgencia);
            } else {
                JOptionPane.showMessageDialog(null, "Ninguém tem conta nesta agência");
            }
        }
    }

    private static void listarTodosOsClientes(ArrayList<ClientePessoaFisica> clientePessoaFisicaList) {
        if (clientePessoaFisicaList.isEmpty()) {
            JOptionPane.showMessageDialog(null, "Nenhum cliente cadastrado");
        } else {
            for (ClientePessoaFisica cliente : clientePessoaFisicaList) {
                if (cliente != null) {
                    JOptionPane.showMessageDialog(null, cliente);
                }
            }
        }
    }

    public static List<Conta> adicionarContas() {
        List<Conta> contas = new ArrayList<>();
        int numeroContas = Integer.parseInt(JOptionPane.showInputDialog("Digite o número de contas do cliente"));
        for (int i = 0; i < numeroContas; i++) {
            StringBuilder agencia = new StringBuilder()
                    .append("Escolha a agência da conta ").append(i + 1).append("\n");

            for (int j = 0; j < Agencia.getAgencias().length; j++) {
                agencia.append(j + 1).append(" - ").append(Agencia.getAgencias()[j].getNome()).append("\n");
            }
            boolean agenciaAdicionada = false;
            Agencia agenciaEscolhida = null;
            while (!agenciaAdicionada) {
                switch (Integer.parseInt(JOptionPane.showInputDialog(agencia))) {
                    case 1:
                        agenciaEscolhida = Agencia.getAgencias()[0];
                        agenciaAdicionada = true;
                        break;
                    case 2:
                        agenciaEscolhida = Agencia.getAgencias()[1];
                        agenciaAdicionada = true;
                        break;
                    case 3:
                        agenciaEscolhida = Agencia.getAgencias()[2];
                        agenciaAdicionada = true;
                        break;
                    default:
                        JOptionPane.showMessageDialog(null, "Opção inválida");
                }
            }

            StringBuilder tipoConta = new StringBuilder()
                    .append("Escolha o tipo da conta ").append(i + 1).append("\n")
                    .append("1 - Conta Corrente\n")
                    .append("2 - Conta Especial\n");
            boolean contaAdicionada = false;

            int numeroConta = LocalTime.now().getNano() % 1000000 / 100;

            while (!contaAdicionada) {
                switch (Integer.parseInt(JOptionPane.showInputDialog(tipoConta))) {
                    case 1:
                        contas.add(new ContaCorrente(numeroConta, 0, agenciaEscolhida));
                        contaAdicionada = true;
                        break;
                    case 2:
                        contas.add(new ContaEspecial(numeroConta, 0, agenciaEscolhida));
                        contaAdicionada = true;
                        break;
                    default:
                        JOptionPane.showMessageDialog(null, "Opção inválida");
                }
            }

        }
        return contas;
    }
}

