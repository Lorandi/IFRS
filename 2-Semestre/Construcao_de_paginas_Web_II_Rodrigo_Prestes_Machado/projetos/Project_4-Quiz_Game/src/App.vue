<template>
  <div>
    <h1 v-html="this.questions"></h1>

    <input type="radio" name="options" value="True" />
    <label>True</label><br>
    
    <input type="radio" name="options" value="False" />
    <label>False</label><br>

    <button class="send"  type="button">Send</button>
  </div>
</template>

<script>
export default{
  name: 'App',

  data(){
    return{
      questions: undefined,
      incorrectAnswers: undefined,
      correctAnswers: undefined
    }
  },

  created(){
    this.axios
    .get("https://opentdb.com/api.php?amount=1&category=18")
    .then((response) => {
      this.questions = response.data.results[0].question
      this.incorrectAnswers = response.data.results[0].incorrect_answers
      this.correctAnswers = response.data.results[0].correct_answer
  console.log(response.data.results[0])
})
  }

}
//https://opentdb.com/api.php?amount=1&category=18
</script>
 
  

<style lang="scss">
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin: 60px auto;
  max-width: 960px;

}

h1 {
  margin-top: 40px;
}

input[type='radio']{
  margin: 12px 4px;
}

button.send {
  margin-top: 12px;
  height: 40px;
  min-width: 120px;
  padding: 0 16px;
  color: #fff;
  background-color: #1867c0;
  border: 1px solid #1867c0;
  cursor: pointer;
}

section.score {
  border-bottom: 1px solid black;
  padding: 24px;
  font-size: 18px;

  span {
    padding: 8px;
    font-weight: bold;
    border: 1px solid black;
  }
}
</style>

