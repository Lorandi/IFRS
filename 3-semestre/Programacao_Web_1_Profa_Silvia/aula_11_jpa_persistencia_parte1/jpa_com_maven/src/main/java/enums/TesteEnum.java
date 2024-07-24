package enums;

import util.JPAUtil;

import classes.Usuario;
import enums.Perfil;
import jakarta.persistence.*;
import java.util.*;
import java.time.*;

public class TesteEnum {

    public static void main(String[] args) {
        EntityManager em = JPAUtil.getEntityManager();
        try {
	        Usuario2 user = new Usuario2("Usuario2", "123456", Perfil.ALUNO);
	        em.getTransaction().begin();
	        em.persist(user);
	        em.getTransaction().commit();
            System.out.println("Usuário salvo com sucesso! ");
            System.out.println(user.toString());

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
