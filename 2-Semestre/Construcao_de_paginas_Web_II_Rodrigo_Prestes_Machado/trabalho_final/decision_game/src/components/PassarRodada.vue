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
  computed: mapState(["receita", "conta", "rodada", "despesa", "studies", "horasOcupadas"]),

  methods: {
    passarRodada(rodada) {

      var horasOcupadas = this.$store.state.horasOcupadas;
      var studies = this.$store.state.studies;
      this.somarHorasDeEstudo(studies, horasOcupadas);

      rodada++;
      var receita = parseFloat(this.$store.state.receita);
      var despesa = parseFloat(this.$store.state.despesa);
      var conta = parseFloat(this.$store.state.conta);
      var saldo = receita - despesa;

      if (conta < 0) {
        //juros 10% cheque especial
        conta = conta * 1.1;    
      }

      this.$store.dispatch("balancoConta", (parseFloat(saldo) + parseFloat(conta)).toFixed(2));
      this.$store.dispatch("addRodada", rodada);
    },

    somarHorasDeEstudo(studies, horasOcupadas) {
      
      for (var i = 0; i < studies.length; i++) {
        if (studies[i].active) {
          var hoursCompleted = parseInt(studies[i].hoursCompleted);
          var tempHour = parseInt(studies[i].tempHour);
          var hoursToComplete = parseInt(studies[i].hoursToComplete);

          hoursCompleted += tempHour;
          studies[i].hoursCompleted = hoursCompleted;
          if (hoursCompleted >= hoursToComplete) {
            studies[i].status = "completed";
            studies[i].active = false;
            this.$store.dispatch("addHorasOcupadas", parseInt(horasOcupadas) - parseInt(studies[i].tempHour));
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