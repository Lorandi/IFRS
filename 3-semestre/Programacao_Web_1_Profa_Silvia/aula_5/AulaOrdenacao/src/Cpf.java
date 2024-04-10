

public class Cpf implements Comparable<Cpf>{
	//atributos
	private long numero;
	private int digito;
	//construtores
	public Cpf() {}
	public Cpf(long numero, int digito) {
		this.numero = numero;
		this.digito = digito;
	}
	public long getNumero() {
		return numero;
	}
	public void setNumero(long numero) {
		this.numero = numero;
	}
	public int getDigito() {
		return digito;
	}
	public void setDigito(int digito) {
		this.digito = digito;
	}
	@Override
	public String toString() {
		return "Cpf: "+ numero + "-" + digito;
	}
	@Override
	public int compareTo(Cpf o) {
        return Long.compare(this.getNumero(), o.getNumero());
//		if(this.getNumero() > o.getNumero()) return 1;
//		if(this.getNumero() < o.getNumero()) return -1;
//		return 0;
    }
	
	
}
