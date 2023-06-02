<template>
  <h1>{{ msg }}</h1>
  <h2 v-for="item in todo">{{ item.text }} : {{ item.status }}</h2>
  <input type="text" v-model="newTodo" />
  <button v-on:click="addTodo()">Add</button>
</template>

<script >
export default {
  name: 'Task',
  data() {
    return {
      msg: 'Estou no Task.vue',
      todo: [
        { text: 'Learn JavaScript', status: 'dont' },
        { text: 'Learn Vue', status: 'done' },
        { text: 'Build something awesome', status: 'cancel' }],
        newTodo: '' // Add the newTodo property here and initialize it to an empty string
    }
  },
  methods: {
    addTodo() {
      this.todo.push({ text: this.newTodo, status: 'dont' })
      this.newTodo = ''
    }
  }
}

</script>

<style >
h1 {
  color: blue;
}

h2 {
  color: red;
}
</style>
