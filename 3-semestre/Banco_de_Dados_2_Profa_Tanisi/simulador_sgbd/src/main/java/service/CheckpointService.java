package service;

import entities.Logs;

import java.io.*;
import java.time.Instant;
import java.util.ArrayList;
import java.util.List;

import static utils.Constants.CABECALHO;

public class CheckpointService {
    public static void checkPoint() {
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
            bw.write(CABECALHO);
            bw.newLine();
            for(String log : checkPoint){
                bw.write(log);
                bw.newLine();
            }

            var check = "checkpoint,,,,,,"+ Utils.formatDateTime(Instant.now().getEpochSecond());
            bw.write(check);
            Logs.getInstance().persistLogBuffer(check);
            bw.newLine();

            System.out.println("\nCheckpoint realizado: " + check.substring(16));

        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
