import { signin } from './chat-api';
import Knight from './sprite/Knight';

export let leftArrowOn = false;
export let rightArrowOn = false;
export let cKeyOn = false
export let vKeyon = false
export let downArrowOn = false
let clicked = false;
let spriteList = [];


let howToplay_Button = document.querySelector(".howToplay-Button")
let show_help = document.querySelector(".container-key")


window.addEventListener("load", () => {
    document.querySelector("form").onsubmit = function () {
        return signin(this);
    }
    spriteList.push(new Knight());
    tick();
    
});

howToplay_Button.addEventListener("click", () => {
    clicked = !clicked; // Toggle the value of 'clicked' variable

    if (clicked) {
        show_help.style.opacity = "1";
        show_help.style.height = "100%"; 
    } else {
        show_help.style.opacity = "0";
        show_help.style.height = "0";
    }
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
    } else if (e.key === "ArrowDown") {
        downArrowOn = true;
    } else if (e.key === "c" || e.key === "C") {
        cKeyOn = true;
    } else if (e.key === "v" || e.key === "V") {
        vKeyon = true;
    }
});

document.addEventListener("keyup", e => {
    if (e.key === "ArrowLeft") {
        leftArrowOn = false;
    } else if (e.key === "ArrowRight") {
        rightArrowOn = false;
    } else if (e.key === "ArrowDown") {
        downArrowOn = false;
    } else if (e.key === "c" || e.key === "C") {
        cKeyOn = false;
    } else if (e.key === "v" || e.key === "V") {
        vKeyon = false;
    }
});
