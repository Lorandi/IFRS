<template>
  <h1>{{msg}}</h1>
  {{url}}
</template>

<script >
export default {
  name: 'Image',
  props: {
    url: String
  },
  data() {
    return {
      msg: 'Estou no Image.vue',
    }
  }
}
</script>

<style >
</style>
