<template>
  <template v-if="this.questions">
    <ScoreBoard :winCount="this.winCount" :loseCount="this.loseCount" />
    <h1 v-html="this.questions"></h1>

    <template v-for="(answer, index) in this.answers" :key="index">
      <input :disabled="this.answerSubmitted" type="radio" name="options" :value="answer" v-model="this.chosenAnswer" />
      <label v-html="answer"></label><br />
    </template>

    <button v-if="!this.answerSubmitted" @click="this.submitAnswer()" class="send" type="button">Send</button>
    <br />

    <section v-if="this.answerSubmitted" class="result">
      <h4 v-if="this.chosenAnswer == this.correctAnswers" v-html="
        ' &#9989; Congratulations, the answer' +        this.correctAnswers  +      ' is corr'      ">
      </h4>
      <h4 v-else v-html="
        ' &#10060; Sorry, you picked the wrong answer. The correct ' +          this.correctAnswers + '.' ">
      </h4>
      <button @click="this.getNewQuestion()" class="send" type="buttton">
        Next question
      </button>
    </section>
    <button @click="this.resetBoard()" class="send" type="button">Reset Board</button>
  </template>
</template>

<script>
import ScoreBoard from "./components/ScoreBoard.vue";

export default {
  name: "App",
  components: {
    ScoreBoard,
  },

  data() {
    return {
      questions: undefined,
      incorrectAnswers: undefined,
      correctAnswers: undefined,
      chosenAnswer: undefined,
      answerSubmitted: false,
      winCount: 0,
      loseCount: 0,
    };
  },

  computed: {
    answers() {
      //JSON.parse(JSON.stringify()) is used to make a copy of the array
      //so that we can push the correct answer into the array
      //without mutating the original array
      var answers = JSON.parse(JSON.stringify(this.incorrectAnswers));
      answers.splice(
        Math.round(Math.random() * answers.length),
        0,
        this.correctAnswers
      );
      return answers;
    },
  },
  methods: {
    resetBoard() {
      this.winCount = 0;
      this.loseCount = 0;
      localStorage.setItem("winCount", JSON.stringify(this.winCount));
      localStorage.setItem("loseCount", JSON.stringify(this.loseCount));
    },
    submitAnswer() {
      if (!this.chosenAnswer) {
        alert("Please choose an answer");
        return;
      } else {
        this.answerSubmitted = true;
        if (this.chosenAnswer == this.correctAnswers) {
          this.winCount++;
          localStorage.setItem("winCount", JSON.stringify(this.winCount));
        } else {
          this.loseCount++;
          localStorage.setItem("loseCount", JSON.stringify(this.loseCount));
        }
      }
    },
    getNewQuestion() {
      this.answerSubmitted = false;
      this.chosenAnswer = undefined;
      this.questions = undefined;
      this.axios
        .get("https://opentdb.com/api.php?amount=1&category=18")
        .then((response) => {
          this.questions = response.data.results[0].question;
          this.incorrectAnswers = response.data.results[0].incorrect_answers;
          this.correctAnswers = response.data.results[0].correct_answer;
          console.log(response.data.results[0]);
        });
    },
  },
  created() {
    this.getNewQuestion();
    this.winCount = JSON.parse(localStorage.getItem("winCount")) || 0;
    this.loseCount = JSON.parse(localStorage.getItem("loseCount")) || 0;
  },


};
//https://opentdb.com/api.php?amount=1&category=18
</script>

<style lang="scss">
#app {
  display: block;
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

input[type="radio"] {
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
