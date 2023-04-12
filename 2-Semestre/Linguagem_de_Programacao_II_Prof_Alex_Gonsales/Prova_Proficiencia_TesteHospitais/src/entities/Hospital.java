package entities;

import java.util.ArrayList;
import java.util.List;

public class Hospital {
    private String nome;
    private List<Medico> medicos = new ArrayList<>();

    public Hospital(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public void registraMed(Medico medico){
        medicos.add(medico);
    }

    public List<Medico> getMedicos() {
        return medicos;
    }

    public Float despesaTotal() {

        Float despesaTotal = 0f;


        for(Medico medico : this.getMedicos()){
            despesaTotal +=medico.salarioTotal();
        }
        return despesaTotal;
    }

}
