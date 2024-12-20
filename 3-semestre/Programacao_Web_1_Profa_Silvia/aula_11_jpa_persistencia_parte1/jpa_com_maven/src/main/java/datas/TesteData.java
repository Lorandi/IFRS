package datas;

import util.JPAUtil;
import enums.Perfil;
import jakarta.persistence.*;
import java.util.*;


public class TesteData {

    public static void main(String[] args) {
        EntityManager em = JPAUtil.getEntityManager();
        try {
	        Usuario3 user = new Usuario3("fulano", "123456");
	        user.setPerfil(Perfil.ALUNO);
	        user.setDataCadastro(new Date());
	        em.getTransaction().begin();
	        em.persist(user);
	        em.getTransaction().commit();
            System.out.println("Usuário salvo com sucesso! " );
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
