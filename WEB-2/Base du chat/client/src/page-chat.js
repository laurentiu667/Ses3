import {registerCallbacks, sendMessage, signout, chatMessageLoop} from './chat-api';
import Knight from './sprite/Knight.js';

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
    document.querySelector("textarea").onkeyup = function (evt) {
        sendMessage(evt, this)
    };
    document.querySelector("#sign-out-btn").onclick = signout;
    registerCallbacks(newMessage, memberListUpdate);
    chatMessageLoop();

    spriteList.push(new Knight());
    tick();

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
    
})


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

// Lorsqu'un nouveau message doit être affiché à l'écran, cette fonction est appelée
// QUand un nouveau utilisateur rentre dans le chat son message d arriver est poster
// et c est aussi utiliser pour quand il met le message 
const newMessage = (fromUser, message, isPrivate) => {
    let node = document.createElement("div");
    node.classList.add("msg");

    if (!message) {
        node.innerHTML = "<strong>" + fromUser + "</strong> a rejoint le chat";
    } else {
        node.innerHTML = "<strong>" + fromUser + ":</strong> " + message;
    }

    let parentNode = document.querySelector("#chat-container");
    parentNode.append(node);

    // Pour scroller quand il y a bcp de message
    parentNode.scrollTop = parentNode.scrollHeight;

    document.querySelector("#message-input").value = "";
};
// À chaque 2-3 secondes, cette fonction est appelée. Il faudra donc mettre à jour la liste des membres
// connectés dans votre interface.
const memberListUpdate = members => {
    console.log(members);
}

