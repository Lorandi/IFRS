package contas;

public class Agencia {
    private String nome;
    private long numero;

    public Agencia() {
    }

    public Agencia(String nome, long numero) {
        this.nome = nome;
        this.numero = numero;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public long getNumero() {
        return numero;
    }

    public void setNumero(long numero) {
        this.numero = numero;
    }


    //criar um metodo statico que retorna a lista de agencias
    public static Agencia[] getAgencias(){
        Agencia[] agencias = new Agencia[3];
        agencias[0] = new Agencia("Agência Centro", 10);
        agencias[1] = new Agencia("Agência Zona Norte", 20);
        agencias[2] = new Agencia("Agência Zona Sul", 30);
        return agencias;
    }

    public static Agencia getAgenciaByNumero(long numero){
        Agencia[] agencias = getAgencias();
        for (Agencia agencia : agencias) {
            if(agencia.getNumero() == numero){
                return agencia;
            }
        }
        return null;
    }



    @Override
    public String toString() {
        return  nome + ",  número=" + numero;
    }
}
