
public class TesteOrdenacao3 {
	public static void main(String[] args) {
		ComparatorCpf comparador = new ComparatorCpf();
		java.util.TreeSet<Cpf> conjunto = new java.util.TreeSet(comparador);
		conjunto.add(new Cpf(5, 5));
		conjunto.add(new Cpf(2, 2));
		System.out.println(conjunto);
	}
}
