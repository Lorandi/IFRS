import { createStore } from 'vuex'
import axios from "axios";
import jobs from './jsons/jobs.json';

export default createStore({
  state: {
    products: [],
    productsInBag: [],
    jobs: [],
    receita:0,
    despesas:0,
    conta:0,
    cartao: 0,
    dividas: 0,
    horasOcupadas: 0,
    rodada: 1    
  },
  mutations: {

    loadProducts(state, products){
      console.log(products);
      state.products = products;
    },

    addToBag(state, product){
      state.productsInBag.push(product);
      localStorage.setItem('productsInBag', JSON.stringify(state.productsInBag));
    },

    removeFromBag(state, productId){
      state.productsInBag = state.productsInBag.filter(product => product.id !== productId);
      localStorage.setItem('productsInBag', JSON.stringify(state.productsInBag));
    },
    
    loadBag(state, products){
      state.productsInBag = products;
    },

    addRodada(state, rodada){
      state.rodada = rodada;
    },

    loadJobs(state, jobs){
      console.log(jobs);
      state.jobs = jobs;
    },

    addReceita(state, receita){
      state.receita = receita;
    },

    addHorasOcupadas(state, horasOcupadas){
      state.horasOcupadas = horasOcupadas;
    },

    receitaNaConta(state, conta){
      state.conta = conta;
    }
    
  },
  actions: {
    receitaNaConta({ commit }, receita){
      console.log(receita); 
      commit('receitaNaConta', receita);
    },

    addHorasOcupadas({commit}, horasOcupadas){
      commit('addHorasOcupadas', horasOcupadas);
    },    

    addReceita({commit}, receita){
      commit('addReceita', receita);
    },

    addRodada({commit},  rodada){  
      commit('addRodada', rodada);
    },

    loadJobs({ commit }) {
      commit('loadJobs', jobs);
    },

    loadProducts({commit}){
      axios
      .get("https://fakestoreapi.com/products")
      .then((response) => {
        commit('loadProducts',response.data); 
      })
    },

    loadBag({commit}){     
      if(localStorage.getItem('productsInBag')){
        let productsInBag = JSON.parse(localStorage.getItem('productsInBag'));
        commit('loadBag', productsInBag);
      }     
    },

    addToBag({commit}, product){
      commit('addToBag', product);
    },

    removeFromBag({commit}, productId){
      if(confirm("Are you sure you want to remove this item?")){
            commit('removeFromBag', productId);
      }
  
    }
  },  
  modules: {
  }
})
