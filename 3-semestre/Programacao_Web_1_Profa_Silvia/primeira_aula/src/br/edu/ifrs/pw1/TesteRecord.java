package br.edu.ifrs.pw1;

public record TesteRecord(String nome, String apelido) {
    public TesteRecord(String nome, String apelido) {
        this.nome = nome;
        this.apelido = apelido;
    }


}
