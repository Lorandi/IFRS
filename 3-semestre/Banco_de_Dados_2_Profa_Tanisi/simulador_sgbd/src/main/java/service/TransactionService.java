package service;

import entities.Transaction;
import enums.TransactionStatus;

import java.util.HashMap;
import java.util.Scanner;

import static java.util.Objects.isNull;

public class TransactionService {
    public static HashMap<Integer, Transaction> transactions = new HashMap<>();

    public TransactionService(HashMap<Integer, Transaction> transactions) {
        this.transactions = transactions;
    }

    public Transaction addTransaction() {
        Transaction transaction = new Transaction();
        transactions.put(transaction.getId(), transaction);
        return transaction;
    }


    public void finishTransaction(Transaction transaction) {
        if(isNull(transaction)) return;

        if(transaction.getStatus().equals(TransactionStatus.STARTED)){
            transaction.setStatus(TransactionStatus.FINISHED);
            System.out.println(transaction.getName() + ": finalizada");
        } else{
            System.out.println("\n Transação já finalizada ou inexistente \n");
        }
    }

    public void showTransactions() {
        System.out.println("Transações: ");
        for (Transaction transaction : transactions.values()) {
            if (transaction.getStatus().equals(TransactionStatus.STARTED)) {
                System.out.println("[" + transaction.getId() + "] - " + transaction);
            }
        }
    }

    public Transaction chooseTransaction() {
        Scanner scanner = new Scanner(System.in);
        if (transactions.values().isEmpty()) {
            System.out.println("\n Não há transações iniciadas \n");

        } else {
            showTransactions();
            System.out.print("Escolha uma transação: ");
            String option = scanner.nextLine();
            Transaction transaction = transactions.get(Integer.parseInt(option));

            if(isNull(transaction)){
                System.out.println("Transação inexistente");
                return null;
            }


            System.out.println("Transação escolhida: " + transaction);

            return transaction;
        }

        return null;

    }
}
