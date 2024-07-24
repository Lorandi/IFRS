package datas;

import enums.Perfil;
import jakarta.persistence.EntityManager;
import util.JPAUtil;

import java.time.LocalDate;
import java.util.Date;


public class TesteData2 {

    public static void main(String[] args) {
        EntityManager em = JPAUtil.getEntityManager();
        try {
	        Usuario3 user = new Usuario3("Ciclano", "123456", Perfil.ALUNO, new Date(), LocalDate.now());
	        user.setPerfil(Perfil.ALUNO);
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
