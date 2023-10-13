package entities;
import enums.Category;

import java.io.*;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.*;

import static validators.Validators.saveOnDatabase;
import static validators.Validators.validateCategory;

public class Database {

    private static final Database database = new Database();

    private static final HashMap<Integer, Product> products = new HashMap<Integer, Product>();

    public static Database getInstance() {
        return database;
    }

    public Database() {
    }

    public void persistsProduct(Product product) {
        products.put(product.getId(), product);
    }

    public HashMap<Integer, Product> recoverProducts() {
        return products;
    }

    public void removeProduct(Product product) {
        products.remove(product.getId());
    }

    public void showStockList() {
        System.out.println("\n Lista de produtos");
        for (Product product : products.values()) {
            System.out.println(product.toString());
        }
        saveOnFile();
    }

    public HashMap<Integer, Product> readFromFile() {
        String path = "src/main/resources/files/estoque.csv";

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

                products.put(product.getId(), product);
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
            return products;
        }
    }

    public void saveOnFile() {
        String path = "src/main/resources/files/estoque.csv";

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

    public void readFromShowcase(){
        Scanner sc = new Scanner(System.in);
        boolean importOK = false;

        do{
            System.out.print("\nDigite o endereço do arquivo .csv que será utilizado: ");
            String mostruario = sc.nextLine();

            int addedProducts = 0;
            int modifiedProducts = 0;

            try (BufferedReader br = new BufferedReader(new FileReader(mostruario))) {
                String line = br.readLine(); //atribuido valor para ler a primeira linha com os nomes dos parâmentros
                String[] temp;

                while ((line = br.readLine()) != null) {
                    temp = line.split(",(?=([^\"]*\"[^\"]*\")*[^\"]*$)");

                    Category categoryTemp = validateCategory(temp[5]);

                    BigDecimal margemDeLucro = new BigDecimal("45")
                            .divide(new BigDecimal("100"), RoundingMode.CEILING)
                            .add(new BigDecimal("1"));

                    BigDecimal imposto = new BigDecimal(temp[7]
                            .replace(",", ".")
                            .replace("\"", ""))
                            .divide(new BigDecimal("100"), RoundingMode.CEILING)
                            .add(new BigDecimal("1"));

                    BigDecimal price = new BigDecimal(temp[6]
                            .replace(",", ".")
                            .replace("\"", ""))
                            .multiply(imposto)
                            .multiply(margemDeLucro)
                            .setScale(2, RoundingMode.CEILING);

                    boolean registerItem = true;

                    if (Database.getInstance().recoverProducts().isEmpty()) {
                        saveOnDatabase(temp[3], price, 1, categoryTemp);
                        addedProducts++;

                    } else {
                        for (Product product : Database.getInstance().recoverProducts().values()) {
                            if (product.getName().equals(temp[3])) {
                                product.setQuantity(product.getQuantity() + 1);
                                registerItem = false;
                                modifiedProducts++;
                            }
                        }
                        if (registerItem) {
                            saveOnDatabase(temp[3], price, 1, categoryTemp);
                            addedProducts++;
                        }
                    }
                }
                System.out.println("\nMostruário adicionado ao estoque.");
                System.out.println("Produtos adicionados: " + addedProducts);
                System.out.println("Produtos modificados: " + modifiedProducts);

                importOK = true;


            } catch (IOException e) {
                System.out.println("Arquivo inválido" +
                        "\n Para adicionar mostruário, é necessário um arquivo .csv com as seguintes colunas:" +
                        "\ncódigo,codigo de barras,série,nome,descrição,categoria,valor bruto,impostos (%),data de fabricação,data de validade,cor,material");


            } catch (ArrayIndexOutOfBoundsException e){
                System.out.println("Endereço com arquivo inválido");
                System.out.println("Para adicionar mostruário o arquivo .csv deve ter as seguintes colunas:");
                System.out.println("código,codigo de barras,série,nome,descrição,categoria,valor bruto,impostos (%),data de fabricação,data de validade,cor,material");

            }
        }while(!importOK);
    }
}