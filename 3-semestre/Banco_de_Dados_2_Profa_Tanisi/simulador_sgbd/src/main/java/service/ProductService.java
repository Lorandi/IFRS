package service;

import entities.Database;
import entities.Product;
import enums.Category;

import java.math.BigDecimal;
import java.util.HashMap;
import java.util.Scanner;

import static validators.Validators.*;

public class ProductService {

    private static HashMap<Integer, Product> products;

    public ProductService(HashMap<Integer, Product> products) {

        this.products = products;
    }

    public static void addProduct() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nome do produto: ");
        String name = sc.nextLine();

        boolean registerItem = true;
        for (Product product : products.values()) {
            if (product.getName().equals(name)) {
                System.out.println("Produto com este nome já cadastrado. Utilize o menu Editar para modificar produto\n");
                registerItem = false;
                editProduct();
            }
        }

        if (registerItem) {
            while (name.isEmpty()) {
                System.out.print("Nome do produto: ");
                name = sc.nextLine();
            }

            BigDecimal price = validateBigDecimal("");

            Integer quantity = validateIntegers();

            Category category = validateCategory("");

            if (confirmOperation()) {
                saveOnDatabase(name, price, quantity, category);

            } else {
                System.out.println("Operação cancelada");
            }
        }
        Database.getInstance().showStockListInMemory();
    }

    public static void editProduct() {
        Database.getInstance().showStockListInMemory();

        if (!products.isEmpty()) {
            Scanner sc = new Scanner(System.in);
            Product produtcOnStock = searchProductOnStock();


            // Produto criado caso operação seja cancelada
            Product productTemp = produtcOnStock;


            System.out.print("Qual dado quer modificar: [1]Nome [2]Preço [3]Quantidade [4]Categoria :");

            String data = sc.next();
            boolean checkData = data.equals("1") || data.equals("2") || data.equals("3") || data.equals("4");

            while (!checkData) {
                System.out.println("Dado inválido");
                System.out.print("Qual dado quer modificar: [1]Nome [2]Preço [3]Quantidade [4]Categoria :");

                data = sc.next();
                checkData = data.equals("1") || data.equals("2") || data.equals("3") || data.equals("4");
            }

            switch (data) {
                case "1":
                    sc.nextLine();
                    System.out.print("Digite o novo nome: ");
                    String newNane = sc.nextLine();
                    produtcOnStock.setName(newNane);
                    break;

                case "2":
                    BigDecimal newPrice = validateBigDecimal("");
                    produtcOnStock.setPrice(newPrice);
                    break;

                case "3":
                    Integer newQuantity = validateIntegers();
                    produtcOnStock.setQuantity(newQuantity);
                    break;

                default:
                    Category category = validateCategory("");
                    produtcOnStock.setCategory(category);
            }

            System.out.println("\nProduto modificado \n"
                    + "Id: " + produtcOnStock.getId() + ", "
                    + "Nome: " + produtcOnStock.getName() + ", "
                    + "Preço: " + produtcOnStock.getPrice() + ", "
                    + "Quantidade: " + produtcOnStock.getQuantity() + ", "
                    + "Categoria: " + produtcOnStock.getCategory().getDescription() + "\n");

            if (confirmOperation()) {
                System.out.println("Operação realizada com sucesso");

            } else {
                switch (data) {
                    case "1":
                        produtcOnStock.setName(productTemp.getName());
                        break;

                    case "2":
                        produtcOnStock.setPrice(productTemp.getPrice());
                        break;

                    case "3":
                        produtcOnStock.setQuantity(productTemp.getQuantity());
                        break;

                    default:
                        produtcOnStock.setCategory(productTemp.getCategory());
                }
                System.out.println("Operação cancelada");
            }
        } else {
            System.out.println("Lista ainda não tem produtos");
        }
        Database.getInstance().showStockListInMemory();
    }

    public static void removeProduct() {
        if (products.size() >= 1) {
            Database.getInstance().showStockListInMemory();
            Product produtcOnStock = searchProductOnStock();

            if (confirmOperation()) {
                Database.getInstance().removeProduct(produtcOnStock);
                System.out.println("Produto excluído");
            } else {
                System.out.println("Operação cancelada");
            }
        } else {
            System.out.println("Não é possível excluir itens da lista");
        }
        Database.getInstance().showStockListInMemory();
    }
}