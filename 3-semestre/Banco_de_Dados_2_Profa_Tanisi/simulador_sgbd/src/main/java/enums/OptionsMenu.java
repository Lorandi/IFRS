package enums;

public enum OptionsMenu {

    TRANSACTION("1"),
    LOG_BUFFER("2"),
    LOG_DISC("3"),
    DATABASE_BUFFER("4"),
    DATABASE_DISC("5"),
    FAIL("6"),
    EXIT("7"),
    ERROR("");

    String value;

    OptionsMenu(String valueOption) {
        value = valueOption;
    }

    public String getValue() {
        return value;
    }


    public static OptionsMenu getByCode(String code) {
        for (OptionsMenu e : OptionsMenu.values()) {
            if (e.getValue().equals(code)) {
                return e;
            }
        }
        return ERROR;
    }
}