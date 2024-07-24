package testes;

import classes.Projeto;
import enums.Situacao;
import jakarta.persistence.EntityManager;
import util.JPAUtil;

public class Projeto_ex4_update {

    public static void main(String[] args) {
        EntityManager em = JPAUtil.getEntityManager();
        try {
	        em.getTransaction().begin();
	        Projeto projeto = em.find(Projeto.class, 2L);
            projeto.setSituacao(Situacao.ENCERRADO);
            System.out.println("Projeto alterado com sucesso");
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
