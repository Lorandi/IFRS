// import './assets/main.css'

import { createApp } from 'vue'
import { createRouter, createWebHistory } from 'vue-router'
import App from './App.vue'
import Task from './components/Task.vue'
import Image from './components/Image.vue'

const router = createRouter({
  history: createWebHistory(),
  routes: [
    { path: '/task', component: Task },
    { path: '/image', component: Image }
  ]
});

const app = createApp(App)
app.use(router)
app.mount('#app')
