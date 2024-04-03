package conjuntos_slides;

import java.util.*;

public class Conjunto1 {
    public static void main(String[] args) {
        //não permite elementos duplicados
        Set<String> conjunto = new HashSet<>();
        conjunto.add("Dois");
        conjunto.add("Tres");
        conjunto.add("Um");
        conjunto.add("cinco");
        conjunto.add("Cinco");
        conjunto.add("Um");
        conjunto.size();
        for (String num : conjunto) {
            System.out.println(num);
        }
        System.out.println(conjunto);
    }
}
