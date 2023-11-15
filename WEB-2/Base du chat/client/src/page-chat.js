import { registerCallbacks, sendMessage, signout, chatMessageLoop } from './chat-api';
import Wizard from './sprite/Wizard.js';
import SecondWizard from './sprite/SecondWizard.js';

export let leftArrowOn = false;
export let rightArrowOn = false;
export let mKeyOn = false;
export let nKeyon = false;
export let qKeyon = false;
export let eKeyon = false;
export let aKeyOn = false;
export let dKeyOn = false;
export let downArrowOn = false;
export let upArrowOn = false;
export let sKeyon = false;

let clicked = false;
let spriteList = [];
let membre_totaux = [];
let membresConnectes = [];  // Ajout de la liste des membres connectés

let howToplay_Button = document.querySelector(".howToplay-Button");
let startGame_display = document.querySelector(".star-the-game");
let show_help = document.querySelector(".container-key");

window.addEventListener("load", () => {
    document.querySelector("textarea").onkeyup = function (evt) {
        sendMessage(evt, this);
    };
    document.querySelector("#sign-out-btn").onclick = signout;
    registerCallbacks(newMessage, memberListUpdate);
    chatMessageLoop();
   
    startGame_display.addEventListener("click", startGameHandler);

    function startGameHandler() {
        spriteList.push(new Wizard());
        spriteList.push(new SecondWizard());

        startGame_display.removeEventListener("click", startGameHandler);
    }

    tick();

    howToplay_Button.addEventListener("click", () => {
        clicked = !clicked;

        if (clicked) {
            show_help.style.opacity = "1";
            show_help.style.height = "100%";
        } else {
            show_help.style.opacity = "0";
            show_help.style.height = "0";
        }
    });
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
};

document.addEventListener("keydown", (e) => {
    if (e.key === "ArrowLeft") {
        leftArrowOn = true;
    } else if (e.key === "ArrowRight") {
        rightArrowOn = true;
    } else if (e.key === "ArrowDown") {
        downArrowOn = true;
    } else if (e.key === "ArrowUp") {
        upArrowOn = true;
    } else if (e.key === "n" || e.key === "N") {
        nKeyon = true;
    } else if (e.key === "m" || e.key === "M") {
        mKeyOn = true;
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
    if (e.key === "ArrowLeft") {
        leftArrowOn = false;
    } else if (e.key === "ArrowRight") {
        rightArrowOn = false;
    } else if (e.key === "ArrowDown") {
        downArrowOn = false;
    } else if (e.key === "ArrowUp") {
        upArrowOn = false;
    } else if (e.key === "n" || e.key === "N") {
        nKeyon = false;
    } else if (e.key === "m" || e.key === "M") {
        mKeyOn = false;
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

    parentNode.scrollTop = parentNode.scrollHeight;

    document.querySelector("#message-input").value = "";
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

const memberListUpdate = (members) => {
    console.log("Membre en ligne " + members);

    loadMembresTotaux();

    membresConnectes = members;  // Mettre à jour la liste des membres connectés

    for (let i = 0; i < members.length; i++) {
        if (!membre_totaux.includes(members[i])) {
            membre_totaux.push(members[i]);
        }
    }

    saveMembresTotaux();

    console.log("Membre identifier:", membre_totaux);

    // Appeler checkLocalUsers avec la liste des membres connectés
    checkLocalUsers(members);
};

// Fonction pour vérifier et faire quelque chose pour chaque utilisateur stocké localement
const checkLocalUsers = (connectedMembers) => {
    // Charger les membres totaux depuis le localStorage
    loadMembresTotaux();

    // Boucle pour chaque utilisateur stocké localement
    for (let i = 0; i < membre_totaux.length; i++) {
        const currentMember = membre_totaux[i];

        // Vérifier si l'utilisateur stocké localement est actuellement connecté
        const isOnline = connectedMembers.includes(currentMember);

        if (isOnline) {
            console.log(currentMember + " est actuellement connecté !");
            // Faire quelque chose ici avec l'utilisateur connecté
        } else {
            console.log(currentMember + " n'est pas actuellement connecté.");
            // Faire quelque chose ici avec l'utilisateur non connecté
        }
    }
    updateMembresTotauxHTML();
};

const updateMembresTotauxHTML = () => {
    // Sélectionner l'élément HTML avec la classe "membres_totaux"
    let parentNode = document.querySelector("#membres_totaux");

    // Effacer le contenu actuel de l'élément
    parentNode.innerHTML = "";

    // Boucle pour chaque membre
    for (let i = 0; i < membre_totaux.length; i++) {
        // Créer un élément div pour chaque membre
        let memberElement = document.createElement("div");

        // Vérifier si le membre est connecté
        const isOnline = membresConnectes.includes(membre_totaux[i]);

        // Ajouter une classe pour indiquer la connectivité
        if (isOnline) {
            memberElement.classList.add("membre-connecte");
        }
        else{
            memberElement.classList.add("membre-deconnecte");
        }

        memberElement.textContent = membre_totaux[i];

        // Ajouter l'élément à l'élément parent
        parentNode.appendChild(memberElement);
    }

    // Faire défiler vers le bas
    parentNode.scrollTop = parentNode.scrollHeight;
};

// Exemple d'utilisation
checkLocalUsers(membre_totaux);
