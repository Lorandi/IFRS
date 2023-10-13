package service;

import builder.ProductBuilder;
import entities.Database;
import entities.Product;
import enums.Category;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ProductService {

    private List<Product> products;

    public ProductService(List<Product> products) {
        this.products = Database.getInstance().recuperaProduct();
    }

    public void addProduct() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nome do produto: ");
        String name = sc.nextLine();
        System.out.print("Preço: ");
        Double price = sc.nextDouble();

        System.out.print("Quantidade: ");
        Integer quantity = sc.nextInt();

        System.out.print("Categoria: [1]Roupas [2]Calçados [3]Acessórios ");
        Integer tempCategoria = sc.nextInt();
        Category category;
        Boolean verificaCagoria = tempCategoria == 1 || tempCategoria == 2 || tempCategoria == 3;

        while (!verificaCagoria) {
            System.out.print("Categoria: [1]Roupas [2]Calçados [3]Acessórios ");
            tempCategoria = sc.nextInt();
            verificaCagoria = tempCategoria == 1 || tempCategoria == 2 || tempCategoria == 3;
        }

        System.out.println("Você quer confirmar a operação?");
        System.out.print("Digite [1] para confirmar ou [2] para cancelar: ");
        Integer confirmacao = sc.nextInt();

        Boolean verificaConfirmacao = confirmacao == 1 || confirmacao == 2;

        while (!verificaConfirmacao) {
            System.out.println("Dado inválido");
            System.out.print("Digite [1] para confirmar ou [2] para cancelar: ");

            confirmacao = sc.nextInt();
            verificaConfirmacao = confirmacao == 1 || confirmacao == 2;
        }

        if (confirmacao == 1) {
            if (tempCategoria == 1) {
                category = Category.ROUPAS;
            } else if (tempCategoria == 2) {
                category = Category.CALCADOS;
            } else {
                category = Category.ACESSORIOS;
            }

            Database.getInstance().persisteProduct(new ProductBuilder(name)
                    .forPrice(price)
                    .forQuantity(quantity)
                    .forCategory(category)
                    .createProdutc());


            System.out.println("\nProduto adicionado com sucesso!!! \n"
                    + "Id: " + products.get(products.size() - 1).getId() + ", "
                    + "Nome: " + products.get(products.size() - 1).getName() + ", "
                    + "Preço: " + products.get(products.size() - 1).getPrice() + ", "
                    + "Quantidade: " + products.get(products.size() - 1).getQuantity() + ", "
                    + "Categoria: " + products.get(products.size() - 1).getCategory().getValue());
        } else {
            System.out.println("Operação cancelada");
        }

//        sc.close(); // se fecho aqui ele da erro  caso tente adicionar outro produto na sequência
    }

    public void editProduct() {
        Database.getInstance().showStockList();

        if(!Database.getInstance().recuperaProduct().isEmpty()) {


            System.out.print("\nQual Id do produto gostaria de editar: ");
            Scanner sc = new Scanner(System.in);
            Integer idProduto = sc.nextInt();
            Product produtcToEdit = Database.getInstance().recuperaProduct().get(idProduto - 1);
            System.out.println("\nProduto escolhido \n"
                    + "Id: " + produtcToEdit.getId() + ", "
                    + "Nome: " + produtcToEdit.getName() + ", "
                    + "Preço: " + produtcToEdit.getPrice() + ", "
                    + "Quantidade: " + produtcToEdit.getQuantity() + ", "
                    + "Categoria: " + produtcToEdit.getCategory().getValue() + "\n");

            // Variáveis criadas para manter as configurações antes da modificação
            String oldName = produtcToEdit.getName();
            Double oldPrice = produtcToEdit.getPrice();
            Integer oldQuantity = produtcToEdit.getQuantity();
            Category oldCategory = produtcToEdit.getCategory();


            System.out.print("Qual dado quer modificar: [1]Nome [2]Preço [3]Quantidade [4]Categoria :");

            Integer dado = sc.nextInt();
            Boolean verificaDado = dado == 1 || dado == 2 || dado == 3 || dado == 4;

            while (!verificaDado) {
                System.out.println("Dado inválido");
                System.out.print("Qual dado quer modificar: [1]Nome [2]Preço [3]Quantidade [4]Categoria ");

                dado = sc.nextInt();
                verificaDado = dado == 1 || dado == 2 || dado == 3 || dado == 4;
            }

            if (dado == 1) {
                sc.nextLine();
                System.out.print("Digite o novo nome: ");
                String newNane = sc.nextLine();
                produtcToEdit.setName(newNane);
            } else if (dado == 2) {
                System.out.print("Digite o novo preço: ");
                Double newPrice = sc.nextDouble();
                produtcToEdit.setPrice(newPrice);
            } else if (dado == 3) {
                System.out.print("Digite a nova quantidade: ");
                Integer newQuantity = sc.nextInt();
                produtcToEdit.setQuantity(newQuantity);
            } else {
                System.out.print("Qual a nova categoria: [1]Roupas [2]Calçados [3]Acessórios ");
                Integer tempCategoria = sc.nextInt();
                Boolean verificaCagoria = tempCategoria == 1 || tempCategoria == 2 || tempCategoria == 3;

                while (!verificaCagoria) {
                    System.out.println("Categoria inválida");
                    System.out.print("Qual a nova categoria: [1]Roupas [2]Calçados [3]Acessórios ");
                    tempCategoria = sc.nextInt();
                    verificaCagoria = tempCategoria == 1 || tempCategoria == 2 || tempCategoria == 3;
                }

                Category category;
                if (tempCategoria == 1) {
                    category = Category.ROUPAS;
                } else if (tempCategoria == 2) {
                    category = Category.CALCADOS;
                } else {
                    category = Category.ACESSORIOS;
                }

                produtcToEdit.setCategory(category);

            }

            System.out.println("\nProduto modificado \n"
                    + "Id: " + produtcToEdit.getId() + ", "
                    + "Nome: " + produtcToEdit.getName() + ", "
                    + "Preço: " + produtcToEdit.getPrice() + ", "
                    + "Quantidade: " + produtcToEdit.getQuantity() + ", "
                    + "Categoria: " + produtcToEdit.getCategory().getValue() + "\n");

            System.out.println("Você quer confirmar a operação?");
            System.out.print("Digite [1] para confirmar ou [2] para cancelar: ");
            Integer confirmacao = sc.nextInt();

            Boolean verificaConfirmacao = confirmacao == 1 || confirmacao == 2;

            while (!verificaConfirmacao) {
                System.out.println("Dado inválido");
                System.out.print("Digite [1] para confirmar ou [2] para cancelar: ");

                confirmacao = sc.nextInt();
                verificaConfirmacao = confirmacao == 1 || confirmacao == 2;
            }


            if (confirmacao == 1) {
                System.out.println("Operação realizada com sucesso");

            } else {
                if (dado == 1) {
                    produtcToEdit.setName(oldName);
                }
                if (dado == 2) {
                    produtcToEdit.setPrice(oldPrice);

                }
                if (dado == 3) {
                    produtcToEdit.setQuantity(oldQuantity);

                } else {
                    produtcToEdit.setCategory(oldCategory);
                }
                System.out.println("Operação cancelada");
            }
        }else{
            System.out.println("Lista ainda não tem produtos");
        }
    }

    public void removeProduct() {

        if (Database.getInstance().recuperaProduct().size() > 1) {
            System.out.println("Qual produto gostaria de remover?");
            Database.getInstance().showStockList();
            System.out.print("Digite o Id do produto que quer remover: ");
            Scanner sc = new Scanner(System.in);
            Integer idProduto = sc.nextInt();

            System.out.println("Você quer confirmar a operação?");
            System.out.print("Digite [1] para confirmar ou [2] para cancelar: ");
            Integer confirmacao = sc.nextInt();

            Boolean verificaConfirmacao = confirmacao == 1 || confirmacao == 2;

            while (!verificaConfirmacao) {
                System.out.println("Dado inválido");
                System.out.print("Digite [1] para confirmar ou [2] para cancelar: ");

                confirmacao = sc.nextInt();
                verificaConfirmacao = confirmacao == 1 || confirmacao == 2;
            }

            if (confirmacao == 1) {
                Database.getInstance().removeProduct(Database.getInstance().recuperaProduct().get(idProduto - 1));
                System.out.println("Produto excluído");
            } else {
                System.out.println("Operação cancelada");
            }
        } else {
            System.out.println("Não é possível excluir itens da lista");
        }
    }


    public void importMostruario() {
//        String mostruario = "c:\\EstagioSouth\\Desafio1\\src\\main\\java\\files\\mostruario.csv";
//        c:\\EstagioSouth\\Desafio1\\src\\main\\java\\files\\mostruario_fabrica.csv
//        c:\\EstagioSouth\\Desafio1\\src\\main\\java\\files\\mostruario_fabricaC.csv

        Scanner sc = new Scanner(System.in);
        System.out.print("\nDigite o endereço do arquivo .csv que será utilizado: ");

        String mostruario = sc.nextLine();

        System.out.println("Você quer confirmar a operação?");
        System.out.print("Digite [1] para confirmar ou [2] para cancelar: ");
        Integer confirmacao = sc.nextInt();

        Boolean verificaConfirmacao = confirmacao == 1 || confirmacao == 2;

        while (!verificaConfirmacao) {
            System.out.println("Dado inválido");
            System.out.print("Digite [1] para confirmar ou [2] para cancelar: ");

            confirmacao = sc.nextInt();
            verificaConfirmacao = confirmacao == 1 || confirmacao == 2;
        }

        if (confirmacao == 1) {
            try (BufferedReader br = new BufferedReader(new FileReader(mostruario))) {
                String line = br.readLine(); //atribuido valor para ler a primeira linha com os nomes dos parâmentros
                String[] temp;
                while ((line = br.readLine()) != null) {
                    temp = line.split(",");

                    Category categoryTemp;

                    if(temp[4].equals("ESCRITÓRIO")){
                        categoryTemp = Category.ESCRITORIO;
                    } else if(temp[4].equals("ALIMENTAÇÃO E BEBIDAS")){
                        categoryTemp = Category.ALIMENTCAO_E_BEBIDAS;
                    }else if(temp[4].equals("VESTUÁRIO")){
                        categoryTemp = Category.VESTUARIO;
                    }else if(temp[4].equals("HIGIENE E SAÚDE")){
                        categoryTemp = Category.HIGIENE_E_SAÚDE;
                    }else if(temp[4].equals("MEIO DE TRANSPORTE")){
                        categoryTemp = Category.MEIO_DE_TRANSPORTE;
                    }else{
                        categoryTemp = Category.OUTROS;
                    }

                    Double taxa = 1.45;

                    Database.getInstance().persisteProduct(new ProductBuilder(temp[3])
                            .forPrice(Double.valueOf(temp[2]) )
                            .forQuantity(3)
                            .forCategory(categoryTemp)
                            .createProdutc());
                }

//                    Database.getInstance().persisteProduct(new ProductBuilder(temp[1])
//                            .forPrice(Double.valueOf(temp[2]) * taxa)
//                            .forQuantity(Integer.parseInt(temp[3]))
//                            .forCategory(Category.valueOf(temp[4]))
//                            .createProdutc());
//                }

                System.out.println("Lista importada com sucesso");
                Database.getInstance().showStockList();

            } catch (IOException e) {
                System.out.println("Error: " + e.getMessage());
            }
        } else {
            System.out.println("Operação cancelada");
        }
    }
}





