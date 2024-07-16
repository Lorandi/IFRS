package testes;

import classes.Projeto;
import jakarta.persistence.EntityManager;
import util.JPAUtil;

public class Projeto_ex3_delete {

    public static void main(String[] args) {
        EntityManager em = JPAUtil.getEntityManager();
        try {
	        em.getTransaction().begin();
	        Projeto projeto = em.find(Projeto.class, 1L);
            em.remove(projeto);
            System.out.println("Projeto excluído com sucesso");
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
