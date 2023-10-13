package exceptions;

import java.text.MessageFormat;

public class EmptyFieldExcepion extends Exception{
    public EmptyFieldExcepion(String campo) {
        super(MessageFormat.format("Campo {campo} não pode estar vazio","campo"));
    }
}