let spriteList = [];

window.addEventListener("load", () => {
    
    let nombre = document.querySelector("#count-field");
    
    nombre.onkeyup = event => {

        if (event.key == "Enter"){
            for (let i = 0; i < nombre.value; i++) {
                spriteList.push(new Metroid());
            }
        }
    }

    tick();
});

const tick = () => {
    for (let i = 0; i < spriteList.length; i++) {
        const frame = spriteList[i];
        frame.tick();
    }
    window.requestAnimationFrame(tick);
};
