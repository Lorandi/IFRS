package exceptions;

import service.ProductService;

public class ProductAlreadyRegisteredException extends Exception {
    public ProductAlreadyRegisteredException() {
        System.out.println("\nProduto com este nome já cadastrado. Utilize o menu Editar para modificar produto\n");
    }
}