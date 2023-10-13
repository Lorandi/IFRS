package entities;

import enums.Category;
import service.ProductService;

import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class Menu {

    List<Product> products = new ArrayList<>();
    ProductService productService = new ProductService(products);

    public Menu() {
        this.products = products;
        this.productService = productService;
    }

    public void menu() {
        Scanner sc = new Scanner(System.in);
        Locale.setDefault(Locale.US);


        String menu = "\n     - - - MENU - - - \n" +
                "[1] Adicionar Novo Produto \n" +
                "[2] Editar Produto\n" +
                "[3] Excluir Produto\n" +
                "[4] Importar Mostruário da Fábrica\n" +
                "[5] Sair\n" +
                "Digite o número da opção desejada: ";
        System.out.print(menu);
        Integer opcao = sc.nextInt();

        Boolean verificaOpcao = opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4 || opcao == 5;

        while (!verificaOpcao) {
            System.out.println("\nOpção inválida\n");
            System.out.print(menu);
            opcao = sc.nextInt();
            verificaOpcao = opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4 || opcao == 5;
        }

        if(opcao == 1){
            productService.addProduct();
        } else if(opcao == 2){
            productService.editProduct();
        }else if(opcao == 3){
            productService.removeProduct();
        } else if(opcao == 4){
            productService.importMostruario();
        } else{
            System.out.println("Até logo!!!");
        }

        if(opcao != 5){
            menu();
        }

    }
}
