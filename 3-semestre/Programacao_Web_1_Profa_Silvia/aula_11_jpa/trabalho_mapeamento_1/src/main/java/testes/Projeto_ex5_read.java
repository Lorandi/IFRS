package testes;

import classes.Projeto;
import jakarta.persistence.EntityManager;
import jakarta.persistence.TypedQuery;
import util.JPAUtil;

import java.util.List;

public class Projeto_ex5_read {

    public static void main(String[] args) {
        EntityManager em = JPAUtil.getEntityManager();
        System.out.println("Listando todos os projetos");
        TypedQuery<Projeto> query =
           em.createQuery("SELECT obj FROM Projeto obj", Projeto.class);
        List<Projeto> projetos= query.getResultList();

        for (Projeto projeto : projetos) {
			System.out.println(projeto.toString());
		}
       	em.close();
       	JPAUtil.close();
    }
}
