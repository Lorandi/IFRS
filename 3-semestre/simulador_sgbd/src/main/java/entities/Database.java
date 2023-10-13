package entities;


import java.io.*;
import java.math.BigDecimal;
import java.util.HashMap;

import static validators.Validators.validateCategory;


public class Database {

    private static final Database database = new Database();

    public static final HashMap<Integer, Product> productsBuffer = new HashMap<>();

    public static final HashMap<Integer, Product> showSavedInDatabase = new HashMap<>();

    public static Database getInstance() {
        return database;
    }

    public Database() {
    }

    public void persistsProduct(Product product) {
        productsBuffer.put(product.getId(), product);
    }

    public HashMap<Integer, Product> recoverProducts() {
        return productsBuffer;
    }

    public void removeProduct(Product product) {
        productsBuffer.remove(product.getId());
    }

    public void showStockListInMemory() {
        System.out.println("\n Lista de produtos");
        for (Product product : productsBuffer.values()) {
            System.out.println(product.toString());
        }
    }

    public void showSavedInDatabase(){
        productsBuffer(showSavedInDatabase);
        System.out.println("\n Lista de produtos");
        for (Product product : showSavedInDatabase.values()) {
            System.out.println(product.toString());
        }
    }

    public HashMap<Integer, Product> productsBuffer(HashMap<Integer, Product> hashMap) {
        String path = "src/resources/files/estoque.csv";

        try (BufferedReader br = new BufferedReader(new FileReader(path))) {
            String line = br.readLine(); //atribuido valor para ler a primeira linha com os nomes dos parâmentros
            String temp[];

            while ((line = br.readLine()) != null) {
                temp = line.split(",(?=([^\"]*\"[^\"]*\")*[^\"]*$)");

                Product product = new Product(Integer.parseInt(temp[0]),
                        temp[1],
                        new BigDecimal(temp[2]),
                        Integer.parseInt(temp[3]),
                        validateCategory(temp[4]));

                hashMap.put(product.getId(), product);
            }
        } catch (
                FileNotFoundException e) {
            System.out.println("arquivo não encontrado");
            e.printStackTrace();
        } catch (
                IOException e) {
            System.out.println("problema na leitura do arquivo");
            e.printStackTrace();
        } finally {
            return hashMap;
        }
    }

    public void saveOnFile() {
        String path = "src/resources/files/estoque.csv";

        try (BufferedWriter bw = new BufferedWriter(new FileWriter(path))) {
            bw.write("id, name, price, quantity, category");
            bw.newLine();
            for (Product product : Database.getInstance().recoverProducts().values()) {
                bw.write(product.toString());
                bw.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}