<template>
  <main class="home">
    <section class="studies">
      <h4>Cursos</h4>
      <div v-for="(study, index) in this.studies" :key="index" class="study" :class="{ selected: study.active }">
        <h3>{{ study.name }}</h3>
        <h4>Custo: R${{ study.value.toFixed(2) }} </h4>
        <h4>Duração: {{ study.hoursToComplete }} horas</h4>
        <h4>Senioridade: {{ study.seniority }}</h4>
        <div class="hours-area" v-if="study.active && study.status === 'started'">
          <button @click.stop="study.tempHour--, subtrairHoras(horasOcupadas)" :disabled="study.tempHour <= 0">-</button>
          <span class="hours"> {{ study.tempHour }} horas </span>
          <button v-if="study.tempHour < 12 && horasOcupadas < 12"
            @click.stop="study.tempHour++; somarHoras(horasOcupadas)">+</button>
          <button v-else @click.stop=alertaLimites()>+</button>
          <h5>{{ calculaRodadas(study) }}</h5>
        </div>
        
        <button v-if="study.status === 'notStarted'" @click.stop="toggleStudyActive(study, horasOcupadas)">
          Iniciar curso
        </button>
        <button class="finalizado" v-if="study.status === 'completed'">
          Concluído
        </button>

      </div>
    </section>

    <section class="summary">
      <strong>Cursos</strong>
      <table>
        <thead>
          <tr>
            <th>Em andamento</th>
            <th class="center">Horas</th>
          </tr>
        </thead>
        <tbody>
          <tr v-for="(study, index) in this.studies" :key="index">
            <template v-if="study.active && study.status != 'completed'">
              <td> {{ study.name }} </td>
              <td class="center"> {{ study.hoursCompleted }} / {{ study.hoursToComplete }}</td>
            </template>
          </tr>
        </tbody>
      </table>
      <table>
        <thead>
          <tr>
            <th>Finalizados</th>
            <th class="center">Horas</th>
          </tr>
        </thead>
        <tbody>
          <template v-if="hasCompletedStudies()">
            <tr v-for="(study, index) in this.studies" :key="index">
              <template v-if="study.status === 'completed'">
                <td>{{ study.name }}</td>
                <td class="center">{{ study.hoursToComplete }}</td>
              </template>
            </tr>
          </template>
          <template v-else>
            <tr>
              <td>Nenhum curso finalizado</td>
            </tr>
          </template>
        </tbody>
      </table>
    </section>

  </main>
</template>

<script>
import { mapState } from "vuex";

export default {
  name: "WorkPage",
  data() {
    return {};
  },

  computed: mapState(["studies", "receita", "horasOcupadas", "conta", "life"]),

  methods: {

    calculaRodadas(study){
      // console.log(study.hoursToComplete);
      var rodadas =  Math.ceil(study.hoursToComplete/(study.tempHour*22));
      if(rodadas <= study.hoursToComplete){
        return "Curso acaba em " +rodadas+ " rodadas";
      }else{
        return "";
      }

    },
     
    
    hasCompletedStudies() {
      return this.studies.some(study => study.status === 'completed');
    },

    alertaLimites: function () {
      alert("Limite de horas alcançado! Você não pode selecionar mais trabalhos ou horas.");
    },

    toggleStudyActive(study) {
      var conta = parseFloat(this.$store.state.conta);
      var skills = this.$store.state.life.skills;
      // var seniority = this.$store.state.life.seniority;
      var prerequisites = study.prerequisites;

      if (!skills.includes(prerequisites)) {
        alert("Esse curso tem o pré-requisito " + prerequisites + " que você não possui!");
        return;
      }


      if (conta < -1000 || (conta - study.value) < -1000) {
        alert("Você não tem saldo suficiente para iniciar um curso!");
        return;
      }
      if (this.horasOcupadas >= 12 && !study.active) {
        alert("Limite de horas alcançado! Você não pode selecionar mais trabalhos.");
        return;
      }
      if (study.status === 'notStarted' && confirm(`Você realmente quer começar este curso? O valor é de R$ ${study.value.toFixed(2)}`)) {
        study.status = 'started';
        study.active = !study.active;

        this.$store.dispatch("addConta", conta - study.value.toFixed(2));  
      }
    },

    somarHoras(horasOcupadas) {
      if (horasOcupadas >= 12) {
        // Limite de horas alcançado, exibir alerta
        alert("Limite máximo de horas alcançado!");
        return;
      }
      horasOcupadas++;
      this.$store.dispatch("addHorasOcupadas", horasOcupadas);
    },

    subtrairHoras(horasOcupadas) {
      horasOcupadas--;
      this.$store.dispatch("addHorasOcupadas", horasOcupadas);
    },

  }
};
</script>

<style lang="scss">
.home {
  display: flex;
  justify-content: center;
  align-items: flex-start;
  flex-wrap: wrap;
  padding-top: 50px;
  justify-content: flex-start;
  flex-direction: row;


  .studies {
    display: flex;
    flex-wrap: wrap;
    border: 1px solid lightgrey;
    padding: 20px;
    max-width: 800px;
    min-width: 400px;
    flex-direction: row;
    align-content: space-around;
    justify-content: space-between;


    h4 {
      text-align: center;
      margin-top: 0;
      width: 100%;
    }

    .study {
      flex: 0 0 30%;
      box-sizing: border-box;
      box-shadow: 0 4px 8px 0 rgba(0, 0, 0, 0.2);
      padding: 16px;
      margin: 8px;
      height: 330px;

      @media only screen and (max-width: 769px) {
        flex: 0 0 40%;
      }

      @media only screen and (max-width: 640px) {
        flex: 0 0 90%;
      }

      .study-image {
        margin: auto;
        width: 80%;
        height: 140px;
        background-size: contain;
        background-position: center;
        background-repeat: no-repeat;
      }

      h4 {
        font-size: 15px;
        font-weight: bold;
        margin: 22px auto;

        max-width: 60%;
        font-weight: normal;
      }

      p.salaryPerHour {
        font-size: 15px;
        font-weight: bold;
      }

      input.hours {
        width: 40%;
        height: 30px;
        border: 1px solid #007bff;
        border-radius: 100px;
        padding: 0 16px;
        margin: 8px 0;
        box-sizing: border-box;
      }

      button {
        color: #fff;
        background-color: #007bff;
        border: 1px solid #007bff;
        border-radius: 50px;
        font-weight: 400;
        text-align: center;
        padding: 8px 16px;
        cursor: pointer;

        &:hover {
          opacity: 0.8;
        }

        &.sair {
          background-color: transparent;
          border: none;
          color: black;
          text-decoration: underline;
        }
      }

      button.finalizado {
        color: #fff;
        background-color: #ee0000;
        border: 1px solid #ff0000;
        border-radius: 50px;
        font-weight: 700;
        text-align: center;
        padding: 8px 16px;
        cursor: pointer;

        &.sair {
          background-color: transparent;
          border: none;
          color: black;
          text-decoration: underline;
        }
      }




    }

    .study.selected {
      border: 2px solid rgb(29, 134, 233);
    }

    .study.finalizados {
      border: 2px solid rgb(255, 000, 000);
    }

    .hours-area {
      margin: 8px auto;
      height: 14px;
    }

    .hours-area button {
      border-radius: 5px;
      background-color: #aaaaaa;
      border: 1px solid #999999;
      width: 16px;
      height: 16px;
      display: inline-flex;
      justify-content: center;
      align-items: center;
      cursor: pointer;
      padding: 8px 8px;
    }

    .hours-area .quantity {
      font-weight: bold;
      margin: 0 4px;
    }
  }

  .summary {
    background-color: rgb(245, 245, 245);
    padding: 20px;
    min-width: 350px;
    text-align: left;

    table {
      width: 100%;
      padding-top: 12px;
      font-size: 15;
      margin: auto;

      tbody tr:last-of-type th {
        border-top: 1px solid black;
        padding-top: 4px;
      }
    }
  }

  .center {
    text-align: center;
  }
}
</style>
