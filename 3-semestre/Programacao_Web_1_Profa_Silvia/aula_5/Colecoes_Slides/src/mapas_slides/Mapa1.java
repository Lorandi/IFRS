package mapas_slides;
import java.util.*;

public class Mapa1 {
    public static void main(String[] args) {
        Map<String, Integer> map = new HashMap<>();
        map.put("um", 1);
        map.put("dois", 2);
        map.put("tres", 3);
        map.put(String.valueOf(4), 4);
        System.out.println(map.get("um"));
        System.out.println(map.get("4"));
        System.out.println();

        //pegar todas as chaves do mapa
        Set<String> chaves = map.keySet();
        chaves.forEach(System.out::println);
        System.out.println();

        Collection<Integer> valores = map.values();
        valores.forEach(System.out::println);
        System.out.println();

        //imprimir todas as chaves e valores
        Set<Map.Entry<String, Integer>> entradas = map.entrySet();
        for (Map.Entry<String, Integer> entrada : entradas) {
            System.out.println(entrada.getKey() + " -> " + entrada.getValue());
        }
    }
}
