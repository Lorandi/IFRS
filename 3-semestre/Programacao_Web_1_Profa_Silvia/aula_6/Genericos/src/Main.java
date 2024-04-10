import genericos.Par;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        System.out.println("Testando a classe Par mês");
        Par<Integer, String> mes = new Par<>();
        mes.setPrimeiro(1);
        mes.setSegundo("Janeiro");
        System.out.println(mes.toString());
        mes.setPrimeiro(2);
        mes.setSegundo("Fevereiro");
        System.out.println(mes.toString());
        System.out.println("\n");

        System.out.println("Testando a classe Par nome_nota");
        Par<String, Double> nome_nota = new Par<>();
        nome_nota.setPrimeiro("João");
        nome_nota.setSegundo(8.5);
        System.out.println(nome_nota.toString());
        nome_nota.setPrimeiro("Maria");
        nome_nota.setSegundo(9.7);
        System.out.println(nome_nota.toString());

        System.out.println("\n");
        System.out.println("Testando a classe Par coodernadas");
        Par<Float, Float> coordenadas = new Par<>(10.5f, 20.5f);
        System.out.println(coordenadas.toString());
        coordenadas.setPrimeiro(30.5f);
        coordenadas.setSegundo(40.5f);
        System.out.println(coordenadas.toString());
        System.out.println("\n");

        System.out.println("Testando a classe Par lista de coordenadas");
        ArrayList<Par<Float, Float>> listaCoordenadas = new ArrayList<>();
        listaCoordenadas.add(new Par<>(10.5f, 20.5f));
        listaCoordenadas.add(new Par<>(30.5f, 40.5f));
        listaCoordenadas.add(new Par<>(50.5f, 60.5f));
        listaCoordenadas.add(new Par<>(70.5f, 80.5f));
        listaCoordenadas.forEach(coordenada -> System.out.println(coordenada.toString()));


    }
}