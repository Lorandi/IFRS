function promocao() {
  var dots = document.getElementById("dots");
  var moreText = document.getElementById("more");
  var btnText = document.getElementById("myBtn");


  if (dots.style.display === "none") {
    dots.style.display = "inline";
    btnText.innerHTML = "Abrir"; 
    moreText.style.display = "none";
  } else {
    dots.style.display = "none";
    btnText.innerHTML = "Fechar"; 
    moreText.style.display = "inline";
  }
}

function totaliza(valorzin){
    quantidade = document.getElementById("quantidade");
    quantidadeT = parseFloat(quantidade.value);
    valor.value = (valorzin * quantidadeT).toFixed(2);
}


function openModal(mn){
  let modal = document.getElementById(mn);

  if (typeof modal == 'undefined' || modal === null)
    return;

  modal.style.display = 'Block'  
}

function closeModal(mn) {
   let modal = document.getElementById(mn);

  if (typeof modal == 'undefined' || modal === null)
    return;

  modal.style.display = 'none'    
}

function openCloseModal(m1, m2) {
   let modal1 = document.getElementById(m1);
   let modal2 = document.getElementById(m2);

  if (typeof modal1 == 'undefined' || modal1 === null)
    return;

  if (typeof modal2 == 'undefined' || modal2 === null)
    return;

  modal1.style.display = 'none'
  modal2.style.display = 'Block'
}

function menu(x) {
  x.classList.toggle("change");
  var y = document.getElementById("myLinks");
  if (y.style.display === "block") {
    y.style.display = "none";
  } else {
    y.style.display = "block";
  }
}




