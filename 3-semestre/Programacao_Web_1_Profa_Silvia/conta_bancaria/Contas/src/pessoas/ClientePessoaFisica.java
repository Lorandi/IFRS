package pessoas;

import contas.Conta;
import documentos.Cpf;

import java.util.ArrayList;
import java.util.List;

public class ClientePessoaFisica {
    private String nome;
    private static int contador = 0;
    private Cpf cpf;
    private List<Conta> contas;



    public ClientePessoaFisica() {
        contador++;
    }

    public ClientePessoaFisica(String nome, Cpf cpf) {
        this.nome = nome;
        this.cpf = cpf;
        contador++;
    }

    public ClientePessoaFisica(String nome, Cpf cpf, List<Conta> contas) {
        this.nome = nome;
        this.cpf = cpf;
        this.contas = contas;
        contador++;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setCpf(Cpf cpf) {
        this.cpf = cpf;
    }

    public Cpf getCpf() {
        return cpf;
    }

    public static int getContador() {
        return contador;
    }

    public List<Conta> getContas() {
        return contas;
    }

    public void addConta(Conta conta) {
        if (this.contas == null) {
            this.contas = new ArrayList<>();
        }
        this.contas.add(conta);
    }

    @Override
    public String toString() {
        var aux = "";
        var num = 1;
        StringBuilder st = new StringBuilder();

        if (contas != null) {
            for (Conta conta : contas) {
                if (conta != null) {
                    st.append(num).append(" : ").append(conta).append("\n\n");
                    num++;
                }
            }
        } else {
            st.append("Sem contas");
        }


        return "Cliente Pessoa Fisica: " + '\n' +
                "Nome=" + nome + '\n' +
                "CPF=" + (cpf != null ? cpf.toString() : "Cpf inválido") +
                '\n' + st;
    }
}
