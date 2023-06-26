<template>
  <div class="container">
    <button @click="passarRodada(rodada)" class="botao-azul">Passar Rodada</button>
  </div>
</template>
  
<script>
import { mapState } from "vuex";

export default {

  name: "PassarRodada",
  data() {
    return {};
  },
  computed: mapState(["receita", "conta", "rodada", "despesa", "myStudies"]),

  methods: {
    passarRodada(rodada) {
      this.somarHorasDeEstudo()
      rodada++;
      var receita = parseFloat(this.$store.state.receita);
      var despesa = parseFloat(this.$store.state.despesa);
      var conta = parseFloat(this.$store.state.conta);
      var saldo = receita - despesa;

      if (conta < 0) {
        console.log("entrou no cheque especial?");
        console.log(conta);
        //juros 10% cheque especial
        conta = conta * 1.1;
        console.log("saindo");
        console.log(conta)
      }

      this.$store.dispatch("balancoConta", (parseFloat(saldo) + parseFloat(conta)).toFixed(2));
      this.$store.dispatch("addRodada", rodada);
    },

    somarHorasDeEstudo() {
      console.log("somando horas de estudo")
      var estudos = this.$store.state.myStudies; 
      console.log(estudos);     
      for(var i = 0; i < estudos.length; i++) {
        if(estudos[i].active) {
          var hoursCompleted = parseInt(estudos[i].hoursCompleted);
          var tempHour = parseInt(estudos[i].tempHour);
          var hoursToComplete = parseInt(estudos[i].hoursToComplete);

          hoursCompleted += tempHour;
          estudos[i].hoursCompleted = hoursCompleted;  
          if(hoursCompleted >= hoursToComplete) {
            estudos[i].status = "completed";            
          }
        }

      }     
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
  background-color: rgb(0, 0, 200);
}

.total {
  margin-left: 10px;
  font-weight: bold;
}
</style>