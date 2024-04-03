package mapas_slides;
import java.util.*;

public class Mapa2 {
    public static void main(String[] args) {
        TreeMap<String, Integer> map = new TreeMap<>();
        map.put("cinco", 5);
        map.put("dois", 2);
        map.put("tres", 3);
        
        Set<String> chaves = map.keySet();
        for (String chave : chaves) {
            System.out.print("Chave => " + chave);
            System.out.println(" - Valor=>" + map.get(chave));
        }  
        
        System.out.println("--------------------------------");
        
        TreeMap<Integer, String> map2 = new TreeMap<>();
        map2.put(5, "cinco");
        map2.put(2, "dois");
        map2.put(3, "tres");
        
        Set<Integer> chaves2 = map2.keySet();
        for (Integer chave : chaves2) {
            System.out.print("Chave => " + chave);
            System.out.println(" - Valor=>" + map2.get(chave));
        }       
    }
}
