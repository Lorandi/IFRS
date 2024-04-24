import java.io.*;

//determina que a classe Arquivo vai salvar objetos do tipo T
public class Exercicio11<T> {
    private ObjectOutputStream saida;
    private ObjectInputStream entrada;
    private String nomeArq;

    public Exercicio11(String nome) {
        nomeArq = nome;
    }

    public void abrir(String tipo) {
        if (tipo.equals("w")) { // abre para gravação
            try {
                saida = new ObjectOutputStream(new FileOutputStream(nomeArq));
                System.out.println("Aberto para Gravação");
            } catch (FileNotFoundException e) {
                System.out.println("Arquivo de escrita não encontrado");
            } catch (SecurityException e) {
                System.out.println("Sem permissão para escrever no arquivo");
            } catch (IOException e) {
                System.out.println("Erro ao abrir para gravação");
            } catch (NullPointerException e) {
                System.out.println("Objeto de escrita nulo");
            }
        } else { // abre para leitura
            try {
                entrada = new ObjectInputStream(new FileInputStream(nomeArq));
                System.out.println("Aberto para Leitura");
            } catch (FileNotFoundException e) {
                System.out.println("Arquivo de leitura não encontrado");
            } catch (SecurityException e) {
                System.out.println("Sem permissão para ler o arquivo");
            } catch (IOException e) {
                System.out.println("Erro ao abrir para leitura");
            }
        }
    }

    public void gravarObjeto(T obj) {
        try {
            saida.writeObject(obj);
        } catch (InvalidClassException e) {
            System.out.println("Problema com a classe usada na serialização");
        } catch (NotSerializableException e) {
            System.out.println("Objeto a ser serializado não implementa Serializable");
        } catch (IOException e) {
            System.out.println("Erro ao gravar objeto");
        }
    }

    public T lerObjeto() {
        try {
            return (T) entrada.readObject();
        } catch (ClassNotFoundException e) {
            System.out.println("Classe do objeto lido não encontrada");
        } catch (InvalidClassException e) {
            System.out.println("Classe inválida");
        } catch (StreamCorruptedException e) {
            System.out.println("Objeto no arquivo está corrompido");
        } catch (OptionalDataException e) {
            System.out.println("Não é objeto, é tipo primitivo");
        } catch (IOException e) {
            System.out.println("Erro ao ler objeto");
        }
        return null;
    }

    public void fechar() {
        if(saida != null) {
            try {
                saida.close();
            } catch (IOException e) {
                System.out.println("Erro ao fechar arquivo de escrita");
            }
        }
        if(entrada != null) {
            try {
                entrada.close();
            } catch (IOException e) {
                System.out.println("Erro ao fechar arquivo de leitura");
            }
        }
    }
}
