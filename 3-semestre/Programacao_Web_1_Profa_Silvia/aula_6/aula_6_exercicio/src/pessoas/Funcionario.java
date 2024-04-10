package pessoas;

import contatos.Telefone;
import documentos.Cpf;

import java.util.LinkedList;
import java.util.Objects;

public class Funcionario extends Pessoa implements Comparable<Funcionario> {
    private String matricula;
    private double salario;
    private Cpf cpf;

    public Funcionario() {
    }

    public Funcionario(String nome, LinkedList<Telefone> telefones, Cpf cpf, String matricula, double salario) {
        super(nome, telefones);
        this.cpf = cpf;
        this.matricula = matricula;
        this.salario = salario;
    }

    public Funcionario(String nomeFuncionario) {
        super(nomeFuncionario, new LinkedList<>());
    }

    public String getMatricula() {
        return matricula;
    }

    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    public Cpf getCpf() {
        return cpf;
    }

    public void setCpf(Cpf cpf) {
        this.cpf = cpf;
    }

    @Override
    public String toString() {
        return "Funcionario{" +
                "nome='" + getNome() + "\t\t" +
                ", telefones=" + getTelefone() + "\t" +
                ", cpf=" + cpf + "\t" +
                ", matricula='" + matricula +  "\t" +
                ", salario=" + salario +
                '}';
    }

    @Override
    public int compareTo(Funcionario outro) {
        if (this.getNome() == null && outro.getNome() == null) {
            return 0;
        } else if (this.getNome() == null) {
            return -1;
        } else if (outro.getNome() == null) {
            return 1;
        } else {
            return this.getNome().compareTo(outro.getNome());
        }
    }

}
