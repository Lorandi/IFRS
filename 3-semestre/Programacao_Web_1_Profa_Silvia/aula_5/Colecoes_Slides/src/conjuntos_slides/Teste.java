package conjuntos_slides;

import java.util.HashSet;
import java.util.Set;

public class Teste {
    public static void main(String[] args) {
        //Tarefa: criar 2 cpmjuntos com 3 elementos cada
        //fazer a união, a diferença e a interseccção dos conjuntos
        //usar numeros inteiros

        Set<Integer> conjunto1 = criaConjunto(1);
        System.out.println("Conjunto 1: ");
        imprimeConjunto(conjunto1);

        Set<Integer> conjunto2 = criaConjunto(3);
        System.out.println("Conjunto 2: ");
        imprimeConjunto(conjunto2);

        Set<Integer> uniao = uniaoDoisConjuntos(conjunto1, conjunto2);
        System.out.println("Uniao: ");
        imprimeConjunto(uniao);


        Set<Integer> interseccao = interseccaoConjuntos(conjunto1, conjunto2);
        System.out.println("Interseccao: ");
        imprimeConjunto(interseccao);


        Set<Integer> diferenca = diferencaConjuntos(interseccao, uniao);
        System.out.println("Diferenca: ");
        imprimeConjunto(diferenca);
    }

    private static HashSet<Integer>  criaConjunto(int valorIncial){
        HashSet<Integer> conjunto = new HashSet<>();
        conjunto.add(valorIncial);
        conjunto.add(valorIncial + 1);
        conjunto.add(valorIncial + 2);
        return conjunto;
    }

    private static void imprimeConjunto(Set<Integer> conjunto){
        System.out.println(conjunto);
        System.out.println();
    }

    public static HashSet<Integer>  uniaoDoisConjuntos(Set<Integer> conjunto1, Set<Integer> conjunto2){
        HashSet<Integer> uniao = new HashSet<>();
        uniao.addAll(conjunto2);
        uniao.addAll(conjunto1);
        return uniao;
    }

    public static HashSet<Integer>  interseccaoConjuntos(Set<Integer> conjunto1, Set<Integer> conjunto2){
        HashSet<Integer> interseccao = new HashSet<>(conjunto1);
        interseccao.retainAll(conjunto2);
        return interseccao;
    }

    public static HashSet<Integer>  diferencaConjuntos(Set<Integer> conjunto1, Set<Integer> conjunto2){
        HashSet<Integer> diferenca = new HashSet<>(conjunto2);
        diferenca.removeAll(conjunto1);
        return diferenca;
    }
}
