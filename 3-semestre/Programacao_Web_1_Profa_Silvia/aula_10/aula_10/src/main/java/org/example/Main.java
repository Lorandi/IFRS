package org.example;

import org.example.cor.Cor;
import org.example.figura.Circulo;
import org.example.figura.Figura;
import org.example.figura.Retangulo;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Cor corVermelhao = new Cor(255, 0, 0);
        Cor corAzulzao= new Cor(0, 0, 255);


        Figura figuras[] = new Figura[5];// não estamos instanciando a classe Figura, mas sim um array de Figura
        Figura figuraCirculo = new Circulo(5, corVermelhao);
//        figuras[3].toString();//NullPointerException
        figuras[3] = figuraCirculo;
        figuras[1] = new Circulo();
        figuras[2] = new Retangulo(5, 10, corVermelhao);

        for (Figura figura : figuras) {
            if (figura != null)
                System.out.println(figura.toString());
        }

        for (Figura figura : figuras) {
            if (figura != null){
                System.out.println(figura.calcularArea());
                System.out.println(figura.calcularPerimetro());
            }

            if(figura instanceof Circulo){
                System.out.println(figura.calcularArea());
            }

        }

        System.out.println("----------------------------------------------------");
        System.out.println("ArrayList");

        List<Figura> figurasList = new ArrayList<>(Arrays.asList(figuras));
        figurasList.add(new Retangulo(10, 20, corVermelhao));
        figurasList.add(new Circulo(10, corVermelhao));

        for (Figura figura : figurasList) {
            if (figura != null)
                System.out.println(figura.toString());
        }

        //Exemplo com Map
        System.out.println("----------------------------------------------------");
        System.out.println("Map");
        Map<String, Figura> figurasMap = new HashMap<>();
        figurasMap.put("circulo", new Circulo(10, corVermelhao));
        figurasMap.put("retangulo", new Retangulo(10, 20, corVermelhao));
        figurasMap.put("circulo2", new Circulo(20, corVermelhao));
        figurasMap.put("retangulo2", new Retangulo(20, 30, corVermelhao));
        for (String key : figurasMap.keySet()) {
            System.out.println(figurasMap.get(key).toString());
        }

        //Exemplo com Set
        System.out.println("----------------------------------------------------");
        System.out.println("LinkedList");


        LinkedList<Circulo> figurasLinkedList = new LinkedList<>();
        figurasLinkedList.addFirst(new Circulo(154, corVermelhao));
        figurasLinkedList.addFirst(new Circulo(23, corVermelhao));
        figurasLinkedList.addFirst(new Circulo(55, corVermelhao));
        figurasLinkedList.addFirst(new Circulo(10, corAzulzao));
        figurasLinkedList.addFirst(new Circulo(8, corAzulzao));

        for (Circulo circulo : figurasLinkedList) {
            System.out.println(circulo.toString());
        }

        //Exemplo com TressSet
        System.out.println("----------------------------------------------------");
        System.out.println("TreeSet");

        TreeSet<Circulo> circulos = new TreeSet<>();
        circulos.add(new Circulo(10, corVermelhao));
        circulos.add(new Circulo(20, corVermelhao));
        circulos.add(new Circulo(5, corVermelhao));
        circulos.add(new Circulo(15, null));
        circulos.add(new Circulo(15, corVermelhao));
        circulos.add(new Circulo(10, corVermelhao));
        circulos.add(new Circulo(8, corAzulzao));

        for (Circulo circulo : circulos) {
            System.out.println(circulo.toString());
        }

    }
}
