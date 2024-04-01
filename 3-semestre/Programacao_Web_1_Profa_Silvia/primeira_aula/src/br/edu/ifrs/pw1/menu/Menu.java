package br.edu.ifrs.pw1.menu;

import br.edu.ifrs.pw1.clientes.ClientePessoaFisica;
import br.edu.ifrs.pw1.contatos.Endereco;
import br.edu.ifrs.pw1.documentos.Cpf;

import javax.swing.*;
import java.util.ArrayList;
import java.util.List;

public class Menu {
    public static void main(String[] args) {
        ArrayList<ClientePessoaFisica> clientePessoaFisicaList = new ArrayList<>();
        //Criar um menu com as seguintes opções:
        //1-cadastrar cliente pessoa física
        //2-pesquisar cliente pessoa física pelo nome
        //3-pesquisar cliente pessoa física pelo cpf
        //4-pesquisar cliente pessoa física pelo endereço
        //5-listar todos os alunos
        //6-sair

        while (true) {
            switch (montaMenu()) {
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
                    pesquisarClientePessoaFisicaPeloEndereco(clientePessoaFisicaList);
                    break;
                case 5:
                    listarClientesPessoaFisica(clientePessoaFisicaList);
                    break;
                case 6:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Opção inválida");
            }
        }
    }

    private static int montaMenu() {
        String menu = "1-cadastrar cliente pessoa física\n" +
                "2-pesquisar cliente pessoa física pelo nome\n" +
                "3-pesquisar cliente pessoa física pelo cpf\n" +
                "4-pesquisar cliente pessoa física pelo endereço\n" +
                "5-listar todos os clientes\n" +
                "6-sair";
        return Integer.parseInt(JOptionPane.showInputDialog(menu));
    }

    private static ClientePessoaFisica cadastrarClientePessoaFisica() {
        String nome = JOptionPane.showInputDialog("Digite o nome do cliente");
        String telefone = JOptionPane.showInputDialog("Digite o telefone do cliente");
        String cpf = JOptionPane.showInputDialog("Digite o cpf do cliente");
        String digito = JOptionPane.showInputDialog("Digite o cpf do digito");
        int numeroEnderecos = Integer.parseInt(JOptionPane.showInputDialog("Digite o número de endereços do cliente"));
        List<Endereco> enderecos = new ArrayList<>();
        for (int i = 0; i < numeroEnderecos; i++) {
            String logradouro = JOptionPane.showInputDialog("Digite a rua do logradouro");
            String complemento = JOptionPane.showInputDialog("Digite o número do complemento");
            String cep = JOptionPane.showInputDialog("Digite o complemento do cep");
            enderecos.add(new Endereco(logradouro, complemento, Long.parseLong(cep)));
        }
        return new ClientePessoaFisica(telefone, enderecos, nome, new Cpf(Long.parseLong(cpf), Integer.parseInt(digito)));
    }

    private static void listarClientesPessoaFisica(ArrayList<ClientePessoaFisica> clientePessoaFisicaList) {
        for (ClientePessoaFisica clientePessoaFisica : clientePessoaFisicaList) {
            if (clientePessoaFisica != null) {
                JOptionPane.showMessageDialog(null, clientePessoaFisica);
            }
        }
        if(clientePessoaFisicaList.isEmpty()){
            JOptionPane.showMessageDialog(null, "Nenhum cliente cadastrado");
        }
    }

    private static void pesquisarClientePessoaFisicaPeloNome(ArrayList<ClientePessoaFisica> clientePessoaFisicaList) {
        String nome = JOptionPane.showInputDialog("Digite o nome do cliente");
        boolean achou = false;
        for (ClientePessoaFisica cli : clientePessoaFisicaList) {
            if (cli != null && cli.getNome().toLowerCase().equals(nome.toLowerCase())) {
                JOptionPane.showMessageDialog(null, cli);
                achou = true;
                break;
            }
        }
        if (!achou) {
            JOptionPane.showMessageDialog(null, "Cliente não encontrado");
        }
    }

    private static void pesquisarClientePessoaFisicaPeloCpf(ArrayList<ClientePessoaFisica> clientePessoaFisicaList) {
        String cpfNumero = JOptionPane.showInputDialog("Digite o cpf do cliente");
        String cpfDigito = JOptionPane.showInputDialog("Digite o digito do cpf do cliente");
        boolean achou = false;
        for (ClientePessoaFisica cli : clientePessoaFisicaList) {
            if (cli != null &&
                    cli.getCpf().getNumero() == Long.parseLong(cpfNumero) &&
                    cli.getCpf().getDigito() == Integer.parseInt(cpfDigito)) {
                JOptionPane.showMessageDialog(null, cli);
                achou = true;
                break;
            }
        }
        if (!achou) {
            JOptionPane.showMessageDialog(null, "Cliente não encontrado");
        }
    }

    private static void pesquisarClientePessoaFisicaPeloEndereco(ArrayList<ClientePessoaFisica> clientePessoaFisicaList) {
        String logradouro = JOptionPane.showInputDialog("Digite o logradouro do endereço");
        boolean achou = false;
        String moraNoEndereco = "";
        if(clientePessoaFisicaList.isEmpty()){
            JOptionPane.showMessageDialog(null, "Nenhum cliente cadastrado");
        }
        for (ClientePessoaFisica cli : clientePessoaFisicaList) {
            if (cli != null) {
                for (Endereco end : cli.getEnderecos()) {
                    if (end != null && end.getLogradouro().toLowerCase().equals(logradouro.toLowerCase())) {
//                        JOptionPane.showMessageDialog(null, cli);
                        moraNoEndereco += cli.getNome() + "\n";
                        achou = true;
                    }
                }
            }
            if (achou) {
                JOptionPane.showMessageDialog(null, moraNoEndereco + "mora no endereço");
            }else {
                JOptionPane.showMessageDialog(null, "Ninguém mora no endereço");
            }
        }
    }
}
