import javax.swing.*;
import java.io.*;
import java.nio.charset.Charset;
import java.nio.file.*;
import java.nio.file.attribute.BasicFileAttributes;
import java.util.*;

public class ListaExercicioArquivosExcecoes {
    public static void main(String[] args) {
//        exercicio1();
//        exercicio2();
//        exercicio3();
//        exercicio4();
//        exercicio5();

    }

    private static void exercicio5() {
        //gravando caracteres e Strings
        try (FileWriter fw = new FileWriter("Ex5.txt")) {
            fw.write('2');
            fw.write("2");
//            fw.flush();
//            fw.close(); // pode comentar por usar o try-with-resources
        } catch (FileNotFoundException e) {
            System.out.println("FileNotFoundException - Arquivo de escrito não encontrado");
        } catch (IOException e) {
            System.out.println("IOException - Exceção no arquivo de escrita");
            e.printStackTrace();
        }

        try (FileReader fr = new FileReader("Ex5.txt")) {   //usando try-with-resources
            int c = fr.read();
            while (c != -1) {
                System.out.print((char) c);
                c = fr.read();
            }
        } catch (NullPointerException e) {
            System.out.println("NullPointerException - Objeto de leitura do arquivo nulo");
        } catch (FileNotFoundException e) {
            System.out.println("FileNotFoundException - Arquivo de leitura não encontrado");
        } catch (IOException e) {
            System.out.println("IOException - Exceção no arquivo de leitura");
            e.printStackTrace();
        }

    }

    private static void exercicio4() {
        Scanner entrada = new Scanner(System.in);
        System.out.printf("Informe o número para a tabuada:\n");
        try (PrintWriter gravarArq = new PrintWriter(new FileWriter("tabuada.txt"));) {
            int n = entrada.nextInt();
//        System.out.printf("Informe a pasta:\n");
//        String pasta = entrada.nextLine();

//            FileWriter arq = new FileWriter("tabuada.txt");
//            PrintWriter gravarArq = new PrintWriter(arq);

            gravarArq.printf("+--Resultado--+%n");
            for (int i = 1; i <= 10; i++) {
                gravarArq.printf("| %2d X %d = %2d |%n", i, n, (i * n));
            }
            gravarArq.printf("+-------------+%n");
//            gravarArq.close();
//            arq.close()
            System.out.println("\nTabuada do " + n + " foi gravada na " +
                    "tabuada.txt\n");
        } catch (FileNotFoundException e) {
            System.out.println("FileNotFoundException - Arquivo não encontrado");
        } catch (InputMismatchException e) {
            System.out.println("InputMismatchException - Erro ao ler o número");
        } catch (NoSuchElementException e) {
            System.out.println("NoSuchElementException - Erro ao ler o número");
        } catch (IllegalStateException e) {
            System.out.println("IllegalStateException - Scanner fechado");
        } catch (IOException e) {
            System.out.println("IOException - Erro ao gravar o arquivo");
            e.printStackTrace();
        }
    }


    private static void exercicio3() {
        try {
//            Path txt = Paths.get("teste.txt");
            Path txt = Paths.get("C:", "Diretorio", "Teste", "Teste.txt");
            BasicFileAttributes info = Files.readAttributes(txt, BasicFileAttributes.class);
            System.out.format("Data de criação: %s%n", info.creationTime());
            System.out.format("Último acesso: %s%n", info.lastAccessTime());
            System.out.format("Última modificação: %s%n", info.lastModifiedTime());
            System.out.format("É um diretorio: %s%n", info.isDirectory());
            System.out.format("Tamanho: %s bytes%n", info.size());
        } catch (NoSuchFileException e) {
            System.out.println("NoSuchFileException - Arquivo não encontrado");
        } catch (IOException e) {
            System.out.println("IOException - Erro ao ler os atributos do arquivo");
            e.printStackTrace();
        }
    }

    private static void exercicio2() {
        FileSystem fs = FileSystems.getDefault();
        List<String> list = criarListaString();
        Path diretorio = fs.getPath("C:", "Diretorio", "Teste");
        Path arquivo = diretorio.resolve("teste.txt");
        Charset charset = Charset.forName("UTF-8");
        try {
            Files.write(arquivo, list, charset, StandardOpenOption.APPEND);
        } catch (IOException e) {
            System.out.println("IOException - Erro ao escrever no arquivo");
            e.printStackTrace();
        }
        lerArquivo(arquivo, charset);
    }

    private static void exercicio1() {
        FileSystem fs = FileSystems.getDefault();
        Path diretorio = fs.getPath("C:", "Diretorio", "Teste");
        Path arquivo = diretorio.resolve("Teste.txt");
        try {
            Files.createDirectories(diretorio);
            Files.createFile(arquivo);
        } catch (FileAlreadyExistsException e) {
            System.out.println("FileAlreadyExistsException - Arquivo já existe");
            System.out.println(e.getMessage());
        } catch (IOException e) {
            System.out.println("IOException  - Erro ao criar o arquivo");
        }
    }

    public static List<String> criarListaString() {
        List<String> list = new ArrayList<String>();
        list.add("ABC");
        list.add("DEF");
        list.add("GHI");
        list.add("JKL");
        list.add("MNO");
        return list;
    }

    public static void lerArquivo(Path arquivo, Charset charset) {
        try {
            List<String> linhas = Files.readAllLines(arquivo, charset);
            for (String linha : linhas) {
                System.out.println(linha);
            }
        } catch (IOException e) {
            System.out.println("IOException - Erro ao ler o arquivo");
            e.printStackTrace();
        }
    }
}
