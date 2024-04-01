package menu;

public enum MenuEnums {
    CADASTRAR_CLIENTE_PF("Cadastrar Cliente Pessoa Física"),
    PESQUISAR_CLIENTE_PF_POR_NOME("Pesquisar Cliente Pessoa Física pelo nome"),
    PESQUISAR_CLIENTE_PF_POR_CPF("Pesquisar Cliente Pessoa Física pelo CPF"),
    PESQUISAR_CLIENTE_PF_POR_NUMERO_CONTA("Pesquisar Cliente Pessoa Física pelo número da conta"),
    LISTAR_CLIENTES_MESMA_AGENCIA("Listar todos os clientes de uma mesma agência"),
    LISTAR_TODOS_CLIENTES("Listar todos os clientes"),
    SAIR("Sair");

    MenuEnums(String descricao) {
        this.descricao = descricao;
    }

    private final String descricao;

    public String getDescricao() {
        return descricao;
    }

    public int getOrdinal() {
        return this.ordinal();
    }

    public static String getMenu() {
        StringBuilder menu = new StringBuilder();
        for (MenuEnums menuEnum : MenuEnums.values()) {
            menu.append(menuEnum.getOrdinal() + 1).append("-").append(menuEnum.getDescricao()).append("\n");
        }
        return menu.toString();
    }

}
