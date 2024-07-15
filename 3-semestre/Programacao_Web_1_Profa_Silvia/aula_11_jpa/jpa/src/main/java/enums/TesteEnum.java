package enums;

import util.JPAUtil;

import classes.Usuario;
import enums.Perfil;
import javax.persistence.*;
import java.util.*;
import java.time.*;

public class TesteEnum {

    public static void main(String[] args) {
        EntityManager em = JPAUtil.getEntityManager();
        try {
	        Usuario2 user = new Usuario2("fulano", "123456", Perfil.ALUNO);
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
