<template>
  <div id="nav">
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
      <span class="right-span"> R$ {{ this.$store.state.conta }} </span>
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
  </div>
  <div id="nav2">
    <div>
      <router-link to="/">Início</router-link>
    </div>
    <div>
      <router-link to="/trabalho">Trabalho </router-link>
    </div>
    <div>
      <router-link to="/estudo">Estudo</router-link>
    </div>
    <div>
      <router-link to="/investimentos">Investimentos </router-link>
    </div>
    <div>
      <router-link to="/lazer">Lazer</router-link>
    </div>
    <div>
      <router-link to="/bens">Bens </router-link>
    </div>
    <div>
      <router-link to="/compras">Compras </router-link>
    </div>
    <div>
      <router-link to="/custos">Custos </router-link>
    </div>
    <div>
      <passar-rodada></passar-rodada>
    </div>

  </div>
  <router-view />
</template>
<script>

import { mapState } from 'vuex'
import PassarRodada from './components/PassarRodada.vue';

export default {
  created() {
    this.$store.dispatch("loadJobs");
    this.$store.dispatch("loadCosts");
  },
  computed: mapState([
    'receita',
    'despesas',
    'conta',
    'cartao',
    'dividas',
    'horasOcupadas',
    'rodada']),
  components: { PassarRodada }
}

</script>


<style lang="scss">
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  max-width: 1280px;
  margin: 80px auto;

}

#nav {
  padding: 16px 0;
  position: fixed;
  z-index: 1;
  top: 0;
  left: 0;
  width: 100%;
  text-align: center;
  background-color: rgb(37, 37, 37);
  color: white;
  display: flex;
  justify-content: space-between;

  .encapsula {
    margin: 10px;
    padding: 5px 10px;
    flex: 1;
    border: 1px solid white;
    display: flex;
    justify-content: space-between;
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

#nav2 {
  padding: 5px 0px 5px;
  position: fixed;
  z-index: 1;
  top: 60px;
  left: 0;
  width: 100%;
  text-align: center;
  background-color: rgb(37, 37, 37);
  color: white;
  display: flex;
  justify-content: space-between;
  text-align: center;


  div {
    flex: 1;
    margin: auto;
    justify-content: space-evenly;
  }

  a {
    color: white;
    text-decoration: none;

    &.router-link-exact-active {
      color: #007bff;
    }
  }
}
</style>
