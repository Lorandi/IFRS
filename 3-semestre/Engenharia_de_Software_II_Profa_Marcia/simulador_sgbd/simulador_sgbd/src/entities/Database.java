package entities;

import java.util.ArrayList;
import java.util.List;

public class Database {

    private static Database database= new Database();

    public static Database getInstance() {
        return database;
    }

    public Database() {
    }

    private List<Product> products = new ArrayList<>();


    public void persisteProduct(Product product) {
        products.add(product);
    }

    public List<Product> recuperaProduct() {
        return products;
    }

    public void removeProduct(Product product) {
        products.remove(product);
    }

    public void showStockList() {
        System.out.println("\n Lista de produtos");
        for (Product product : products) {
            System.out.println(product.toString());//
        }

    }
}
