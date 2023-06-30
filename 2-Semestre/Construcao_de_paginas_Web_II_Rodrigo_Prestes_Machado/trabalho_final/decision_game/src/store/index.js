import { createStore } from "vuex";
import jobs from "./jsons/jobs.json";
import costs from "./jsons/costs.json";
import studies from "./jsons/studies.json";

export default createStore({
  state: {
    products: [],
    productsInBag: [],
    jobs: [],
    costs: [],
    studies: [],
    seniority: [],
    receita: 0,
    despesa: 0,
    conta: 0,
    cartao: 0,
    dividas: 0,
    horasOcupadas: 0,
    rodada: 1,
    life: {
      health: 100,
      workedHours: 0,
      studiedHours: 0,
      satisfaction: 100,
      energy: 100,
      seniority: null,
      skills: ["Alfabetizado"],
      workExpirience: ["Nenhuma"],
    },
  },
  mutations: {
    addRodada(state, rodada) {
      state.rodada = rodada;
    },

    addReceita(state, receita) {
      state.receita = receita;
    },

    addDespesa(state, despesa) {
      state.despesa = despesa;
    },

    addHorasOcupadas(state, horasOcupadas) {
      state.horasOcupadas = horasOcupadas;
    },

    balancoConta(state, conta) {
      state.conta = conta;
    },
    loadJobs(state, jobs) {
      console.log(jobs);
      state.jobs = jobs;
    },

    loadCosts(state, costs) {
      console.log(costs);
      state.costs = costs;
    },

    loadStudies(state, studies) {
      console.log(studies);
      state.studies = studies;
    },
    addConta(state, conta) {
      state.conta = conta;
    },

    addSeniority(state, seniority) {
      state.life.seniority = seniority;
    },

    addSkills(state, skills) {
      state.life.skills.push(skills);
    },

    addWorkExpirience(state, workExpirience) {
      state.life.workExpirience.push(workExpirience);
    },

    addHealth(state, health) {
      state.life.health += health;
      if (state.life.health > 100) {
        state.life.health = 100;
      }

      if (state.life.health < 0) {
        state.life.health = 0;
        alert("Você morreu!"); 
        location.reload();         
      }

    },

    addSatisfaction(state, satisfaction) {
      state.life.satisfaction += satisfaction;
      if (state.life.satisfaction > 100) {
        state.life.satisfaction = 100;
      }
      if (state.life.satisfaction < 50) {
        state.life.health -= 1;
      }

      if(state.conta < 0 && state.conta > -999){
        state.life.satisfaction -= 1;
      }

      if(state.conta < -1000){
        state.life.satisfaction -= 5;
      } 

      if(state.life.satisfaction < 0){
        state.life.satisfaction = 0;
      }
    }
  },

  actions: {

    addSatisfaction({ commit }, satisfaction) {
      commit("addSatisfaction", satisfaction);
    },

    addHealth({ commit }, health) {
      commit("addHealth", health);
    },

    addWorkExpirience({ commit }, workExpirience) {
      commit("addWorkExpirience", workExpirience);
    },

    addSkills({ commit }, skills) {
      commit("addSkills", skills);
    },

    addSeiority({ commit }, seniority) {
      commit("addSeniority", seniority);
    },

    addConta({ commit }, conta) {
      commit("addConta", conta);
    },

    loadStudies({ commit }) {
      commit("loadStudies", studies);
    },

    loadJobs({ commit }) {
      commit("loadJobs", jobs);
    },

    loadCosts({ commit }) {
      commit("loadCosts", costs);
    },

    balancoConta({ commit }, saldo) {
      commit("balancoConta", saldo);
    },

    addHorasOcupadas({ commit }, horasOcupadas) {
      commit("addHorasOcupadas", horasOcupadas);
    },

    addReceita({ commit }, receita) {
      commit("addReceita", receita);
    },

    addDespesa({ commit }, despesa) {
      commit("addDespesa", despesa);
    },

    addRodada({ commit }, rodada) {
      commit("addRodada", rodada);
    },
  },
  modules: {},
});
