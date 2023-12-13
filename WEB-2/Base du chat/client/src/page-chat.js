import { registerCallbacks, sendMessage, signout, chatMessageLoop } from './chat-api';
import Pepega from './sprite/Pepega.js';
import Maison from './sprite/Maison.js';
import Monster from './sprite/Monster.js';
import Decoration from './sprite/Decoration.js';
import Blob from './sprite/Chicken.js';
<<<<<<< HEAD
import Chicken from './sprite/Chicken.js';
=======


>>>>>>> 43cc736 (web234234)

export let qKeyon = false;
export let eKeyon = false;
export let aKeyOn = false;
export let dKeyOn = false;
export let sKeyon = false;
export let wKeyon = false;

const chicken = new Chicken();
const maison = new Maison()
const monster = new Monster(chicken, maison);
chicken.monster = monster

<<<<<<< HEAD
=======
blob.monster = monster

>>>>>>> 43cc736 (web234234)
export let messageUser = "";
let interval
let clicked = false;
let spriteList = [];
let membre_totaux = [];
let membresConnectes = [];  
let startGame_display = document.querySelector(".star-the-game");
let commencer_surprise = document.querySelector(".commencer-surprise");
let afficher_touche = document.querySelector(".button-afficher-touche");
let container_touche = document.querySelector(".container-touches");
let removeAll = document.querySelector(".stopper-surprise");

window.addEventListener("load", () => {

    document.querySelector("textarea").onkeyup = function (evt) {
        sendMessage(evt, this);
    };
    document.querySelector("#sign-out-btn").onclick = signout;
    registerCallbacks(newMessage, memberListUpdate);
    chatMessageLoop();
    
    startGame_display.addEventListener("click", start_game);
    
    
    function start_game() {
        spriteList.push(monster); 
        spriteList.push(new Maison());
        spriteList.push(new Decoration());
        spriteList.push(chicken)
          
        startGame_display.removeEventListener("click", start_game);
    }
    
    commencer_surprise.addEventListener("click", () => {
        if (!interval) {
            interval = setInterval(() => {
                spriteList.push(new Pepega());
            }, 100);
        }
    });
    
    removeAll.addEventListener("click", () => {
        clearInterval(interval);
        interval = null; 
    });
    
  
    afficher_touche.addEventListener("click", () =>{
        clicked = !clicked;
        if(clicked){
            container_touche.style.display = "flex";
        }
        else{
            container_touche.style.display = "none";
        }
    })
   
    tick();
});

const tick = () => {
    for (let i = 0; i < spriteList.length; i++) {
        const frame = spriteList[i];
        frame.tick();
    }

    window.requestAnimationFrame(tick);
};

// TOUCHE JOUEUR

document.addEventListener("keydown", (e) => {
    if (e.key === "w" || e.key === "W") {
        wKeyon = true;
    } else if (e.key === "a" || e.key === "A") {
        aKeyOn = true;
    } else if (e.key === "d" || e.key === "D") {
        dKeyOn = true;
    } else if (e.key === "q" || e.key === "Q") {
        qKeyon = true;
    } else if (e.key === "e" || e.key === "E") {
        eKeyon = true;
    } else if (e.key === "s" || e.key === "S") {
        sKeyon = true;
    }
});

document.addEventListener("keyup", (e) => {
    if (e.key === "w" || e.key === "W") {
        wKeyon = false;
    } else if (e.key === "a" || e.key === "A") {
        aKeyOn = false;
    } else if (e.key === "d" || e.key === "D") {
        dKeyOn = false;
    } else if (e.key === "q" || e.key === "Q") {
        qKeyon = false;
    } else if (e.key === "e" || e.key === "E") {
        eKeyon = false;
    } else if (e.key === "s" || e.key === "S") {
        sKeyon = false;
    }
});

<<<<<<< HEAD
// MESSAGE  

=======
>>>>>>> 43cc736 (web234234)
const newMessage = (fromUser, message, isPrivate) => {
    
    messageUser = message;
    let node = document.createElement("div");
    node.classList.add("msg");

<<<<<<< HEAD
    node.innerText = fromUser + ": " + message;
=======
    if (!message) {
        node.innerText = "<strong>" + fromUser + "</strong> a rejoint le chat";
    } else {
        node.innerText = "<strong>" + fromUser + ":</strong> " + message;
    }
>>>>>>> 43cc736 (web234234)

    let parentNode = document.querySelector(".afficher-message");
    parentNode.append(node);

    parentNode.scrollTop = parentNode.scrollHeight;

    document.querySelector("#message-input").value = "";
    
};

const memberListUpdate = (members) => {
    console.log("Membres en ligne: " + members);

    loadMembresTotaux();

    membresConnectes = members;

    console.log("Membres connectés après mise à jour:", membresConnectes);

    for (let i = 0; i < members.length; i++) {
        if (!membre_totaux.includes(members[i])) {
            membre_totaux.push(members[i]);
        }
    }

    saveMembresTotaux();

    console.log("Membres identifiés:", membre_totaux);

    checkLocalUsers();
};
const loadMembresTotaux = () => {
    const storedMembres = localStorage.getItem('membres_totaux');
    if (storedMembres) {
        membre_totaux = JSON.parse(storedMembres);
    }
};

const saveMembresTotaux = () => {
    localStorage.setItem('membres_totaux', JSON.stringify(membre_totaux));
};

const checkLocalUsers = () => {
   
    loadMembresTotaux();

    updateMembresTotauxHTML();
};

const updateMembresTotauxHTML = () => {
    
    let parentNode = document.querySelector("#membres_totaux");
    
<<<<<<< HEAD
    parentNode.innerHTML = "";
=======
    parentNode.innerText = "";

>>>>>>> 43cc736 (web234234)
   
    for (let i = 0; i < membre_totaux.length; i++) {
        
        let memberElement = document.createElement("div");

        
        const isOnline = membresConnectes.includes(membre_totaux[i]);

        
        if (isOnline) {
            memberElement.classList.add("membre-connecte");
        }
        else{
            memberElement.classList.add("membre-deconnecte");
        }

        memberElement.textContent = membre_totaux[i];

        parentNode.appendChild(memberElement);
    }

 
};

checkLocalUsers();