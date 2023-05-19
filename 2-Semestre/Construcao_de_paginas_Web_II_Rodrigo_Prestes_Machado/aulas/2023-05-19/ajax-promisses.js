function myrequest(method, url) {
    return new Promise((resolve, reject) => {

        //instanciando o objeto XMLHttpRequest
        let xhr = new XMLHttpRequest();

        //Tratamento do retorno
        xhr.onreadystatechange = () => {
            if (xhr.readyState == 4 && xhr.status == 200) {
                resolve(JSON.parse(xhr.responseText));
            } 
        }

        //tratamento de erro
        xhr.onerror = () => reject(xhr.statusText);

        //configurando a requisição
        xhr.open(method, url, true);

        //enviando a requisição
        xhr.send();

    });
}
 
async function main() {
    try {
        let images = await myrequest('GET', 'images.json');
        console.log(images);
        var divImages =document.getElementById('images');
        images = shuffle(images);

        for(const image of images){
            let img = document.createElement('img');
            img.src = image.imagemUrl;
            divImages.appendChild(img);
        }
    } catch (error) {
        console.log(error);
    }
}

function shuffle(array) {
    for (let i = array.length - 1; i > 0; i--) {
        let j = Math.floor(Math.random() * ( i + 1));
        [array[i], array[j]] = [array[j], array[i]];
    } 
    return array;  
}

window.onscroll = function(ev) {
    if ((window.innerHeight + window.scrollY) >= document.body.offsetHeight) {
        main();
    }
}
