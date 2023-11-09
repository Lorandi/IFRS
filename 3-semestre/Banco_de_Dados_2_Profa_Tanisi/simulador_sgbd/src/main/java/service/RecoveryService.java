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

        if(transactions.isEmpty()){
            logsFromDatabase();
        }

        for(String st : transactions){
            String[] temp = st.split(",");
            if(!temp[0].equals("checkpoint")){
                addToListUndo(st);
                //TODO criar lista das finalizadas
            }
        }
        for(String st : listUndo){
            System.out.println(st);
        }
    }

}
