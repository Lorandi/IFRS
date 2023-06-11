var todos = [
  //   {
  //     text: "Learn JavaScript",
  //     done: true,
  //   },
  //   {
  //     text: "Learn Vue",
  //     done: false,
  //   },
];

const todoApp = {
  data() {
    return {
      todos: [],
      newTodo: {
        text: "",
        done: false,
      },
    };
  },
  methods: {
    addTodo() {
      if (this.newTodo.text.trim() === "") return;
      this.todos.push(this.newTodo);
      this.newTodo = {
        text: "",
        done: false,
      };
      localStorage.setItem("todos", JSON.stringify(this.todos));
    },
    //usar esse método para atualizar o localstorage caso o usuário clique em uma tarefa
    //Necessário para o localstorage não seja atualizado a cada letra digitada    
    storeTodos() {
      localStorage.setItem("todos", JSON.stringify(this.todos));
      console.log("updated");
    },
    deleteTodo(todo) {
        const index = this.todos.indexOf(todo);
        if (index !== -1) {
          this.todos.splice(index, 1);
          localStorage.setItem("todos", JSON.stringify(this.todos));
        }
    }
  },
  computed: {
    completedTasks() {
      return this.todos.filter((todo) => todo.done).length;
    },
    totalTasks() {
      return this.todos.length;
    },
  },
  created() {
    this.todos = JSON.parse(localStorage.getItem("todos")) || [];
  },  
  updated() { 
    //localStorage sendo atualizado a cada letra digitada  
    localStorage.setItem("todos", JSON.stringify(this.todos));
    console.log("updated"); 
  }

};

Vue.createApp(todoApp).mount("#app");
