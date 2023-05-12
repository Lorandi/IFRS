async function asc(value) {
    return new Promise((resolve, reject) => {
        if(value){
            resolve("Promise resolvida com sucesso")
        } else {
            reject("Promise rejeitada")
        }       
    });
}

//chamada da promise
//  function load(){

//     var x = asc(false);

//     x.then((res) => {console.log(res)})
//     .catch((err) => {console.log(err)});
// }

//chamada da promise com async/await
async function load(){
    try{
        var res = await asc(true);
        console.log(res);
    }catch(err){
        console.log(err);
    }
}

