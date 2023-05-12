function asc(value) {
    return new Promise((resolve, reject) => {
        if(value){
            resolve("Promise resolvida com sucesso")
        } else {
            reject("Promise rejeitada")
        }       
    });
}

function load(){

    var x = asc(false);

    x.then((res) => {console.log(res)})
    .catch((err) => {console.log(err)});
}
