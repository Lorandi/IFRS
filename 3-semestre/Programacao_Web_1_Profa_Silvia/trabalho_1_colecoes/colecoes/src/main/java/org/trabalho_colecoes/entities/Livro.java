package org.trabalho_colecoes.entities;

import java.io.Serializable;
import java.util.Objects;

public class Livro implements Comparable<Livro>, Serializable {
    private String titulo;
    private String autor;
    private String isbn;

    public Livro() {
    }

    public Livro(String titulo, String autor, String isbn) {
        this.titulo = titulo;
        this.autor = autor;
        this.isbn = isbn;
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public String getIsbn() {
        return isbn;
    }

    public void setIsbn(String isbn) {
        this.isbn = isbn;
    }

    @Override
    public String toString() {
        return "Livro: titulo= " + titulo + ", autor= " + autor + ", isbn= " + isbn;
    }

    @Override
    public int compareTo(Livro livro) {
        return CharSequence.compare(this.autor, livro.autor);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Livro livro)) return false;
        return Objects.equals(titulo, livro.titulo);
    }

    @Override
    public int hashCode() {
        return Objects.hash(titulo);
    }
}
