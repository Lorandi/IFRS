<template>
  <div class="nav-main">
    <div>
      <div class="nav">
        <div class="router">
          <router-link to="/">Início</router-link>
        </div>
        <div class="router">
          <router-link to="/trabalho">Trabalho </router-link>
        </div>
        <div class="router">
          <router-link to="/estudo">Estudo</router-link>
        </div>
        <div class="router">
          <router-link to="/investimentos">Investimentos </router-link>
        </div>
        <div class="router">
          <router-link to="/lazer">Lazer</router-link>
        </div>
        <div class="router">
          <router-link to="/bens">Bens </router-link>
        </div>
        <div class="router">
          <router-link to="/compras">Compras </router-link>
        </div>
        <div class="router">
          <router-link to="/custos">Custos </router-link>
        </div>
        
      </div>
    </div>
    <div class="nav2">
      <div class="encapsula">
        <span class="left-span"> Receita: </span>
        <span class="right-span"> R$ {{ this.$store.state.receita }} </span>
      </div>
      <div class="encapsula">
        <span class="left-span"> Despesas: </span>
        <span class="right-span">R$ {{ this.$store.state.despesa }} </span>
      </div>
      <div class="encapsula">
        <span class="left-span"> Conta: </span>
        <span class="right-span"> R$ {{ parseFloat(this.$store.state.conta).toFixed(2) }} </span>
      </div>
      <div class="encapsula">
        <span class="left-span"> Cartão </span>
        <span class="right-span"> R$ {{ this.$store.state.cartao }} </span>
      </div>
      <div class="encapsula">
        <span class="left-span"> Dívida: </span>
        <span class="right-span"> R$ {{ this.$store.state.dividas }} </span>
      </div>
      <div class="encapsula">
        <span class="left-span"> Horas ocupadas: </span>
        <span class="right-span"> {{ this.$store.state.horasOcupadas }} / 12 </span>
      </div>
      <div class="encapsula">
        <span class="left-span"> Rodada: </span>
        <span class="right-span"> {{ this.$store.state.rodada }} / 200 </span>
      </div>
      <div class="router">
        <br>
          <passar-rodada></passar-rodada>
      </div>
      <div>
        <br>
        <button class="router" @click="this.$store.dispatch('reset')">Resetar</button>
      </div>
     
    </div>    
  </div>
  <div class="router-view">
    <router-view />
  </div>  
</template>
<script>

import { mapState } from 'vuex'
import PassarRodada from './components/PassarRodada.vue';

export default {
  created() {
    this.$store.dispatch("loadJobs");
    this.$store.dispatch("loadCosts");
    this.$store.dispatch("loadStudies");
  },
  computed: mapState([
    'receita',
    'despesas',
    'conta',
    'cartao',
    'dividas',
    'horasOcupadas',
    'rodada',
    'jobs',
    'studies',
    'costs',
    "life"]),
  components: { PassarRodada }
}

</script>


<style lang="scss">
.home {
  display: flex;
  align-items: flex-start;
  justify-content: center; 
}

#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
}

.router-view {
  margin-top: 66px;  
  margin-left: 200px;  
  }

.nav-main {  
  .nav {
  display: flex;
  padding: 5px;
  margin: auto;
  position: fixed;
  z-index: 1;
  top: 0;
  left: 0;
  width: 100%;
  text-align: center;
  background-color: rgb(37, 37, 37);
  color: white;
  justify-content: space-between;
  text-align: center;   
   
  .router{     
    display: flex;
    margin: auto;
    justify-content: space-between;
    align-items: center;
  }

    a {
      color: white;
      text-decoration: none;

      &.router-link-exact-active {
        color: #007bff;
      }
    }
  }

  .nav2 {
  width: 200px;
  height: 100%;
  background-color: #bbbbbb;
  position: fixed;
  color: white;
  top: 30px;
  z-index: 1;
  left: 0;
  overflow-x: hidden;

    .encapsula {
      display: flex;
      margin: auto;      
      padding: 5px ;
      flex: 1;
      display: flex;
      justify-content: space-between;
      align-items: center;
    }

    .left-span {
      text-align: left
    }

    .right-span {
      text-align: right;
      border: none;
    }

    a {
      color: white;
      text-decoration: none;

      &.router-link-exact-active {
        color: #007bff;
      }
    }
  }
}
</style>
