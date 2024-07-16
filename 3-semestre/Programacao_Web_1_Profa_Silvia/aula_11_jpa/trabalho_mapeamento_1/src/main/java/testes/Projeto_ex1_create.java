package testes;


import classes.Projeto;
import enums.Situacao;
import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.Persistence;

import java.util.Date;

public class Projeto_ex1_create {
	public static void main(String[] args) {
		EntityManagerFactory emf = Persistence.createEntityManagerFactory("mapeamento1");
        EntityManager em = emf.createEntityManager();
        Projeto projeto = new Projeto(new Date(), Situacao.ATIVO);
        em.getTransaction().begin();
        em.persist(projeto);
        System.out.println("Projeto salvo com sucesso! " );
        em.getTransaction().commit();
        em.close();
        emf.close();
    }
}



