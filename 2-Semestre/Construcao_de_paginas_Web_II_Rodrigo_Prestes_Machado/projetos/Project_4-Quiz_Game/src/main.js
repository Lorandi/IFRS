import './assets/main.css'
import axios from 'axios'
import VueAxios from 'vue-axios'

import { createApp } from 'vue'
import App from './App.vue'

createApp(App)
.mount('#app')
.use(VueAxios, axios)
