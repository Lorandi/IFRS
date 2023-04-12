package entities;

import java.util.List;

public class Homeopata extends Medico{

    public Homeopata(String CRM, Float salarioBasico) {
        super(CRM, salarioBasico);
    }

    @Override
    public Float ganhoExtra() {
        return this.getSalarioBasico() * 0.1f;
    }

    @Override
    public String getTipo(){
        return "Hommeopata";
    }
}
