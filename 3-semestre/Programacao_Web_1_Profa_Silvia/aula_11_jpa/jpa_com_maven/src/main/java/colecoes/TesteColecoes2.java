package colecoes;

import util.JPAUtil;

import enums.Perfil;
import jakarta.persistence.*;
import java.util.*;


public class TesteColecoes2 {

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
	        em.getTransaction().commit();
			System.out.println("Usuário salvo com sucesso! " );
	        //buscando objeto cadastrado no banco
	        Usuario4 userAux = em.find(Usuario4.class, 1L);
	        Date date = userAux.getDataCadastro();
	        System.out.println("Data " + date.toString());

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
