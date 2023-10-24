window.addEventListener("load", () =>{

    const input = document.querySelector("#memo-input");


    input.onkeyup = event => {

        if (event.key == "Enter"){

            let node = document.createElement("div");

            let divNode = document.createTextNode(input.value);
            node.append(divNode);

            let parentNode = document.querySelector("#memo-list"); // ul ou #liste
            parentNode.append(node);

            input.value = "";

            node.onclick = () => node.remove();
        }
    }
    
    /*
    inputNode.onkeyup = event => {
        // lorsque une touche est relacher
        if (event.key == "Enter"){
            // si oui alors creer un new div
            // l ajouter a son parent

            // creer un noeud
            let node = document.createElement("div");
            // mettre la valeur du champ texte
            node.innerText = inputNode.value;
            // ajouter a la page
            let parentNode = document.querySelector("#memo-list")
            parentNode.append(node);

            inputNode.value = "";

            // sur le new noeud cliquer alors remove
            node.onclick = () => node.remove();
        }
    }
    */ 
    
   

})