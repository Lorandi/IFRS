package entities;

public class Curso {
    private String titulo;
    private int pontuacao;
    private Categoria categoria;

    public Curso(String titulo, int pontuacao, Categoria categoria) {
        this.titulo = titulo;
        this.pontuacao = pontuacao;
        this.categoria = categoria;
    }

    public String getTitulo() {
        return titulo;
    }

    public int getPontuacao() {
        return pontuacao;
    }

    public Categoria getCategoria() {
        return categoria;
    }

}
