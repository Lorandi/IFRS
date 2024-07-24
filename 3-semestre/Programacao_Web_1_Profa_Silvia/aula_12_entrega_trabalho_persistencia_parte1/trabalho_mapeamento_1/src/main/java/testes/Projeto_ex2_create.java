package testes;

import classes.Projeto;
import enums.Situacao;
import jakarta.persistence.EntityManager;
import util.JPAUtil;

import java.time.LocalDate;
import java.util.Date;
import java.util.HashSet;


public class Projeto_ex2_create {

    public static void main(String[] args) {
        EntityManager em = JPAUtil.getEntityManager();
        try {
			HashSet<String> participantes = new HashSet<String>();
			participantes.add("Joaozinho");
			participantes.add("Mariazinha");
			participantes.add("Ana");
			participantes.add("Zeca");
			participantes.add("Adoniran");
			Projeto projeto = new Projeto(new Date(),  participantes, Situacao.ATIVO);
			projeto.setDataFim(LocalDate.now().plusMonths(3));
	        em.getTransaction().begin();
	        em.persist(projeto);
	        em.getTransaction().commit();
			System.out.println("Projeto salvo com sucesso! " );
			Projeto projeto1 = em.find(Projeto.class, 3L);
			//Essa chamada ao método size() força a inicialização do IndirectSet.
			projeto1.getParticipantes().size();
	        System.out.println(projeto1);

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
