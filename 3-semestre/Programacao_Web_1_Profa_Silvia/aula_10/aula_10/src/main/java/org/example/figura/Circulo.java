package org.example.figura;

import org.example.cor.Cor;

import java.util.Objects;

public class Circulo extends Figura implements Comparable<Circulo>{
    private double raio;

    //private static final double PI = 3.14159;


    public Circulo() {
    }

    public Circulo(double raio, Cor cor) {
        super(cor);
        this.raio = raio;
    }

    @Override
    public double calcularArea() {
        return Math.PI * Math.pow(raio, 2);
    }

    @Override
    public double calcularPerimetro() {
        return 2 * Math.PI * raio;
    }

    @Override
    public String toString() {
        //retornar a cor, raio, area e perimetro
        return "Circulo: " + "raio=" + raio + ", area=" + calcularArea() + ", perimetro=" + calcularPerimetro() + ", " + super.toString();
    }

    @Override
    public int compareTo(Circulo o) {
        return Double.compare(this.calcularArea(), o.calcularArea());
    }
}
