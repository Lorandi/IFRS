package contas;

public class ContaEspecial extends Conta {
    private double limite;
    private double MIN_SALDO = 200.0;

    public ContaEspecial() {
    }

    public ContaEspecial(double limite) {
        this.limite = limite;
    }

    public ContaEspecial(int numero, double saldo, Agencia agencia) {
        super(numero, saldo, agencia);
    }

    public ContaEspecial(int numero, double saldo, Agencia agencia, double limite) {
        super(numero, saldo, agencia);
        this.limite = limite;
    }

    public double getLimite() {
        return limite;
    }

    public void setLimite(double limite) {
        this.limite = limite;
    }

    public double getMIN_SALDO() {
        return MIN_SALDO;
    }

    public void setMIN_SALDO(double MIN_SALDO) {
        this.MIN_SALDO = MIN_SALDO;
    }

    @Override
    public void debitar(double valor) {
        if (valor > 0) {
            if (this.getSaldo() + this.limite - valor >= MIN_SALDO) {
                this.setSaldo(this.getSaldo() - valor);
            } else {
                System.out.println("\nSaldo insuficiente");
            }
        } else {
            System.out.println("\nValor inválido");
        }
    }

    @Override
    public String toString() {
        return "Conta Corrente\n" +
                getAgencia() +
                "\nNúmero da conta = " + getNumero() +
                "\nSaldo = R$" + getSaldo() +
                "\nLimite = R$" + limite +
                "\nSaldo Mínimo = R$" + MIN_SALDO;
    }
}
