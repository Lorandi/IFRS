package mapas_slides;
import java.util.*;

public class MapaValores {
    public static void main(String[] args) {
        LinkedHashMap<Integer, String> map = new LinkedHashMap<>();
        map.put(1, "um");
        map.put(2, "dois");
        map.put(3, "três");
        //obtendo valores
        Collection<String> valores = map.values();
        for (String valor : valores) {
            System.out.println(valor);
        }
    }
}
