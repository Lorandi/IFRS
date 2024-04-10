import java.util.Set;

public class TesteOrdenacao1 {
	public static void main(String[] args) {
//		java.util.TreeMap<Integer, Cpf> mapaCpfs = new java.util.TreeMap();
//		mapaCpfs.put(1, new Cpf(1, 1));
//		mapaCpfs.put(5, new Cpf(5, 5));
//		mapaCpfs.put(3, new Cpf(3, 3));
//		java.util.Set<Integer> chaves = mapaCpfs.keySet();
//		for (Integer chave : chaves) {
//			if (chave != null)
//				System.out.println(chave);
//		}

		java.util.TreeMap<Cpf, Integer> mapaCpfs = new java.util.TreeMap();
		mapaCpfs.put( new Cpf(1, 1),1);
		mapaCpfs.put( new Cpf(5, 5),5);
		mapaCpfs.put(new Cpf(3, 3),3);
		Set<Cpf> chaves = mapaCpfs.keySet();
		for (Cpf chave : chaves) {
			if (chave != null)
				System.out.println(chave);
		}
	}
}
