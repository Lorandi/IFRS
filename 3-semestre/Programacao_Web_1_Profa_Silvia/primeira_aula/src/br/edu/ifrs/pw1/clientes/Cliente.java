package br.edu.ifrs.pw1.clientes;

import br.edu.ifrs.pw1.contatos.Endereco;

import java.util.ArrayList;
import java.util.List;

public class Cliente {
    private String telefone;

    private List<Endereco> enderecos;

    public Cliente() {
    }

    public Cliente(String telefone) {
        this.telefone = telefone;
    }

    public Cliente(String telefone, List<Endereco> enderecos) {
        this.telefone = telefone;
        this.enderecos = enderecos;
    }

    public String getTelefone() {
        return telefone;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }

    public List<Endereco> getEnderecos() {
        return enderecos;
    }


    public void addEnderecos(Endereco endereco) {
        if (this.enderecos == null) {
            this.enderecos = new ArrayList<>();
        }
        this.enderecos.add(endereco);
    }


    @Override
    public String toString() {

        var aux = "";
        var num = 1;
        StringBuilder st = new StringBuilder();

        if (enderecos != null) {
            for (Endereco end : enderecos) {
                if (end != null) {
                    st.append("   ").append(num).append(": ").append(end).append("\n");
                    num++;
                }
            }
        } else {
            st.append("Sem endereços");
        }


        return "telefone='" + telefone + ", \n" +
                "Enderecos= \n" + st;
    }
}
