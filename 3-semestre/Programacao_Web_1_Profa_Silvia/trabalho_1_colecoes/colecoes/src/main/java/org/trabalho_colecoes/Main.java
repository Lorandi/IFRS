package org.trabalho_colecoes;

import org.trabalho_colecoes.IOClasses.ArquivoObjetos;
import org.trabalho_colecoes.entities.Biblioteca;
import org.trabalho_colecoes.entities.Livro;
import org.trabalho_colecoes.entities.Membro;

import static org.trabalho_colecoes.enums.SituacaoMatriculaEnum.CANCELADO;
import static org.trabalho_colecoes.enums.SituacaoMatriculaEnum.MATRICULADO;

public class Main {

    public static void main(String[] args) {

        Livro livro1 = new Livro("Mas em que mundo tu vive", "José Falero", "656546546");
        Livro livro2 = new Livro("Seleta de Canções", "Lupicínio Rodrigueso", "54654654654");
        Livro livro3 = new Livro("A terra dos mil povos ", "Kaká Werá", "979797979797");
        Livro livro4 = new Livro("Água funda", "Ruth Guimarães.", "131313131");

        Membro membro1 = new Membro("asdf1321", "Galileu Galilei", MATRICULADO);
        Membro membro2 = new Membro("asdf1322", "Isaac Newton", CANCELADO);
        Membro membro3 = new Membro("asdf1323", "Marie Curie", MATRICULADO);
        Membro membro4 = new Membro("asdf1324", "Albert Einsteini", MATRICULADO);

        Biblioteca biblioteca1 = new Biblioteca();

        biblioteca1.cadastrarLivro(livro1);
        biblioteca1.cadastrarLivro(livro2);
        biblioteca1.cadastrarLivro(livro3);
        biblioteca1.listarTodosLivros();
        System.out.println();

        biblioteca1.cadastrarMembro(membro1);
        biblioteca1.cadastrarMembro(membro2);
        biblioteca1.cadastrarMembro(membro3);
        biblioteca1.listarTodosMembros();
        System.out.println();

        System.out.println( biblioteca1.pesquisarLivro(livro3) ? "Encontrou livro: " + livro3.getTitulo() : "Não encontrou livro: " + livro3.getTitulo());
        System.out.println( biblioteca1.pesquisarLivro(livro4) ? "Encontrou livro: " + livro4.getTitulo() : "Não encontrou livro: " + livro4.getTitulo());
        System.out.println();

        System.out.println(biblioteca1.pesquisarMembro(membro3) ? "Encontrou membro: " + membro3.getNome() : "Não encontrou membro: " + membro3.getNome());
        System.out.println(biblioteca1.pesquisarMembro(membro4) ? "Encontrou membro: " + membro4.getNome() : "Não encontrou membro: " + membro4.getNome());
        System.out.println();


        ArquivoObjetos arquivoObjetos = new ArquivoObjetos("Arquivo");

        arquivoObjetos.abrir("w");
        arquivoObjetos.gravarObjeto(biblioteca1);
        arquivoObjetos.fechar();

        arquivoObjetos.abrir("r");

        Biblioteca b = (Biblioteca) arquivoObjetos.lerObjeto();
        arquivoObjetos.fechar();

        b.listarTodosMembros();
    }

}

