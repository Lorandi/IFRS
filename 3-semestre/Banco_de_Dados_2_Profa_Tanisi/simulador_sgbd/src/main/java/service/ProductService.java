package service;

import entities.Database;
import entities.Logs;
import entities.Product;
import entities.Transaction;

import java.math.BigDecimal;
import java.util.HashMap;
import java.util.Scanner;

import static java.util.Objects.isNull;
import static validators.Validators.*;

public class ProductService {

    private static HashMap<Integer, Product> products;

    public ProductService(HashMap<Integer, Product> products) {

        this.products = products;
    }

//    public static void addProduct() {
//        Scanner sc = new Scanner(System.in);
//        System.out.print("Nome do produto: ");
//        String name = sc.nextLine();
//
//        boolean registerItem = true;
//        for (Product product : products.values()) {
//            if (product.getName().equals(name)) {
//                System.out.println("Produto com este nome já cadastrado. Utilize o menu Editar para modificar produto\n");
//                registerItem = false;
//                editProduct();
//            }
//        }
//
//        if (registerItem) {
//            while (name.isEmpty()) {
//                System.out.print("Nome do produto: ");
//                name = sc.nextLine();
//            }
//
//            BigDecimal price = validateBigDecimal("");
//
//            Integer quantity = validateIntegers();
//
//
//            if (confirmOperation()) {
//                saveOnDatabase(name, price, quantity);
//
//            } else {
//                System.out.println("Operação cancelada");
//            }
//        }
//        Database.getInstance().showStockListInMemory();
//    }

    public static void editProduct(Transaction transaction) {
        if (isNull(transaction) ) return;

        Database.getInstance().showStockListInMemory();
        StringBuilder log = new StringBuilder();
        log.append(transaction.getName()+", ");

        if (!products.isEmpty()) {
            Scanner sc = new Scanner(System.in);
            Product produtcOnStock = searchProductOnStock();


            // Produto criado caso operação seja cancelada
            Product productTemp = new Product(produtcOnStock.getId(), produtcOnStock.getName(), produtcOnStock.getPrice(), produtcOnStock.getQuantity());
            log.append(produtcOnStock.getId()+", ");

            System.out.print("Qual dado quer modificar: [1]Nome [2]Preço [3]Quantidade :");

            String data = sc.next();
            boolean checkData = data.equals("1") || data.equals("2") || data.equals("3") ;

            while (!checkData) {
                System.out.println("Dado inválido");
                System.out.print("Qual dado quer modificar: [1]Nome [2]Preço [3]Quantidade :");

                data = sc.next();
                checkData = data.equals("1") || data.equals("2") || data.equals("3") ;
            }

            switch (data) {
                case "1":
                    sc.nextLine();
                    System.out.print("Digite o novo nome: ");
                    String newNane = sc.nextLine();
                    produtcOnStock.setName(newNane);
                    log.append("nome, ");
                    log.append(productTemp.getName() + ", ");
                    log.append(produtcOnStock.getName());
                    break;

                case "2":
                    BigDecimal newPrice = validateBigDecimal("");
                    produtcOnStock.setPrice(newPrice);
                    log.append("preço, ");
                    log.append(productTemp.getPrice() + ", ");
                    log.append(produtcOnStock.getPrice());
                    break;

                case "3":
                    Integer newQuantity = validateIntegers();
                    produtcOnStock.setQuantity(newQuantity);
                    log.append("quantidade, ");
                    log.append(productTemp.getQuantity() + ", ");
                    log.append(produtcOnStock.getQuantity());
                    break;
            }

            System.out.println("\nProduto modificado \n"
                    + "Id: " + produtcOnStock.getId() + ", "
                    + "Nome: " + produtcOnStock.getName() + ", "
                    + "Preço: " + produtcOnStock.getPrice() + ", "
                    + "Quantidade: " + produtcOnStock.getQuantity() + "\n");

            if (confirmOperation()) {
                Logs.getInstance().persistLogBuffer(log.toString());
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
                }
                System.out.println("Operação cancelada");
            }
        } else {
            System.out.println("Lista ainda não tem produtos");
        }
        Database.getInstance().showStockListInMemory();
    }

//    public static void removeProduct() {
//        if (products.size() >= 1) {
//            Database.getInstance().showStockListInMemory();
//            Product produtcOnStock = searchProductOnStock();
//
//            if (confirmOperation()) {
//                Database.getInstance().removeProduct(produtcOnStock);
//                System.out.println("Produto excluído");
//            } else {
//                System.out.println("Operação cancelada");
//            }
//        } else {
//            System.out.println("Não é possível excluir itens da lista");
//        }
//        Database.getInstance().showStockListInMemory();
//    }
}