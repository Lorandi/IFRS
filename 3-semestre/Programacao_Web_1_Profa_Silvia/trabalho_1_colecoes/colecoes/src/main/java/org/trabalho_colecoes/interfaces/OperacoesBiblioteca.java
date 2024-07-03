package org.trabalho_colecoes.interfaces;

import org.trabalho_colecoes.entities.Livro;

public interface OperacoesBiblioteca {
    public void cadastrarMembro(Object obj);
    public void cadastrarLivro(Object obj);
    public String listarTodosMembros();
    public String listarTodosLivros();
    public boolean pesquisarMembro(Object obj);
    public boolean pesquisarLivro(Object obj);

}
