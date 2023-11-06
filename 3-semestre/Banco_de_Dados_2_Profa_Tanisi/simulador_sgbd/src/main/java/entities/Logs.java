package entities;


import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Logs {

    public static final List<String> logsBuffer = new ArrayList<>();
    public static final List<String> logsMemory = new ArrayList<>();
    private static final Logs logs = new Logs();

    public Logs() {
    }

    public static Logs getInstance() {
        return logs;
    }

    public void persistLogBuffer(String string) {
        logsBuffer.add(string);
    }

    public void removeLogBuffer(String string) {
        logsBuffer.remove(string);
    }

    public void showLogsBuffer() {
        System.out.println("\n Lista de logs no buffer:");
        if (logsBuffer.isEmpty()) {
            System.out.println(" Buffer vazio");
        }
        for (String log : logsBuffer) {
            System.out.println(log);
        }
    }

    public void showLogsMemory() {
        logsFromMemory();
        System.out.println("\n Lista de logs em memória");
        for (String log : logsMemory) {
            System.out.println(log);
        }
    }


    private void logsFromMemory() {
        String path = "src/resources/files/logs.csv";

        try (BufferedReader br = new BufferedReader(new FileReader(path))) {
            String line = br.readLine(); //atribuido valor para ler a primeira linha com os nomes dos parâmentros

            while ((line = br.readLine()) != null) {
                logsMemory.add(line);
            }
        } catch (FileNotFoundException e) {
            System.out.println("arquivo não encontrado");
            e.printStackTrace();
        } catch (IOException e) {
            System.out.println("problema na leitura do arquivo");
            e.printStackTrace();
        }
    }

    public void saveLogsOnMemory() {
        String path = "src/resources/files/logs.csv";

        try (BufferedWriter bw = new BufferedWriter(new FileWriter(path))) {
            bw.write("cod_trans, id_produto, nome_campo, valor_anterior, valor_atual");
            bw.newLine();
            for (String log : logsMemory) {
                bw.write(log);
                bw.newLine();
            }
            for (String log : logsBuffer) {
                bw.write(log);
                bw.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void checkPoint() {
        String path = "src/resources/files/logs.csv";

        List<String> checkPoint = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(path))) {
            String line = br.readLine(); //atribuido valor para ler a primeira linha com os nomes dos parâmentros

            while ((line = br.readLine()) != null) {
                checkPoint.add(line);
            }
        } catch (FileNotFoundException e) {
            System.out.println("arquivo não encontrado");
            e.printStackTrace();
        } catch (IOException e) {
            System.out.println("problema na leitura do arquivo");
            e.printStackTrace();
        }

        try (BufferedWriter bw = new BufferedWriter(new FileWriter(path))) {
            bw.write("cod_trans, id_produto, nome_campo, valor_anterior, valor_atual");
            bw.newLine();
            for(String log : checkPoint){
                bw.write(log);
                bw.newLine();
            }

            bw.write("CheckPoint");
            bw.newLine();

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

}