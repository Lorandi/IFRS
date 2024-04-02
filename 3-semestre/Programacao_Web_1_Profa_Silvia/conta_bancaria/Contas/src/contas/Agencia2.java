package contas;

public class Agencia2 {
    private String nome;
    private long numero;

    public Agencia2() {
    }

    public Agencia2(String nome, long numero) {
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
    public static Agencia2[] getAgencias(){
        Agencia2[] agencias = new Agencia2[3];
        agencias[0] = new Agencia2("Agência Centro", 10);
        agencias[1] = new Agencia2("Agência Zona Norte", 20);
        agencias[2] = new Agencia2("Agência Zona Sul", 30);
        return agencias;
    }

    public static Agencia2 getAgenciaByNumero(long numero){
        Agencia2[] agencias = getAgencias();
        for (Agencia2 agencia : agencias) {
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
