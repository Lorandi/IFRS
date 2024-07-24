package testes;


import classes.Usuario;
import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.Persistence;

public class Exemplo1 {
	public static void main(String[] args) {
		EntityManagerFactory emf = Persistence.createEntityManagerFactory("testeJPA");
        EntityManager em = emf.createEntityManager();
        Usuario user = new Usuario("sbertagnolli2", "123456");
        em.getTransaction().begin();
        em.persist(user);
        System.out.println("Usu�rio salvo com sucesso! " );
        em.getTransaction().commit();
        em.close();
        emf.close();
    }
}



