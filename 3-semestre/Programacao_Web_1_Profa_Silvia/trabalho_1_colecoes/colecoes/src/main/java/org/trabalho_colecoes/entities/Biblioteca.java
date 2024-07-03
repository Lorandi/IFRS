package org.trabalho_colecoes.entities;

import org.trabalho_colecoes.interfaces.OperacoesBiblioteca;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.TreeSet;

public class Biblioteca implements OperacoesBiblioteca, Serializable {
    private ArrayList<Membro> membros = new ArrayList<>();
    private TreeSet<Livro> livros = new TreeSet<>();


    @Override
    public void cadastrarMembro(Object obj) {
        membros.add((Membro) obj);
    }

    @Override
    public void cadastrarLivro(Object obj) {
        livros.add((Livro) obj);
    }

    public String listarTodosMembros(){
        System.out.println("\nTodos os membros: ");
        if(membros.isEmpty()){
            System.out.println("Lista de membros está vazia. \n");
        }
        StringBuilder st = new StringBuilder();
        for (Membro membro : membros) {
            st.append(membro.toString());
            st.append("\n");
            System.out.println(membro);
        }
        return st.toString();
    }

    public String listarTodosLivros(){
        System.out.println("\nTodos os livros: ");
        StringBuilder st = new StringBuilder();

        if(livros.isEmpty()){
            System.out.println("Lista de livros está vazia. \n");
        }
        for (Livro livro : livros) {
            st.append(livro.toString());
            st.append("\n");
            System.out.println(livro);
        }
        return st.toString();
    }

    @Override
    public boolean pesquisarMembro(Object obj) {
        return membros.contains((Membro) obj);

    }

    @Override
    public boolean pesquisarLivro(Object obj) {
        return livros.contains((Livro)obj);
    }

}
