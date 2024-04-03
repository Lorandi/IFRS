/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package listas_slides;

import java.util.*;

public class Lista1 {
    public static void main(String args[]) {
//            List<Integer> lista = new ArrayList<>();

        Integer i = 17;
        List<Number> lista = new ArrayList<>();
        lista.add(10);
        lista.add(2);
        lista.add(4);
        lista.add(i);
        lista.add(20.0);
        lista.add(30L);
        lista.add(20F);
        lista.add(i);
        lista.add(20);
        System.out.println(lista.size());

//            for(Integer obj: lista) {
        for (Number obj : lista) {
            System.out.println(obj);
        }

        System.out.println();
        System.out.println(lista.indexOf(20));//retorna o indice a primeira ocorrencia
        System.out.println(lista.lastIndexOf(20));//retorna o indice da última ocorrencia

        System.out.println();

        //remover o valor 20F da colecao
        lista.remove(20F);
        lista.remove((Integer)17);

        // remover o valor que está na posição 2
        lista.remove(2);//se passa int, remove pelo índice
        for (Number obj : lista) {
            System.out.println(obj);
        }

    }
}
