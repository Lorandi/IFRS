package conjuntos_slides;

import java.util.*;

public class TestesConjuntos {
	//exercício para os estudantes
    public static void main(String[] args) {
        //o que a linha abaixo faz?
        SortedSet<Integer> conjOrd = new TreeSet<Integer>(Arrays.asList(2, 3, 5));
        Integer first = conjOrd.first(); //retorna: ?
        //imprimir first
        Integer last = conjOrd.last(); //retorna: ?
        //imprimir last
        conjOrd.add(1); //conjunto resultante = ?
        //imprimir conjOrd
        conjOrd.add(4); //conjunto resultante = ?
        //imprimir conjOrd
        SortedSet<Integer> head = conjOrd.headSet(3); //head = ?
        //imprimir head
        SortedSet<Integer> tail = conjOrd.tailSet(3); //tail = ?
        //imprimir tail
        SortedSet<Integer> subSet = conjOrd.subSet(2, 5); //subSet = ?
        //imprimir subSet
    }
}
