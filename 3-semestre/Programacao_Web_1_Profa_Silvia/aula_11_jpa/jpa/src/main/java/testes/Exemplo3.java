package testes;

import util.JPAUtil;
import classes.Usuario;
import javax.persistence.*;

public class Exemplo3 {

    public static void main(String[] args) {
        EntityManager em = JPAUtil.getEntityManager();
        try {
	        Usuario user = new Usuario("sbertagnolli3", "123456");
	        em.getTransaction().begin();
	        em.persist(user);
	        System.out.println("Usuário salvo com sucesso! " );
	        em.getTransaction().commit();
        }catch(RuntimeException e) {
        	 if (em.getTransaction().isActive()) {
                 em.getTransaction().rollback();
             }
         } finally {
             em.close();
             JPAUtil.close();
         }
    }

}
