package documentos;

public final class Cpf {
    private int ddd;
    private long numero;

    public Cpf() {
    }
    public Cpf(int ddd, long numero) {
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

    public void setNumero(int numero) {
        this.numero = numero;
    }

    @Override
    public String toString() {
        return " {ddd=" + ddd + ", número=" + numero +"}\n";
    }
}
