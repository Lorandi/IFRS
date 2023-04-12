package entities;


import java.util.List;

public class Especialista extends Medico{

    public Especialista(String CRM, Float salarioBasico) {
        super(CRM, salarioBasico);
    }

    @Override
    public Float ganhoExtra() {
        float salarioBasico = this.getSalarioBasico();

        float extraDosCursos = 0;
        for(Curso curso : this.getCursos()){
            extraDosCursos += curso.getPontuacao() * 10f;
        }
        return extraDosCursos;
    }

    @Override
    public String getTipo(){
        return "Especialista";
    }
}
