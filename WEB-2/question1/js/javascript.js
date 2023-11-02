// VARIABLE utilisteur et message
let nomUsager = "Toi : "
let nomFrederique = "Frédérique : ";
let message = "Sekiro c est meilleur que Elden Ring"

window.addEventListener("load", () =>{
    const input = document.querySelector("#input-field");
    
    input.onkeyup = event => {

        if (event.key == "Enter"){
            // Random à chaque rentré de la touche Enter
            let chance = Math.floor(Math.random() * 10) + 1
   
            // Entré des messages de l'utilisateur
            let node = document.createElement("div");
            node.classList.add("msg")
            let divNode = document.createTextNode(input.value);
            node.append(nomUsager + divNode.nodeValue);
            let parentNode = document.querySelector("#chat"); 
            parentNode.append(node);
            input.value = "";
            
            // Chance 3 sur 10 et message affiché une seconde après
            if (chance == 1 || chance == 2 || chance == 3){
                setTimeout(() => {
                    let node = document.createElement("div");
                    node.classList.add("msg")
                    let divNode = document.createTextNode(message);
                    node.append(nomFrederique + divNode.nodeValue);
                    let parentNode = document.querySelector("#chat"); 
                    parentNode.append(node);
                }, 1000);
    
            }
        }
    }
})