package enums;

public enum Category {
    ESCRITORIO("ESCRITÓRIO", "1"),
    ALIMENTCAO_E_BEBIDAS("ALIMENTAÇÃO E BEBIDAS", "2"),
    VESTUARIO("VESTUÁRIO","3"),
    HIGIENE_E_SAUDE("HIGIENE E SAÚDE", "4"),
    MEIO_DE_TRANSPORTE("MEIO DE TRANSPORTE", "5"),
    CATEGORY_NOT_FOUND("CATEGORY NOT FOUND", "");

    String description;
    String value;

    Category(String description, String value) {
        this.description = description;
        this.value = value;
    }

    public String getValue() {
        return value;
    }

    public String getDescription() {
        return description;
    }

    public static Category getByCode(String code) {
        for (Category e : Category.values()) {
            if (e.getValue().equals(code)) {
                return e;
            }
        }
        for (Category e : Category.values()) {
            if (e.getDescription().equals(code)) {
                return e;
            }
        }

        return CATEGORY_NOT_FOUND;
    }
}