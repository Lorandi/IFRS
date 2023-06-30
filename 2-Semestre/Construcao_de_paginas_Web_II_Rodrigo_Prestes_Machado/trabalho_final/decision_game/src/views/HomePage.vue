<template>
  <div class="home">
    <div class = "table">
      <h1>Life Status</h1>
      <div class="table-container">
        <table class="styled-table">
          <tbody>
            <tr>
              <td>Health</td>
              <td>{{ lifeStatus().health}}</td>
            </tr>
            <tr>
              <td>Worked Hours</td>
              <td>{{ lifeStatus().workedHours }}</td>
            </tr>
            <tr>
              <td>Studied Hours</td>
              <td>{{ lifeStatus().studiedHours }}</td>
            </tr>
            <tr>
              <td>Satisfaction</td>
              <td>{{lifeStatus().satisfaction }}</td>
            </tr>
            <tr>
              <td>Energy</td>
              <td>{{lifeStatus().energy }}</td>
            </tr>
            <tr>
              <td>Seniority</td>
              <td>{{ lifeStatus().seniority || '-' }}</td>
            </tr>
            <tr>
              <td>Work Expirience</td>
              <td>
                 <li v-for="work in lifeStatus().workExpirience" :key="work">{{ work }}</li>   
              </td>
            </tr>
            <tr>
              <td>Skills</td>
              <td>
                 <li v-for="skill in lifeStatus().skills" :key="skill">{{ skill }}</li>   
              </td>
            </tr>
          </tbody>
        </table>
      </div>
    </div>
  </div>
</template>

<script>
import { mapState } from "vuex";

export default {
  name: "HomePage",
  data() {
    return {           
    };
  },
  computed: mapState(["life"]), 

  methods: {
    lifeStatus() {
      const { health, workedHours, studiedHours, satisfaction, energy, seniority, skills, workExpirience } = this.life;
      return {
        health,
        workedHours,
        studiedHours,
        satisfaction,
        energy,
        seniority,
        skills,
        workExpirience,
      };
    },
  },
};
</script>
<style lang="scss">

.table {
  display: flex;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  background-color: #bbbbbb;
  margin: auto;
}

.table-container {
  background-color: #ffffff;
  box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
  padding: 20px;
  margin: 20px;
  display: flex;
  justify-content: center;
  align-items: center;
}

h1 {
  margin-bottom: 20px;
}

.styled-table {
  width: 300px;
  border-collapse: collapse;
  margin-bottom: 20px;
}

.styled-table td,
.styled-table th {
  padding: 10px;
  text-align: left;
  border-bottom: 1px solid #dddddd;
}

.styled-table td {
  font-weight: bold;
}

.styled-table tr:last-child td {
  border-bottom: none;
}
</style>