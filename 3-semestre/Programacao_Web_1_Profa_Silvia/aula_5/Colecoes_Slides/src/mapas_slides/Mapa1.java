package mapas_slides;
import java.util.*;

public class Mapa1 {
    public static void main(String[] args) {
        Map<String, Integer> map = new HashMap<>();
        map.put("um", 1);
        map.put("dois", 2);
        map.put("tres", 3);
        
        Iterator<Integer> it = map.values().iterator();
        while (it.hasNext()) {
            System.out.println((Integer) it.next());
        }
    }
}
