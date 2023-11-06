package enums;

public enum TransactionsMenu {

    START_TRANSACTION("1"),
    CHOOSE_TRANSACTION("2"),
    END_TRANSACTION("3"),
    BACK("4"),
    ERROR("");

    String value;

    TransactionsMenu(String valueOption) {
        value = valueOption;
    }

    public String getValue() {
        return value;
    }


    public static TransactionsMenu getByCode(String code) {
        for (TransactionsMenu e : TransactionsMenu.values()) {
            if (e.getValue().equals(code)) {
                return e;
            }
        }
        return ERROR;
    }
}