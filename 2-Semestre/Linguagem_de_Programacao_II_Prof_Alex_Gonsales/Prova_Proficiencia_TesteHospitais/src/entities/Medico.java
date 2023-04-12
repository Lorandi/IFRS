package entities;

import java.util.ArrayList;
import java.util.List;

public abstract class Medico {
    private String CRM;
    private Float salarioBasico;
    private List<Curso> cursos = new ArrayList<>();

    public Medico(String CRM, Float salarioBasico) {
        this.CRM = CRM;
        this.salarioBasico = salarioBasico;
    }

    public String getCRM() {
        return CRM;
    }

    public Float getSalarioBasico() {
        return salarioBasico;
    }

    public void registraCusrso(Curso curso) {
        this.cursos.add(curso);
    }

    public List<Curso> getCursos() {
        return cursos;
    }

    public float salarioTotal() {

        return this.salarioBasico + this.ganhoExtra() + this.retribuicaoPorCurso();
    }

    public int quantCursos() {
        return cursos.size();
    }

    public float retribuicaoPorCurso() {
        return this.quantCursos() * 100f;
    }

    public abstract Float ganhoExtra();

    public List<Curso> cursosPorCategoria(Categoria categoria) {
        List<Curso> cursosPorCategoria = new ArrayList<>();
        for (Curso curso : this.getCursos()) {
            if (curso.getCategoria().equals(categoria)) {
                cursosPorCategoria.add(curso);
            }
        }
        return cursosPorCategoria;
    }

    public String getTipo(){
        return "";
    }
}
