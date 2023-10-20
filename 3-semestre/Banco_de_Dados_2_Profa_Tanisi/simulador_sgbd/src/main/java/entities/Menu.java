package entities;

import enums.OptionsMenu;
import service.ProductService;

import java.util.HashMap;
import java.util.Scanner;

import static entities.Database.productsBuffer;

public class Menu {

    HashMap<Integer, Product> products;
    ProductService productService;

    public Menu(){
        Database.getInstance().productsBuffer(productsBuffer);
        this.products = Database.getInstance().recoverProducts();
        this.productService = new ProductService(products);
    }

    public void menu(){
        Scanner sc = new Scanner(System.in);

        String menu = "\n     - - - MENU - - - \n" +
                "[1] Adicionar Novo Produto \n" +
                "[2] Editar Produto\n" +
                "[3] Excluir Produto\n" +
                "[4] Ver produtos salvos no banco\n" +
                "[5] Ver produtos na memória\n" +
                "[6] Commit\n" +
                "[7] Sair\n" +
                "Digite o número da opção desejada: ";
        System.out.print(menu);
        String option = sc.nextLine();

        switch (OptionsMenu.getByCode(option)) {
            case NEW_PRODUCT:
                ProductService.addProduct();
                break;

            case EDIT_PRODUCT:
                ProductService.editProduct();
                break;

            case REMOVE_PRODUCT:
                ProductService.removeProduct();
                break;

            case SEE_DATABASE:
                Database.getInstance().showSavedInDatabase();
                break;

            case SEE_MEMORY:
                Database.getInstance().showStockListInMemory();
                break;

            case COMMIT:
                Database.getInstance().saveOnFile();
                System.out.println("Commit realizado com sucesso!!!");
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
}