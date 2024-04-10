
public class TesteOrdenacao2 {
	public static void main(String[] args) {
		java.util.TreeSet<Cpf> conjuntoCpfs = new java.util.TreeSet();
		conjuntoCpfs.add(new Cpf(1, 1));
		conjuntoCpfs.add(new Cpf(5, 5));
		conjuntoCpfs.add(new Cpf(3, 3));
		conjuntoCpfs.add(new Cpf(2, 2));
		for (Cpf conjuntoCpf : conjuntoCpfs) {
			if (conjuntoCpf != null)
				System.out.println(conjuntoCpf.toString());
		}
	}
}
