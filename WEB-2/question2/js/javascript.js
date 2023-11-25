
let spriteList = [];
let pause = false;
let togglePause = () =>{
    pause = !pause;
}
window.addEventListener("load", () => {
    
    let nombre = document.querySelector("#count-field");
    document.querySelector('.btn-container button').addEventListener('click', () => {
        togglePause();
    });
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
    if (!pause) {
        for (let i = 0; i < spriteList.length; i++) {
            const frame = spriteList[i];
            frame.tick();
        }
    }
    window.requestAnimationFrame(tick);
};
