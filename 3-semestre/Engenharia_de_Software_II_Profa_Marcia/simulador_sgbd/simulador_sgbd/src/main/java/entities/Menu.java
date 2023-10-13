package entities;

import enums.OptionsMenu;
import service.ProductService;

import java.util.*;

public class Menu {

    HashMap<Integer, Product> products;
    ProductService productService;

    public Menu(){
        Database.getInstance().readFromFile();
        this.products = Database.getInstance().recoverProducts();
        this.productService = new ProductService(products);
    }

    public void menu(){
        Scanner sc = new Scanner(System.in);

        String menu = "\n     - - - MENU - - - \n" +
                "[1] Adicionar Novo Produto \n" +
                "[2] Editar Produto\n" +
                "[3] Excluir Produto\n" +
                "[4] Importar Mostruário da Fábrica\n" +
                "[5] Sair\n" +
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

            case IMPORT_SHOWCASE:
                ProductService.importShowcase();
                break;

            case EXIT:
                System.out.println("Até logo!!!");
                break;

            default:
                System.out.println("\nOpção inválida. É necessário escolher uma das opções numéricas do menu.");
        }
        if (!option.equals("5")) {
            menu();
        }
        sc.close();
    }
}