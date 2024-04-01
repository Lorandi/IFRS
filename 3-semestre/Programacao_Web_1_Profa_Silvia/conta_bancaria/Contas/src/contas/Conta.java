package contas;

public abstract class Conta {
    private int numero;
    private double saldo;
    private Agencia agencia;

    public Conta() {
    }

    public Conta(int numero, double saldo, Agencia agencia) {
        this.numero = numero;
        this.saldo = saldo;
        this.agencia = agencia;
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public double getSaldo() {
        return saldo;
    }

    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    public Agencia getAgencia() {
        return agencia;
    }

    public void setAgencia(Agencia agencia) {
        this.agencia = agencia;
    }

    public void creditar(double valor) {
        if(valor > 0){
            this.saldo += valor;
        }else{
            throw new IllegalArgumentException("Valor inválido");
        }

    }
    public abstract void debitar(double valor);

    @Override
    public String toString() {
        return "Contas{" +
                "numero=" + numero +
                ", saldo=" + saldo +
                ", agencia=" + agencia +
                '}';
    }
}
