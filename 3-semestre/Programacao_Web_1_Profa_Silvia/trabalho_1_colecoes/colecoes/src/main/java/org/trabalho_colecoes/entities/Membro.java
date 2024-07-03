package org.trabalho_colecoes.entities;

import org.trabalho_colecoes.enums.SituacaoMatriculaEnum;

import java.io.Serializable;
import java.util.Objects;

public class Membro implements Serializable {

    private String matricula;
    private String nome;

    private SituacaoMatriculaEnum situacao;

    public Membro() {
    }

    public Membro(String matricula, String nome, SituacaoMatriculaEnum situacao) {
        this.matricula = matricula;
        this.nome = nome;
        this.situacao = situacao;
    }

    public String getMatricula() {
        return matricula;
    }

    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public SituacaoMatriculaEnum getSituacao() {
        return situacao;
    }

    public void setSituacao(SituacaoMatriculaEnum situacao) {
        this.situacao = situacao;
    }

    @Override
    public String toString() {
        return "Membro:  " + "Matricula: " + matricula + ", Nome: " + nome + ", Situacao: " + situacao;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Membro membro)) return false;
        return Objects.equals(matricula, membro.matricula);
    }

    @Override
    public int hashCode() {
        return Objects.hash(matricula);
    }
}
