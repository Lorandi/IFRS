import { createRouter, createWebHashHistory } from "vue-router";
import Home from "../views/HomePage.vue";
import Trabalho from "../views/WorkPage.vue";
import Custos from "../views/CostsPage.vue";
import Estudos from "../views/StudyPage.vue";

const routes = [
  {
    path: "/",
    name: "Home",
    component: Home,
  },

  {
    path: "/trabalho",
    name: "Trabalho",
    component: Trabalho,
  },

  {
    path: "/estudo",
    name: "Estudo",
    component: Estudos,
  },

  {
    path: "/investimentos",
    name: "Investimento",
    component: Home,
  },

  {
    path: "/lazer",
    name: "Lazer",
    component: Home,
  },

  {
    path: "/bens",
    name: "Bens",
    component: Home,
  },

  {
    path: "/compras",
    name: "compras",
    component: Home,
  }, 

  {
    path: "/custos",
    name: "custos",
    component: Custos,
  },

];

const router = createRouter({
  history: createWebHashHistory(),
  routes,
});

export default router;
