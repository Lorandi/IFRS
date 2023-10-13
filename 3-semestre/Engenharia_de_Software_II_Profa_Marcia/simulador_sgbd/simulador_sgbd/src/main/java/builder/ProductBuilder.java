package builder;

import entities.Database;
import entities.Product;
import enums.Category;

import java.math.BigDecimal;

public class ProductBuilder {
    private static Integer id = 0;

    //Mandatory
    final private String name;

    //Optionals
    private BigDecimal price;
    private Integer quantity;
    private Category category;

    public ProductBuilder(String name) {
        this.name = name;
    }

    public ProductBuilder forPrice(BigDecimal price) {
        this.price = price;
        return this;
    }

    public ProductBuilder forQuantity(Integer quantity) {
        this.quantity = quantity;
        return this;
    }

    public ProductBuilder forCategory(Category category) {
        this.category = category;
        return this;
    }

    public Product createProduct() {
        for (Product product : Database.getInstance().recoverProducts().values()) {
            if (product.getId() > id) {
                id = product.getId();
            }
        }

        this.id = id + 1;

        return new Product(id, name, price, quantity, category);
    }
}