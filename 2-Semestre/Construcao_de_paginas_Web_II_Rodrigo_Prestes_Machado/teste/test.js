let x = 1;

function load(){
     x++;
    document.write(x);
    execute();
    x++;
}

function execute(){
    let y = 10;
    document.write(y);
    console.log("Hello World");
}