<template>
  <main class="home">
    <section class="studies">
      <h4>Cursos</h4>
      <div v-for="(study, index) in this.studies" :key="index" class="study"  @click="toggleStudyActive(study, horasOcupadas)"
        :class="{ selected: study.active }">        
        <h3>{{ study.name }}</h3>
        <h4>Custo: R${{ study.value.toFixed(2) }} </h4>
        <h4>Duração: {{study.hoursToComplete }} horas</h4>
        <h4>Senioridade: {{ study.seniority }}</h4>      
        <div class="hours-area" v-if="study.active">
          <button @click.stop="study.hours--, subtrairHoras(horasOcupadas)" :disabled="study.hours <= 1">-</button>
          <span class="hours"> {{ study.hours }} horas </span>
          <button v-if="study.hours < 12 && horasOcupadas < 12"
            @click.stop="study.hours++; somarHoras(horasOcupadas)">+</button>
          <button v-else @click.stop=alertaLimites()>+</button>          
        </div>

      </div>
    </section>

    <section class="summary">
      <strong>Contratos</strong>
      <span v-if="total() <= 0">
        Não há contratos ativos
      </span>
      <div v-if="total() > 0">
        <table>
          <thead>
            <tr>
              <th>study</th>
              <th class="center">Horas</th>
              <th class="center">Total/mês</th>
            </tr>
          </thead>
          <tbody>
            <tr v-for="(study, index) in this.studies" :key="index">
              <template v-if="study.active">
                <td> {{ study.name }} </td>
                <td class="center"> {{ study.hours }} </td>
                <td class="center"> R$ {{ (study.hours * study.salaryPerHour * 22).toFixed(2) }} </td>
              </template>
            </tr>

            <tr>
              <th>Total</th>
              <th class="center">{{ totalHours(horasOcupadas) }}</th>
              <th class="center">R$ {{ total() }}</th>
            </tr>
          </tbody>
        </table>
      </div>
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

  computed: mapState(["studies", "receita", "horasOcupadas", "study"]),

  methods: {

    alertaLimites: function () {
      alert("Limite de horas alcançado! Você não pode selecionar mais trabalhos ou horas.");
    },
    total: function () {
      let total = 0;
      this.studies.forEach(study => {
        if (study.active) {
          total += study.hours * study.salaryPerHour * 22;
        }
      });

      this.$store.dispatch("addReceita", total.toFixed(2));

      return total.toFixed(2);
    },

    totalHours() {
      let hours = 0;
      this.studies.forEach(study => {
        if (study.active) {
          hours += study.hours
        }

      });
      return hours
    },

    toggleStudyActive(study, horasOcupadas) {
      if (this.horasOcupadas >= 12 && !study.active) {
        alert("Limite de horas alcançado! Você não pode selecionar mais trabalhos.");
        return;
      }
      study.active = !study.active;
      if (study.active) {
        study.hours = 1;
        this.somarHoras(horasOcupadas);
      } else if (!study.active) {
        var loops = study.hours;
        for (let i = 0; i < loops; i++) {
          this.subtrairHoras(this.horasOcupadas)
        }
        study.hours = 0;
      } else {
        this.subtrairHoras(horasOcupadas);
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
    }


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
    }

    .study.selected {
      border: 2px solid rgb(29, 134, 233);
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
