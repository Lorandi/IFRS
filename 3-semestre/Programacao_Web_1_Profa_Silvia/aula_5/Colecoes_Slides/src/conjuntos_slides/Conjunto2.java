package conjuntos_slides;
import java.util.*;

public class Conjunto2 {

    public static void main(String[] args) {
    	LinkedHashSet<String> cidades = new LinkedHashSet<String>();
        cidades.add("Porto Alegre");
        cidades.add("Canoas");
        cidades.add("Alvorada");
        cidades.add("Viamão");
        for (String cidade : cidades) {
            System.out.println(cidade);
        }

    }

}
