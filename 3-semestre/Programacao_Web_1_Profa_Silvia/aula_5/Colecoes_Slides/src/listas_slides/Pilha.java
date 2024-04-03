package listas_slides;

import java.util.LinkedList;

public class Pilha {
    public static void main(String args[]) {

        LinkedList<Number> numeros = new LinkedList<>();
        push(numeros, 10);
        push(numeros, 20.8);
        push(numeros, 30L);
        print(numeros);

        //colocar 3 objetos na pilha, remover 1 e dizer se a pilha esta vazia usando o size
        pop(numeros);
        System.out.println(isEmpty(numeros));
        print(numeros);

    }

    public static void push(LinkedList<Number> numeros, Number n){
        numeros.addFirst(n);
    }

    public static Number pop(LinkedList<Number> numeros){
        return numeros.removeFirst();
    }

    public static String isEmpty(LinkedList<Number> numeros){
        return numeros.size() == 0 ? "Pilha vazia" : "Pilha não vazia";
    }

    public static void print(LinkedList<Number> numeros){
        System.out.println("Pilha: ");
        for (Number number : numeros) {
            System.out.println(number);
        }
    }

}
