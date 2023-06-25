<template>
    <div class="container">
      <button @click="contarCliques(rodada)" class="botao-azul">Passar Rodada</button>
    </div>
  </template>
  
  <script>  
  import { mapState } from "vuex";

  export default {

    name: "PassarRodada",
  data() {
    return {};
  },
  computed: mapState(["receita", "conta", "rodada"]),

    methods: {
      contarCliques(rodada) { 
        rodada++;  
        var guardar = (parseFloat( this.$store.state.receita) + parseFloat(this.$store.state.conta)).toFixed(2);
        this.$store.dispatch("receitaNaConta", guardar);
        this.$store.dispatch("addRodada", rodada);
      },      
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

  .botao-azul:hover {
    background-color: rgb(0,0,200);
  }
  
  .total {
    margin-left: 10px;
    font-weight: bold;
  }
  </style>