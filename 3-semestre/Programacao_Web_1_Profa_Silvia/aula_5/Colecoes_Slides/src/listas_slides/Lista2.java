/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package listas_slides;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

public class Lista2 {
    public static void main(String args[]) {
        LinkedList<Number> numeros = new LinkedList<>();
        numeros.add(10);
        numeros.add(20.8);
        numeros.add(30L);
        numeros.add(23.5F);
        numeros.addLast(29.5F);
        numeros.addFirst(21.5F);
        numeros.addFirst(18.5F);

        for (Number number : numeros) {
            System.out.println(number);
        }
        System.out.println();

        numeros.removeFirst();
        numeros.removeLast();
        numeros.remove();//remove o primeiro elemento

        for (Number number : numeros) {
            System.out.println(number);
        }
        System.out.println();


        //outra forma de percorrer uma lista � usando o padr�o de projeto Iterator
        Iterator<Number> iter = numeros.iterator();
        while (iter.hasNext()) {
            System.out.println(iter.next());
        }

        //imprimir elemento na posicao 2
        System.out.println(numeros.get(2));
    }
}

