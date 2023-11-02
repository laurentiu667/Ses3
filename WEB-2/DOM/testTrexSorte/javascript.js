/*
let spriteList = [];
window.addEventListener("load", () =>{
    tick()
})

const tick = () => {

    spriteList.push(new Block())

    window.requestAnimationFrame(tick);
}*/ 

window.addEventListener("load", () => {
    let block = new Block(); // Créer un bloc directement sans déclarer de variable globale

    const tick = () => {
        block.tick();
        window.requestAnimationFrame(tick);
    };

    tick(); // Démarrer le tick immédiatement
});
