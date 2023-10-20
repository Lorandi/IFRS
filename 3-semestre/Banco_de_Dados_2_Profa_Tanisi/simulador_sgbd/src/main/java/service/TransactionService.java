package service;

import entities.Transaction;

import java.util.HashMap;
import java.util.Scanner;

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

    public void showTransactions() {
        System.out.println("Transações: ");
        for (Transaction transaction : transactions.values()) {
            System.out.println("[" + transaction.getId() + "] - " + transaction);
        }
    }

    public void chooseTransaction() {
        Scanner scanner = new Scanner(System.in);
        showTransactions();
        System.out.print("Escolha uma transação: ");
        String option = scanner.nextLine();
        Transaction transaction = transactions.get(Integer.parseInt(option));
        System.out.println("Transação escolhida: " + transaction);

    }
}
