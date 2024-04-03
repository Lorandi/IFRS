package mapas_slides;
import java.util.*;

public class MapaChaves {
    public static void main(String[] args) {
        Map<Integer, String> map = new LinkedHashMap<>();
        map.put(1, "um");
        map.put(2, "dois");
        map.put(3, "três");
        //obtendo as chaves
        
     
        Set<Integer> chaves = map.keySet();
        for (Integer chave : chaves) {
            System.out.println(chave);
        }
        
    }
}
