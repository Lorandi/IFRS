package enums;

public enum Category {
    ESCRITORIO("ESCRITÓRIO"),
    ALIMENTCAO_E_BEBIDAS("ALIMENTAÇÃO E BEBIDAS"),
    VESTUARIO("VESTUÁRIO"),
    HIGIENE_E_SAÚDE("HIGIENE E SAÚDE"),
    MEIO_DE_TRANSPORTE("MEIO DE TRANSPORTE"),
    OUTROS("Outros"),
    ROUPAS("Roupas"),
    ACESSORIOS("Acessórios"),
    CALCADOS("Calçados");


    String value;

    Category(String value) {
        this.value = value;
    }

    public String getValue() {
        return value;
    }


}
