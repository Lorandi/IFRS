<template>
  <main class="home">
    <section class="costs">
      <h4>Custos</h4>
      <div v-for="(category, index) in  categories " :key="index" class="category">
        <div class="categorias">
          <h4> {{ category.name }}</h4>
          <div v-for=" (cost, index) in category.products" :key="index" class="cost" @click="cost.active = !cost.active" :class="{ selected: cost.active }">
            
            <div class="cost-image" :style="{ backgroundImage: 'url(' + cost.image + ')' }"></div>
            <h4>{{ cost.name }}</h4>
            <p class="salaryPerHour">R$ {{ (cost.cost).toFixed(2) }} /mês</p>
            <div class="hours-area" v-if="cost.active">
              <p class="salaryPerHour">Contratado</p>
            </div>
          </div>
        </div>
      </div>
    </section>
    <section class="summary">
      <strong>Contratos</strong>
      <span v-if="total() <= 0">
        Não há contratos ativos
      </span>
      <div v-if="total() > 0">
        <table>
          <thead>
            <tr>
              <th>Tipo</th>
              <th class="center">Valor</th>
            </tr>
          </thead>
          <tbody>
            <tr v-for="( cost, index ) in  this.costs " :key="index">
              <template v-if="cost.active">
                <td> {{ cost.name }} </td>
                <td > R$ {{ (cost.cost).toFixed(2) }} </td>
              </template>
            </tr>

            <tr>
              <th>Total</th>
              <th >R$ {{ total() }}</th>
            </tr>
          </tbody>
        </table>
      </div>
    </section>

  </main>
</template>

<script>
import { mapState } from "vuex";
export default {
  name: "CostPage",
  computed: {
    ...mapState(["costs", "despesa"]),
    categories() {
      const categories = {};
      this.costs.forEach((cost) => {
        if (!categories[cost.category]) {
          categories[cost.category] = {
            name: cost.category,
            products: [],
          };
        }
        categories[cost.category].products.push(cost);
      });

      return Object.values(categories);
    },
  },
  methods: {
    total() {
      let total = 0;
      Object.values(this.categories).forEach((category) => {
        category.products.forEach((cost) => {
          if (cost.active) {
            total += cost.cost;
          }
        });
      });
      this.$store.dispatch("addDespesa", total.toFixed(2));
      return total.toFixed(2);
    },
    toggleCategory(category) {
      category.open = !category.open; // Altera o estado de abertura/fechamento da categoria
    },
  },
};

</script>

<style lang="scss">
.home {
  display: flex;
  justify-content: center;
  align-items: flex-start;
  flex-wrap: wrap;
  padding-top: 50px;
  justify-content: flex-start;
  flex-direction: row;

  .categorias {
    display: flex;
    flex-wrap: wrap;
    border: 1px solid lightgrey;
    padding: 20px;
    max-width: 800px;
    min-width: 600px;
    flex-direction: row;
    align-content: space-around;
    justify-content: space-between;
  }


  .costs {
    flex-wrap: wrap;
    border: 1px solid lightgrey;
    padding: 20px;
    max-width: 800px;
    min-width: 400px;
    flex-direction: row;
    align-content: space-around;
    justify-content: space-between;


    h4 {
      text-align: center;
      margin-top: 0;
      width: 100%;
    }

    .cost {
      flex: 0 0 30%;
      box-sizing: border-box;
      box-shadow: 0 4px 8px 0 rgba(0, 0, 0, 0.2);
      padding: 16px;
      width: 100px;
      margin: 8px;
      height: 330px;

      .cost-image {
        margin: auto;
        width: 90%px;
        height: 100px;
        background-size: cover;
        background-position: center;
        background-repeat: no-repeat;
        box-shadow: 0 4px 8px 0 rgba(0, 0, 0, 0.2);
      }

      h4 {
        font-size: 15px;
        font-weight: bold;
        margin: 22px auto;

        max-width: 60%;
        font-weight: normal;
      }

      p.salaryPerHour {
        font-size: 15px;
        font-weight: bold;
      }

      input.hours {
        width: 40%;
        height: 30px;
        border: 1px solid #007bff;
        border-radius: 100px;
        padding: 0 16px;
        margin: 8px 0;
        box-sizing: border-box;
      }

    }

    .cost.selected {
      border: 5px solid rgb(185, 26, 26);
    }

    .hours-area {
      margin: 8px auto;
      height: 14px;
    }

    .hours-area button {
      border-radius: 5px;
      background-color: #aaaaaa;
      border: 1px solid #999999;
      width: 16px;
      height: 16px;
      display: inline-flex;
      justify-content: center;
      align-items: center;
      cursor: pointer;
      padding: 8px 8px;
    }

    .hours-area .quantity {
      font-weight: bold;
      margin: 0 4px;
    }
  }

  .summary {
    background-color: rgb(245, 245, 245);
    padding: 20px;
    min-width: 350px;
    text-align: left;

    table {
      width: 100%;
      padding-top: 12px;
      font-size: 15;
      margin: auto;

      tbody tr:last-of-type th {
        border-top: 1px solid black;
        padding-top: 4px;
      }
    }
  }

  .center {
    text-align: center;
  }
}
</style>
