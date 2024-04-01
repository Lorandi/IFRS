import br.edu.ifrs.pw1.clientes.Cliente;
import br.edu.ifrs.pw1.clientes.ClientePessoaFisica;
import br.edu.ifrs.pw1.contatos.Endereco;
import br.edu.ifrs.pw1.documentos.Cpf;

public class Main {
    public static void main(String[] args) {

        Endereco end1 = new Endereco("rua", "casa", 45);
        Endereco end2 = new Endereco("rua", "casa", 47);
        Endereco end3 = new Endereco();

        Cliente cl1 = new Cliente("(51) 345454545");

        cl1.addEnderecos(end1);
        cl1.addEnderecos(end3);
        cl1.addEnderecos(null);
        cl1.addEnderecos(end2);
        System.out.println(cl1);

        ClientePessoaFisica clientePessoaFisica = new ClientePessoaFisica("51-32232233", "Joselito", new Cpf(99333331,41));
        clientePessoaFisica.addEnderecos(end1);
        clientePessoaFisica.addEnderecos(end3);
        System.out.println(clientePessoaFisica);

    }
}
