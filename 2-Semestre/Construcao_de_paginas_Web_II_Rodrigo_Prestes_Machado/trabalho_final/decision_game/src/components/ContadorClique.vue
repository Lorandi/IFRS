<template>
  <div class="container">
    <button @click="contarCliques" class="botao-azul">RODAR</button>
    <span class="total">{{ contador }}</span>
  </div>
</template>

<script>
export default {
  data() {
    return {
      contador: 0
    };
  },
  methods: {
    contarCliques() {
      this.contador++;
    }
  }
};
</script>

<style>
.container {
  display: flex;
  align-items: center;
  justify-content: center;
  flex-direction: row;
}

.botao-azul {
  background-color: blue;
  color: white;
  padding: 10px 20px;
  border: none;
  cursor: pointer;
}

.total {
  margin-left: 10px;
  font-weight: bold;
}
</style>
