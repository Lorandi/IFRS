package aplication;

import entities.Menu;
import org.springframework.boot.SpringApplication;

public class Program {
    public static void main(String[] args) throws Exception {
        SpringApplication.run(Program.class, args);
        Menu menu = new Menu();
        menu.menu();
    }
}