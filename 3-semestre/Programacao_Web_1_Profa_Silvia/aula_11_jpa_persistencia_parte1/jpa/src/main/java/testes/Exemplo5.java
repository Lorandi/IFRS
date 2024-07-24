package testes;

import util.JPAUtil;
import classes.Usuario;
import javax.persistence.*;

public class Exemplo5 {

    public static void main(String[] args) {
        EntityManager em = JPAUtil.getEntityManager();
        try {
	        em.getTransaction().begin();
	        Usuario usuario = em.find(Usuario.class, 2L); 
            usuario.setIdentificador("novoid");
            System.out.println("objeto alterado com sucesso");
	        em.getTransaction().commit();
        }catch(RuntimeException e) {
        	 if (em.getTransaction().isActive())
                 em.getTransaction().rollback();
        } finally {
            if(em!= null) {
            	em.close();
            	JPAUtil.close();
            }
        }
    }

}
