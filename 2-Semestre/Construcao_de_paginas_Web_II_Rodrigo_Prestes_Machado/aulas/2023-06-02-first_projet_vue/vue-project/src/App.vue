<template>
  <h1>{{ msg }}</h1>
  <router-link to="/task">Task</router-link> 
  <br>
  <router-link to="/image">Image</router-link>
  <router-view v-slot="{Component}">
    <keep-alive>
      <component :is="Component" />
    </keep-alive>
  </router-view>




</template>

<script >
export default {
  name: 'App',
  data() {
    return {
      msg: 'Estou no App.vue',
    }
  }
}
</script>

<style >
</style>
