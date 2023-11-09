package service;

import entities.Logs;
import entities.Recovery;

import java.io.*;
import java.time.Instant;
import java.util.ArrayList;
import java.util.List;

import static service.LogsService.logsFromDatabase;
import static utils.Constants.CABECALHO;

public class RecoveryService {
    private static final Recovery recovery = Recovery.getInstance();
    private static final List<String> listUndo = recovery.getListUndo();
    private static final List<String> listRedo = recovery.getListRedo();

    public static void addToListUndo(String undo){
        recovery.persistListUndo(undo);
    }

    public static void addToListRedo(String redo){
        recovery.persistListRedo(redo);
    }



    public static void recoveryFromDatabaseLogs(){
        List<String> transactions = Logs.getInstance().getLogsDatabase();

        List<String> iniciadas =new ArrayList<>();
        List<String> finalizadas =new ArrayList<>();


        if(transactions.isEmpty()){
            logsFromDatabase();
        }

        for(int i = transactions.size(); i > 0;  i--){
            String[] temp = transactions.get(i-1).split(",");

            if(temp[0].equals("finaliza")){
                finalizadas.add(temp[1]);
            }

            if(!finalizadas.contains(temp[1]) &&
                    (temp[0].equals("inicia") ||temp[0].equals("update"))){
                iniciadas.add(transactions.get(i-1));

                if(!listUndo.contains(temp[1])) addToListUndo(temp[1]);
            }
        }

        System.out.println("\nLista ativas na falha");
        for(String st : iniciadas){
            System.out.println(st);
        }

        System.out.println("\nFinalizadas na falha:");
        System.out.println(finalizadas);


        System.out.println("\nLista undo");
        for(String st : listUndo){
            System.out.println(st);
        }


        System.out.println("\nLista redo");
        for(String st : listRedo){
            System.out.println(st);
        }



    }

}
