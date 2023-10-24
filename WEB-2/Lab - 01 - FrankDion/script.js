

//function validate() {}

// type de fonction
const validate = () => {
    console.log(23432);
    let nom = document.querySelector("#nompinput").value;
    let motDepasse = document.querySelector("#mdpinput").value;

    let errors = [];
    
    if (nom != "franck"){
        errors.push("Nom invalide")
        
    }

    if (motDepasse != "dion"){
        errors.push("Mot de passe invalide")
    }

    

    if (errors.length > 0){
					
        let message = "Vous avez ces erreurs : ";
        errors.forEach(err => {
            message += "\n - " + err;
        } )
        alert(message);
    }

   

}

window.addEventListener("load", () => {
    const videoOnclick = document.querySelector("video");
    const bodyy = document.querySelector("#booody");
    const generic = document.querySelectorAll(".generic");

    videoOnclick.onplay = () => {
        bodyy.style.backgroundColor = "#555";
    };

    videoOnclick.onpause = () => {
        bodyy.style.backgroundColor = "white";
    };

    videoOnclick.onended = () => {
        window.location.href = "./generique.html";
    };
    let currentTop = 600;
    let direction = -1;

    
});
let currentTop = 600; // Initial top position
let direction = -1; // Initial direction (upward)

// Function to move the text
function moveGeneric() {
    const genericDiv = document.querySelector("#generic");

    // Toggle direction when the user clicks
    genericDiv.addEventListener("click", () => {
        direction *= -1;
    });

    // Move the text
    currentTop += direction; // Update the top position

    // Apply the new top position using CSS
    genericDiv.style.top = currentTop + "px";

    // Call moveGeneric() repeatedly every 30 milliseconds using setTimeout
    setTimeout(moveGeneric, 30);
}

// Wait for the page to load
window.addEventListener("load", () => {
    // Call moveGeneric() initially
    moveGeneric();


    videoOnclick.onplay = () => {
        bodyy.style.backgroundColor = "#555";
    };

    videoOnclick.onpause = () => {
        bodyy.style.backgroundColor = "white";
    };

    videoOnclick.onended = () => {
        window.location.href = "./generique.html";
    };

});
