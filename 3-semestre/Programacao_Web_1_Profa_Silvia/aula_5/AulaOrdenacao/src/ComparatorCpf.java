import java.util.Comparator;

public class ComparatorCpf implements Comparator<Cpf>{

	@Override
	public int compare(Cpf cpf1, Cpf cpf2) {
		if(cpf1.getDigito() > cpf2.getDigito()) return 1;
		if(cpf1.getDigito() < cpf2.getDigito()) return -1;
		return 0;
	}

}
