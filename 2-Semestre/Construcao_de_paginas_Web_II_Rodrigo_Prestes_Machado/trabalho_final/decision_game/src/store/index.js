import { createStore } from 'vuex'
import jobs from './jsons/jobs.json';
import costs from './jsons/costs.json';


export default createStore({
  state: {
    products: [],
    productsInBag: [],
    jobs: [],
    costs: [],
    receita:0,
    despesa:0,
    conta:0,
    cartao: 0,
    dividas: 0,
    horasOcupadas: 0,
    rodada: 1    
  },
  mutations: {    

    addRodada(state, rodada){
      state.rodada = rodada;
    },

    addReceita(state, receita){
      state.receita = receita;
    },

    addDespesa(state, despesa){
      state.despesa = despesa;
    },

    addHorasOcupadas(state, horasOcupadas){
      state.horasOcupadas = horasOcupadas;
    },

    balancoConta(state, conta){
      state.conta = conta;
    }
    ,

    loadJobs(state, jobs){
      console.log(jobs);
      state.jobs = jobs;
    },

    loadCosts(state, costs){
      console.log(costs);
      state.costs = costs;
    }
    
  },
  actions: {
    loadJobs({ commit }) {
      commit('loadJobs', jobs);
    },

    loadCosts({ commit }) {     
      commit('loadCosts', costs);
    },

    balancoConta({ commit },saldo){            
      commit('balancoConta',saldo);
    },

    addHorasOcupadas({commit}, horasOcupadas){
      commit('addHorasOcupadas', horasOcupadas);
    },    

    addReceita({commit}, receita){
      commit('addReceita', receita);
    },

    addDespesa({commit}, despesa){
      commit('addDespesa', despesa);
    },

    addRodada({commit},  rodada){  
      commit('addRodada', rodada);
    },

    
    
  },  
  modules: {
  }
})
