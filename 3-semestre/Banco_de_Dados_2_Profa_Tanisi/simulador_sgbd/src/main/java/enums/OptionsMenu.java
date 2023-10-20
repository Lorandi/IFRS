package enums;

public enum OptionsMenu {

    NEW_PRODUCT("1"),
    EDIT_PRODUCT("2"),
    REMOVE_PRODUCT("3"),
    SEE_DATABASE("4"),
    SEE_MEMORY("5"),
    COMMIT("6"),
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