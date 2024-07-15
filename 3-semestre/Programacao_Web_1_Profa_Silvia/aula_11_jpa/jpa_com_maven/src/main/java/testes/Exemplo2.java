package testes;

import util.JPAUtil;
import classes.Usuario;
import jakarta.persistence.*;

public class Exemplo2 {

    public static void main(String[] args) {
        EntityManager em = JPAUtil.getEntityManager();
        Usuario user = new Usuario("sbertagnolli2", "123456");
        em.getTransaction().begin();
        em.persist(user);
        System.out.println("Usuário salvo com sucesso! " );
        em.getTransaction().commit();
        em.close();
        JPAUtil.close();
    }

}
