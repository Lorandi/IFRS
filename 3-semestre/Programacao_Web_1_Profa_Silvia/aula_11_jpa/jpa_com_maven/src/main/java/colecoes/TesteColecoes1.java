package colecoes;

import jakarta.persistence.EntityManager;
import util.JPAUtil;

import enums.Perfil;
import java.util.*;

public class TesteColecoes1 {

    public static void main(String[] args) {
        EntityManager em = JPAUtil.getEntityManager();
        try {
        	Set<String> emails = new HashSet<String>();
        	emails.add("fulano1@mail.com");
        	emails.add("fulano2@mail.com");
	        Usuario4 user = new Usuario4("fulano", "123456", emails);
	        user.setPerfil(Perfil.ALUNO);
	        user.setDataCadastro(new Date());
	        em.getTransaction().begin();
	        em.persist(user);
	        System.out.println("Usu�rio salvo com sucesso! " );
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
