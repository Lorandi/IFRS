import java.util.*;

public class Exercicio6 {
    public static void main(String args[]) {
        TreeSet<Number> numeros = new TreeSet<>();
        numeros.add(5);
        numeros.add(8);
//        numeros.add(2.3);//.ClassCastException
        numeros.add(7);
//        numeros.add(null);//.NullPointerException
        for(Number num : numeros)
            System.out.println("Num: " + num);
    }

}


