<template>
  <main class="home">
    <section class="jobs">
      <h4>Oportunidades</h4>
      <div v-for="(job, index) in this.jobs" :key="index" class="job" @click="toggleJobActive(job, horasOcupadas)"
        :class="{ selected: job.active }">
        <div class="job-image" :style="{ backgroundImage: 'url(' + job.image + ')' }"></div>
        <h4>{{ job.name }}</h4>
        <p class="salaryPerHour">R$ {{ job.salaryPerHour.toFixed(2) }}/hora</p>
        <div class="hours-area" v-if="job.active">
          <button @click.stop="job.hours--, subtrairHoras(horasOcupadas)" :disabled="job.hours <= job.minWorkTime">-</button>
          <span class="hours"> {{ job.hours }} horas </span>
          <button v-if="job.hours < 12 && horasOcupadas < 12"
            @click.stop="job.hours++; somarHoras(horasOcupadas)" :disabled="job.hours >= job.maxWorkTime">+</button>
          <button v-else @click.stop=alertaLimites()>+</button>
          <p class="salaryPerHour">R$ {{ (job.hours * job.salaryPerHour * 22).toFixed(2) }} /mês</p>
        </div>
        <div v-if="!job.active">
        <span>Mínimo:{{ job.minWorkTime }} horas</span>
        <br>
        <span>Máximo:{{ job.maxWorkTime }} horas</span> 
        </div >
        
        
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
              <th>Job</th>
              <th class="center">Horas</th>
              <th class="center">Total/mês</th>
            </tr>
          </thead>
          <tbody>
            <tr v-for="(job, index) in this.jobs" :key="index">
              <template v-if="job.active">
                <td> {{ job.name }} </td>
                <td class="center"> {{ job.hours }} </td>
                <td class="center"> R$ {{ (job.hours * job.salaryPerHour * 22).toFixed(2) }} </td>
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

  computed: mapState(["jobs", "receita", "horasOcupadas", "life"]),

  methods: {

    alertaLimites: function () {
      alert("Limite de horas alcançado! Você não pode selecionar mais trabalhos ou horas.");
    },
    total: function () {
      let total = 0;
      this.jobs.forEach(job => {
        if (job.active) {
          total += job.hours * job.salaryPerHour * 22;
        }
      });

      this.$store.dispatch("addReceita", total.toFixed(2));

      return total.toFixed(2);
    },

    totalHours() {
      let hours = 0;
      this.jobs.forEach(job => {
        if (job.active) {
          hours += job.hours
        }

      });
      return hours
    },

    toggleJobActive(job ) {
      if (this.horasOcupadas >= 12 && !job.active) {
        alert("Limite de horas alcançado! Você não pode selecionar mais trabalhos.");
        return;
      }

      if(this.horasOcupadas + job.hours > 12 && !job.active){
        alert("Incluir esse trabalho excederia o limite de horas diárias!");
        return;
      }

      var jobSkills = job.skills;
      var lifeSkills = this.$store.state.life.skills;      

      var haveAllSkills = jobSkills.every(function (elemento) {
        return lifeSkills.includes(elemento);
      });     

      if (!haveAllSkills) {
        alert("Esse trabalho exigem skills que você não possui!");
        return;
      }

      var jobExpirience = job.workExpirience;
      var workExpirience = this.$store.state.life.workExpirience;     

      var haveAllWorkExpirience = jobExpirience.every(function (elemento) {
        return workExpirience.includes(elemento);
      });

      if(!haveAllWorkExpirience){
        alert("Esse trabalho exigem experiência pregressa que você não possui!");
        return;
      }

      var loops = job.hours;

      job.active = !job.active;
      if (job.active) {
        for (let i = 0; i < loops; i++) {          
          this.somarHoras(this.horasOcupadas)
        }  
        
      } else if (!job.active) {        
        for (let i = 0; i < loops; i++) {
          this.subtrairHoras(this.horasOcupadas)
        }        
      }
      
      if(!workExpirience.includes(job.name)){
        this.$store.dispatch("addWorkExpirience", job.name);
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

  .jobs {     
    display: flex;
    flex-wrap: wrap;
    border: 1px solid lightgrey;
    padding: 20px;
    max-width: 800px;
    min-width: 400px;
    flex-direction: row;
    align-content: space-around;
    justify-content: space-between; 
    background-color: #bbbbbb;

    h4 {
      text-align: center;
      margin-top: 0;
      width: 100%;
    }

    .job {
      flex: 0 0 30%;
      box-sizing: border-box;
      box-shadow: 0 4px 8px 0 rgba(0, 0, 0, 0.2);
      padding: 16px;
      margin: 8px;
      height: 330px;
      background-color: #ffffff;

      @media only screen and (max-width: 769px) {
        flex: 0 0 40%;
      }

      @media only screen and (max-width: 640px) {
        flex: 0 0 90%;
      }

      .job-image {
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

    .job.selected {
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
    width: auto;

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
