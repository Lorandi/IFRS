package contas;

public class ContaCorrente extends Conta {
    private final double MIN_SALDO = 100.0;

    public ContaCorrente() {
    }

    public ContaCorrente(int numero, double saldo, Agencia agencia) {
        super(numero, saldo, agencia);
    }

    @Override
    public void debitar(double valor) {
        if (valor > 0) {
            if (this.getSaldo() - valor >= MIN_SALDO) {
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
                "\nSaldo Mínimo = R$" + MIN_SALDO;
    }
}
