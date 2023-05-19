function myrequest(method, url) {
    return new Promise((resolve, reject) => {

        //instanciando o objeto XMLHttpRequest
        let xhr = new XMLHttpRequest();

        //Tratamento do retorno
        xhr.onreadystatechange = () => {
            if (xhr.readyState == 4 && xhr.status == 200) {
                resolve(JSON.parse(xhr.responseText));
            } else {
                console.log(xhr.statusText)
            }
        }

        //tratamento de erro
        xhr.onerror = () => reject(xhr.statusText);


        //configurando a requisição
        xhr.open(method, url, true);

        //enviando a requisição
        xhr.send();

    });

    async function main() {
        try {
            let objJson = await myrequest('GET', 'images.json');
            console.log(objJson[1].alt);
        } catch (error) {
            console.log(error);
        }
    }
}