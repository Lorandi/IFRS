package entities;

import enums.OptionsMenu;
import enums.TransactionsMenu;
import service.ProductService;
import service.TransactionService;

import java.util.HashMap;
import java.util.Scanner;

import static entities.Database.productsBuffer;
import static enums.TransactionsMenu.START_TRANSACTION;

public class Menu {

    HashMap<Integer, Product> products;
    ProductService productService;

    TransactionService transactionService;

    public Menu(){
        Database.getInstance().productsBuffer(productsBuffer);
        this.products = Database.getInstance().recoverProducts();
        this.productService = new ProductService(products);
        this.transactionService = new TransactionService(TransactionService.transactions);

    }

    public void menu(){
        Scanner sc = new Scanner(System.in);

        String menu = "\n     - - - MENU PRINCIPAL- - - \n" +
                "[1] Transações \n" +
                "[2] Log memória\n"+
                "[3] Log disco\n"+
                "[4] Banco memória\n" +
                "[5] Banco disco\n" +
                "[6] Falha\n" +
                "[7] Sair\n" +
                "Digite o número da opção desejada: ";
        System.out.print(menu);
        String option = sc.nextLine();

        switch (OptionsMenu.getByCode(option)) {
            case TRANSACTION:
                transactionMenu();
                break;

            case LOG_BUFFER:
                break;

            case LOG_DISC:
                break;

            case DATABASE_BUFFER:
                Database.getInstance().showStockListInMemory();
                break;

            case DATABASE_DISC:
                Database.getInstance().showSavedInDatabase();
                break;

            case FAIL:
                break;

            case EXIT:
                System.out.println("Até logo!!!");
                break;

            default:
                System.out.println("\nOpção inválida. É necessário escolher uma das opções numéricas do menu.");
        }
        if (!option.equals("7")) {
            menu();
        }
        sc.close();
    }

    public void transactionMenu(){
        Scanner scanner = new Scanner(System.in);

        String menu = "\n     - - - MENU DE TRANSAÇÕES- - - \n" +
                "[1] Começar transação \n" +
                "[2] Escolher transação\n"+
                "[3] Finalizar transação\n"+
                "[4] Commit\n" +
                "[5] Voltar para menu principal\n" +
                "Digite o número da opção desejada: ";
        System.out.print(menu);
        String option = scanner.nextLine();

        switch (TransactionsMenu.getByCode(option)) {
            case START_TRANSACTION:

                System.out.println("\n" + transactionService.addTransaction() + " criada com sucesso!");
                break;

            case CHOOSE_TRANSACTION:
                transactionService.chooseTransaction();
                break;

            case END_TRANSACTION:
                break;

            case COMMIT:
                break;

            case BACK:
                System.out.println("Voltando para menu principal...");
                break;

            default:
                System.out.println("\nOpção inválida. É necessário escolher uma das opções numéricas do menu.");
        }
        if (!option.equals("5")) {
            transactionMenu();
        }
    }
}