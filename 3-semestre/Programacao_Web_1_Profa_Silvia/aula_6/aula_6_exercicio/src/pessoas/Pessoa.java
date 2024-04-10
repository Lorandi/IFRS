package pessoas;

import contatos.Telefone;

import java.util.LinkedList;

public class Pessoa {
    private String nome;
    private LinkedList<Telefone> telefone = new LinkedList<>();

    public Pessoa() {
    }

    public Pessoa(String nome, LinkedList<Telefone> telefone) {
        this.nome = nome;
        this.telefone = telefone;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public LinkedList<Telefone> getTelefone() {
        return telefone;
    }

    public void addTelefone(Telefone telefone) {
        this.telefone.add(telefone);
    }

    @Override
    public String toString() {
        StringBuilder aux = new StringBuilder();
        for (Telefone t : telefone) {
            if(telefone != null){
                aux.append(t.toString()).append("\n");
            }
        }
        if(aux.isEmpty()){
            aux.append("Sem telefones cadastrados.");
        }

        return "Nome: " + nome + "\n" +
               "Telefone: " + aux + "\n";
    }
}
