package br.edu.ifrs.pw1.clientes;

import br.edu.ifrs.pw1.contatos.Endereco;
import br.edu.ifrs.pw1.documentos.Cpf;

import java.util.List;

public class ClientePessoaFisica extends Cliente {
    private String nome;
    private Cpf cpf;

    public ClientePessoaFisica() {
    }

    public ClientePessoaFisica(String nome, Cpf cpf) {
        this.nome = nome;
        this.cpf = cpf;
    }

    public ClientePessoaFisica(String telefone, String nome, Cpf cpf) {
        super(telefone);
        this.nome = nome;
        this.cpf = cpf;
    }

    public ClientePessoaFisica(String telefone, List<Endereco> enderecos, String nome, Cpf cpf) {
        super(telefone, enderecos);
        this.nome = nome;
        this.cpf = cpf;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Cpf getCpf() {
        return cpf;
    }

    public void setCpf(Cpf cpf) {
        this.cpf = cpf;
    }

    @Override
    public String toString() {
        return "ClientePessoaFisica: " + '\n' +
                "  nome='" + nome + '\n' +
                "  cpf=" + (cpf != null ? cpf.toString():"Cpf inválido") + '\n' +
                "  " + super.toString();
    }
}
