import entities.*;

import java.util.ArrayList;
import java.util.List;

public class TesteHospitais {
    public static void main(String[] args) {

        // Questão 2
        Medico med1 = new Especialista("1001", 10000f);
        Medico med2 = new Especialista("1002", 20000f);
        Medico med3 = new Homeopata("1003", 30000f);
        Medico med4 = new Homeopata("1004", 40000f);

        Hospital h1 = new Hospital("H1");
        h1.registraMed(med1);
        h1.registraMed(med2);
        h1.registraMed(med3);

        Hospital h2 = new Hospital("H2");
        h2.registraMed(med2);
        h2.registraMed(med3);
        h2.registraMed(med4);

        Hospital h3 = new Hospital("H3");
        h3.registraMed(med3);
        h3.registraMed(med4);

        //Questão 3
        Categoria catA = new Categoria("A");
        Categoria catB = new Categoria("B");
        Categoria catC = new Categoria("C");

        Curso curso1 = new Curso("Gripe", 100, catC);
        Curso curso2 = new Curso("Asma", 200, catC);
        Curso curso3 = new Curso("Alergia", 300, catB);
        Curso curso4 = new Curso("Tosse", 400, catA);


        //Questão 4
        med1.registraCusrso(curso1);
        med2.registraCusrso(curso1);
        med2.registraCusrso(curso2);
        med3.registraCusrso(curso1);
        med3.registraCusrso(curso2);
        med3.registraCusrso(curso3);
        med4.registraCusrso(curso3);
        med4.registraCusrso(curso4);

        //Questão 5
        System.out.println("Questão 5");
        List<Medico> medicosCriados = new ArrayList<>();
        medicosCriados.add(med1);
        medicosCriados.add(med2);
        medicosCriados.add(med3);
        medicosCriados.add(med4);

        for (Medico medico : medicosCriados) {
            System.out.println("CRM: " + medico.getCRM());
            System.out.println("Tipo: " + medico.getTipo());
            System.out.println("Salário Básico: " + medico.getSalarioBasico());
            for (Curso curso : medico.getCursos()) {
                System.out.println("Curso: " + curso.getTitulo());
            }
            System.out.println("");
        }

        //questao 6
        System.out.println("Questão 6");
        for (Medico medico : medicosCriados) {
            System.out.println("CRM: " + medico.getCRM());
            System.out.println("Tipo: " + medico.getTipo());
            System.out.println("Salário Básico: " + medico.getSalarioBasico());

            int totalPontos = 0;
            System.out.println("Curso: ");
            for (Curso curso : medico.getCursos()) {
                System.out.println(curso.getTitulo() + " = " + curso.getPontuacao() + " pontos");
                totalPontos += curso.getPontuacao();
            }
            System.out.println("Total = " + totalPontos + " pontos");
            System.out.println("Retribuição por cursos = " + medico.retribuicaoPorCurso());
            System.out.println("Ganho extra = " + medico.ganhoExtra());
            System.out.println("Salário Total = " + medico.salarioTotal());
            System.out.println("");
        }

        //questao 7
        System.out.println("Questao 7");
        List<Hospital> listHospital = new ArrayList<>();
        listHospital.add(h1);
        listHospital.add(h2);
        listHospital.add(h3);

        for(Hospital hospital : listHospital){
            System.out.println("Hospital: " + hospital.getNome());
            for(Medico medico : hospital.getMedicos()){
                System.out.println("CRM: " + medico.getCRM() + ". Salário Total = " + medico.salarioTotal());
            }
            System.out.println("Despesa total = " + hospital.despesaTotal());
            System.out.println("");
        }
    }
}





