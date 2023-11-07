package entities;

import enums.OptionsMenu;
import enums.TransactionsMenu;
import service.ProductService;
import service.TransactionService;

import java.util.HashMap;
import java.util.Scanner;

import static entities.Database.productsBuffer;


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
                "[2] Log buffer\n"+
                "[3] Log disco\n"+
                "[4] Banco buffer\n" +
                "[5] Banco disco\n" +
                "[6] Check point\n" +
                "[7] Falha\n" +
                "[8] Sair\n" +
                "Digite o número da opção desejada: ";
        System.out.print(menu);
        String option = sc.nextLine();

        switch (OptionsMenu.getByCode(option)) {
            case TRANSACTION:
                transactionMenu();
                break;

            case LOG_BUFFER:
                Logs.getInstance().showLogsBuffer();
                break;

            case LOG_DISC:
                Logs.getInstance().showLogsMemory();
                break;

            case DATABASE_BUFFER:
                Database.getInstance().showStockListInMemory();
                break;

            case DATABASE_DISC:
                Database.getInstance().showSavedInDatabase();
                break;

            case CHECK_POINT:
                Logs.getInstance().saveLogsOnMemory();
                Database.getInstance().saveOnFile();
                Logs.getInstance().checkPoint();

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
                "[3] Finalizar transação (commit)\n"+
                "[4] Voltar para menu principal\n" +
                "Digite o número da opção desejada: ";
        System.out.print(menu);
        String option = scanner.nextLine();

        switch (TransactionsMenu.getByCode(option)) {
            case START_TRANSACTION:

                System.out.println("\n" + transactionService.startTransaction() + " criada com sucesso!");
                break;

            case CHOOSE_TRANSACTION:
                ProductService.editProduct(transactionService.chooseTransaction());
                break;

            case END_TRANSACTION:
                transactionService.finishTransaction(transactionService.chooseTransaction());
                break;

            case BACK:
                System.out.println("\n Voltando para menu principal...\n");
                break;

            default:
                System.out.println("\nOpção inválida. É necessário escolher uma das opções numéricas do menu.");
        }
        if (!option.equals("4")) {
            transactionMenu();
        }
    }
}