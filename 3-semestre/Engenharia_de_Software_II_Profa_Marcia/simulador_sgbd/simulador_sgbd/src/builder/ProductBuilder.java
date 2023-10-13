package builder;

import entities.Product;
import enums.Category;

public class ProductBuilder {
    private static Integer id = 0;

    //Mandatory
    private String name;

    //Optionals
    private Double price;
    private Integer quantity;
    private Category category;

    public ProductBuilder( String name) {
        this.name = name;
    }

    public ProductBuilder forPrice(Double price) {
        this.price = price;
        return this;
    }

    public ProductBuilder forQuantity(Integer quantity) {
        this.quantity = quantity;
        return this;
    }

    public ProductBuilder forCategory(Category category) {
        this.category= category;
        return this;
    }

    public Product createProdutc(){
        this.id = id + 1;
        return new Product(id, name,price,quantity,category);
    }

}
