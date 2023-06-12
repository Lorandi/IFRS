<template>
  <div>
    <h1>Contador de Cliques</h1>
    <contador-cliques></contador-cliques>
  </div>
</template>

<script>
import ContadorCliques from './components/ContadorClique.vue';

export default {
  components: {
    ContadorCliques
  }
};
</script>

<style>
h1 {
  text-align: center;
}
</style>
