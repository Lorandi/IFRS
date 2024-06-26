package org.example.figura;

import org.example.cor.Cor;

public abstract class Figura {
    private Cor cor;

    public abstract double calcularArea();

    public abstract double calcularPerimetro();

    public Figura(Cor cor) {
        this.cor = cor;
    }

    public Figura() {
    }

    @Override
    public String toString() {
        return cor != null ? cor.toString() + "\n" : "Sem cor definida.\n";
    }
}
