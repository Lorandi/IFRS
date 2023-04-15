function getRandomImage() {
  const number = Math.floor(Math.random() * 1000);
  console.log(number);
  return `https://picsum.photos/id/${number}/400/600`;
}

function showLoadingIcon() {
  const loadingIcon = document.createElement("div");
  loadingIcon.classList.add("loading-icon");

  const spinner = document.createElement("div");
  spinner.classList.add("spinner");

  loadingIcon.appendChild(spinner);
  document.body.appendChild(loadingIcon);

  setTimeout(() => {
    loadingIcon.remove();
  }, 2000);
}

window.addEventListener("scroll", () => {
  if (window.innerHeight + window.scrollY >= document.body.offsetHeight) {
    showLoadingIcon();
    for (let i = 0; i < 5; i++) {
      const newImage = document.createElement("img");
      newImage.src = getRandomImage();
      document.body.appendChild(newImage);
      newImage.onerror = () => {
        console.log("Erro ao carregar imagem.");
        newImage.remove();
      };
    }
  }
});

for (let i = 0; i < 10; i++) {
  const newImage = document.createElement("img");
  showLoadingIcon();
  setTimeout(() => {
    newImage.src = getRandomImage();
  }, 1500);
  document.body.appendChild(newImage);
  newImage.onerror = () => {
    console.log("Erro ao carregar imagem.");
    newImage.remove();
  };
}
