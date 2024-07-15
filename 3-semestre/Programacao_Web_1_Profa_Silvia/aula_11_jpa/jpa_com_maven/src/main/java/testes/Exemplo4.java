package testes;

import util.JPAUtil;
import classes.Usuario;
import jakarta.persistence.*;

public class Exemplo4 {

    public static void main(String[] args) {
        EntityManager em = JPAUtil.getEntityManager();
        try {
	        em.getTransaction().begin();
	        Usuario usuario = em.find(Usuario.class, 1L); 
            em.remove(usuario);
            System.out.println("objeto excluído com sucesso");
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
