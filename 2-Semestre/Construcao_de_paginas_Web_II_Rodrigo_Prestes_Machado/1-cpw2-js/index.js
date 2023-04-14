/**
 * Recebe um array com os nomes de pessoas e retorna um array invertido
 *
 * @param {*} people : Um array contendo um conjunto de nomes
 * @returns Um array com os nomes invertidos
 */
function invert(people) {
  let nomesInvertidos = [];
  for (let i = people.length - 1; i >= 0; i--) {
    nomesInvertidos.push(people[i]);
  }

//   for (let i = 0; i < nomesInvertidos.length; i++) {
//     console.log(nomesInvertidos[i]);
//     console.log(people[i]);
//   }
  console.log(nomesInvertidos);
  console.log(people);

  return nomesInvertidos;
}

/**
 * Essa função recebe um array de notas e retorna uma média
 *
 * @param {*} grades : Um array de notas
 * @returns Uma média a partir do array de notas
 */
function mean(grades) {
  let total = 0;
  for (let i = 0; i < grades.length; i++) {
    total += grades[i];
  }
  return total / grades.length;
}

/**
 * Função recebe uma média e informa textualmente se um estudante está aprovado ou não
 *
 * @param {*} mean : Um número que representa uma média
 * @returns Uma string dizendo se um estudante está aprovado ou não
 */
function isApproved(mean) {
  if (mean >= 7) {
    return "aprovado";
  } else {
    return "reprovado";
  }
}

/**
 * Recebe uma data no formato de string e transforma em um formato textual
 *
 * @param {*} strDate : Uma string no formato de data
 * @returns Uma descrição da data informada
 */
function wide(strDate) {
  if (strDate === "") {
    return "";
  }

  let mesPorExtenso;
  strDate = strDate.split("/");
  let dia = strDate[0];
  let mes = strDate[1];
  let ano = strDate[2];

  if (isNaN(dia) || isNaN(mes) || isNaN(ano)) {
    return "";
  } else {
    let diaNumerico = parseInt(dia);
    let mesNumerico = parseInt(mes);
    let anoNumerico = parseInt(ano);
    if (
        diaNumerico < 1 ||
        diaNumerico > 31 ||
        mesNumerico < 1 ||
        mesNumerico > 12 ||
        anoNumerico < 0
    ) {
      return "";
    }
  }

  switch (mes) {
    case "01":
      mesPorExtenso = "janeiro";
      break;

    case "02":
      mesPorExtenso = "fevereiro";
      break;

    case "03":
      mesPorExtenso = "março";
      break;

    case "04":
      mesPorExtenso = "abril";
      break;

    case "05":
      mesPorExtenso = "maio";
      break;

    case "06":
      mesPorExtenso = "junho";
      break;

    case "07":
      mesPorExtenso = "julho";
      break;

    case "08":
      mesPorExtenso = "agosto";
      break;

    case "09":
      mesPorExtenso = "setembro";
      break;

    case "10":
      mesPorExtenso = "outubro";
      break;

    case "11":
      mesPorExtenso = "novembro";
      break;

    case "12":
      mesPorExtenso = "dezembro";
      break;

    default:
      mesPorExtenso = mes;
      break;
  }

  let data = dia + " de " + mesPorExtenso + " de " + ano;
  return data;
}

invert(["Pedro", "Maria", "Trevis", "John", "Heitor", "Camila"]);

// Trecho utilizado pelos testes
exports._test = {
  invert: invert,
  mean: mean,
  isApproved: isApproved,
  wide: wide,
};
