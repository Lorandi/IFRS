package contatos;

public class Telefone implements Comparable<Telefone> {
    private int ddd;
    private long numero;

    public Telefone() {
    }

    public Telefone(int ddd, long numero) {
        this.ddd = ddd;
        this.numero = numero;
    }

    public int getDdd() {
        return ddd;
    }

    public void setDdd(int ddd) {
        this.ddd = ddd;
    }

    public long getNumero() {
        return numero;
    }

    public void setNumero(long numero) {
        this.numero = numero;
    }

    @Override
    public String toString() {
        return "Telefone: ("  + ddd + ") " + numero;
    }

    @Override
    public int compareTo(Telefone o) {
        return Long.compare(numero, o.getNumero());
    }
}
