package org.example.figura;

import org.example.cor.Cor;

public class Retangulo extends Figura{
    private double base;
    private double altura;

    public Retangulo() {
    }

    public Retangulo(double base, double altura, Cor cor) {
        super(cor);
        this.base = base;
        this.altura = altura;
    }

    @Override
    public double calcularArea() {
        return base * altura;
    }

    @Override
    public double calcularPerimetro() {
        return 2 * (base + altura);
    }

    @Override
    public String toString() {
        return "Retangulo: " + "base=" + base + ", altura=" + altura + ", area=" + calcularArea() +
                ", perimetro=" + calcularPerimetro() + ", " + super.toString();
    }

}
