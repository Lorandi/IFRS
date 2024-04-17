package agenda;

import pessoas.Pessoa;

import java.util.Collection;
import java.util.LinkedList;
import java.util.List;


public class Agenda<E> implements OperacoesAgenda<E>{

    private final List<E> lista = new LinkedList<>();

    @Override
    public boolean cadastrar(E obj) {
        return lista.add(obj);
    }

    @Override
    public Collection<E> listarTodos() {
        return lista;
    }

    @Override
    public int totalizar() {
        return lista.size();
    }

    @Override
    public boolean remover(E obj) {
        return lista.remove(obj);
    }

    @Override
    public boolean pesquisar(E obj) {
        return lista.contains(obj);
    }

    public String toString() {
        StringBuilder aux = new StringBuilder();
        for (E e : lista) {
            if(e != null){
                aux.append(e.toString()).append("\n");
            }
        }
        if(aux.isEmpty()){
            aux.append("Lista vazia.");
        }

        return aux.toString();
    }


}
