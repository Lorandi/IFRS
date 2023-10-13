package validators;

import builder.ProductBuilder;
import entities.Database;
import entities.Product;
import enums.Category;
import exceptions.ValueMustBePositiveException;

import java.math.BigDecimal;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Validators {
    public static void saveOnDatabase(String name, BigDecimal price, Integer quantity, Category category) {
        Database.getInstance().persistsProduct(new ProductBuilder(name)
                .forPrice(price)
                .forQuantity(quantity)
                .forCategory(category)
                .createProduct());

        System.out.println("\nProduto adicionado com sucesso!!! \n"
                + "Nome: " + name + ", "
                + "Preço: " + price + ", "
                + "Quantidade: " + quantity + ", "
                + "Categoria: " + category);
    }

    public static BigDecimal validateBigDecimal(String valor) {
        Scanner readBigDecimal = new Scanner(System.in);
        BigDecimal price = null;
        boolean continua = true;

        do {
            try {
                System.out.print("Preço: ");
                valor = readBigDecimal.nextLine();

                while (valor.equals("")) {
                    System.out.print("Digite um valor numérico. Preço: ");
                    valor = readBigDecimal.nextLine();
                }

                price = new BigDecimal(valor
                        .replace(",", ".")
                        .replace("\"", ""));

                if (price.signum() < 0) {
                    throw new ValueMustBePositiveException();
                }
                continua = false;
            } catch (NumberFormatException msn) {
                System.out.print("Digite apenas valores numéricos para o preço. ");

            } catch (ValueMustBePositiveException erro2) {
                System.out.print("Valor deve ser positivo. ");
                continua = true;
            }
        } while (continua);

        return price;
    }

    public static Integer validateIntegers() {
        Scanner sc = new Scanner(System.in);

        boolean continues = true;
        int quantity = 0;

        do {
            try {
                System.out.print("Quantidade: ");
                quantity = sc.nextInt();
                continues = false;

                if (quantity < 0) {
                    throw new ValueMustBePositiveException();
                }
            } catch (InputMismatchException erro1) {
                System.out.println("Necessário digitar apenas números inteiros entre 0 e 2147483647.");
                sc.nextLine();
            } catch (ValueMustBePositiveException erro2) {
                System.out.print("Quantidade deve ser positiva. ");
                continues = true;
            }
        } while (continues);

        return quantity;
    }

    public static Category validateCategory(String nameCategory) {
        Category category = null;
        Scanner sc = new Scanner((System.in));

        String menuCategories =
                "[1]ESCRITÓRIO  " +
                        "[2]ALIMENTÇÃO E BEBIDAS  " +
                        "[3]VESTUÁRIO  " +
                        "[4]HIGIENE E SAÚDE  " +
                        "[5]MEIO DE TRANSPORTE  " +
                        "\nSelecione a categoria: ";

        if (nameCategory.equals("")) {
            System.out.print(menuCategories);
            nameCategory = sc.next();

            boolean checkCategory = nameCategory.equals("1") ||
                    nameCategory.equals("2") ||
                    nameCategory.equals("3") ||
                    nameCategory.equals("4") ||
                    nameCategory.equals("5");

            while (!checkCategory) {
                System.out.println("Valor inválido");
                System.out.print(menuCategories);

                nameCategory = sc.next();

                checkCategory = nameCategory.equals("1") ||
                        nameCategory.equals("2") ||
                        nameCategory.equals("3") ||
                        nameCategory.equals("4") ||
                        nameCategory.equals("5");
            }
        }

        switch (Category.getByCode(nameCategory)) {
            case ESCRITORIO:
                category = Category.ESCRITORIO;
                break;

            case ALIMENTCAO_E_BEBIDAS:
                category = Category.ALIMENTCAO_E_BEBIDAS;
                break;

            case VESTUARIO:
                category = Category.VESTUARIO;
                break;

            case HIGIENE_E_SAUDE:
                category = Category.HIGIENE_E_SAUDE;
                break;

            case MEIO_DE_TRANSPORTE:
                category = Category.MEIO_DE_TRANSPORTE;
                break;

            default:
                category = Category.CATEGORY_NOT_FOUND;
        }
        return category;
    }

    public static Boolean confirmOperation() {
        Scanner sc = new Scanner(System.in);

        System.out.println("Você quer confirmar a operação?");
        System.out.print("Digite [1] para confirmar ou [2] para cancelar: ");
        String confirmation = sc.nextLine();

        boolean verificaConfirmacao = confirmation.equals("1") || confirmation.equals("2");

        while (!verificaConfirmacao) {
            System.out.println("Dado inválido");
            System.out.print("Digite [1] para confirmar ou [2] para cancelar: ");

            confirmation = sc.nextLine();
            verificaConfirmacao = confirmation.equals("1") || confirmation.equals("2");
        }

        if (confirmation.equals("1")) {
            return true;
        } else {
            return false;
        }
    }

    public static Product searchProductOnStock() {
        Scanner sc = new Scanner(System.in);
        Product produtcOnStock = null;
        do {
            try {
                System.out.print("\nQual Id do produto? ");
                String idProduto = sc.next();
                for (Product product : Database.getInstance().recoverProducts().values()) {
                    if (Integer.parseInt(idProduto) == product.getId()) {
                        produtcOnStock = Database.getInstance().recoverProducts().get(Integer.parseInt(idProduto));
                    }
                }
                if (produtcOnStock == null) {
                    System.out.println("Nenhum produto com Id " + idProduto + " no estoque.");
                }
            } catch (NumberFormatException msn) {
                System.out.println("Digite apenas valores numéricos do Id do produto ");
            }
        } while (produtcOnStock == null);

        System.out.println("\nProduto escolhido \n"
                + "Id: " + produtcOnStock.getId() + ", "
                + "Nome: " + produtcOnStock.getName() + ", "
                + "Preço: " + produtcOnStock.getPrice() + ", "
                + "Quantidade: " + produtcOnStock.getQuantity() + ", "
                + "Categoria: " + produtcOnStock.getCategory().getDescription() + "\n");

        return produtcOnStock;
    }
}