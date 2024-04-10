package testesCollections;

import javax.swing.*;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Testes1 {
    //criar uma lista de números inteiros
    //preencher a lista usando o método fill
    //ordenar a lista
    //realizar a pesquisa de um valor da lista



    public static void main(String[] args) {
        //criar uma lista de números inteiros
        List<Integer> numeros = Arrays.asList(9,3,5,1,7,8,2,4,6,0);
        imprimeLista(numeros);

        int buscar = 8;
        //realizar a pesquisa de um valor da lista desordenada
        int posicao = Collections.binarySearch(numeros, buscar);
        System.out.println("Posição do número " + buscar + ": " + posicao);


        //preencher a lista usando o método fill
        //Collections.fill(numeros, numeros.get(0));

         List<Integer> ordenados = numeros.stream().sorted().toList();
         imprimeLista(numeros);
         imprimeLista(ordenados);
        //ordenar a lista
        Collections.sort(numeros);
        imprimeLista(numeros);

        //BinarySearch
        int search = Collections.binarySearch(numeros, 3);
        System.out.println("Posição do número 3: " + search);



        //realizar a pesquisa de um valor da lista
        posicao = Collections.binarySearch(numeros, buscar);
        System.out.println("Posição do número " + buscar + ": " + posicao);

        posicao = Collections.binarySearch(numeros, 5);
        System.out.println("Posição do número 5: " + posicao);
    }

    private static void imprimeLista(List<Integer> lista){
        String aux = "";
        for (Integer numero : lista) {
            aux += numero + " ";
        }
        System.out.println(aux);
//        JOptionPane.showMessageDialog(null, aux);
    }
}
