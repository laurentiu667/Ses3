import { signin } from './chat-api';
import Knight from './sprite/Knight';

export let leftArrowOn = false;
export let rightArrowOn = false;
export let cKeyOn = false
let spriteList = [];

window.addEventListener("load", () => {
    document.querySelector("form").onsubmit = function () {
        return signin(this);
    }
    spriteList.push(new Knight());
    tick();
});

const tick = () => {
    for (let i = 0; i < spriteList.length; i++) {
        let alive = spriteList[i].tick();

        if (!alive) {
            spriteList.splice(i, 1);
            i--;
        }
    }

    window.requestAnimationFrame(tick);
}


document.addEventListener("keydown", e => {
  
    if (e.key === "ArrowLeft") {
        leftArrowOn = true;
    } else if (e.key === "ArrowRight") {
        rightArrowOn = true;
    } else if (e.key === "c") {
        cKeyOn = true;

    }
});


document.addEventListener("keyup", e => {
   
    if (e.key === "ArrowLeft") {
        leftArrowOn = false;
    } else if (e.key === "ArrowRight") {
        rightArrowOn = false;
    } else if (e.key === "c") {
        cKeyOn = false;
        
    }

});