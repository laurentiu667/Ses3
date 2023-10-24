const validation = () => {
    const name = document.getElementById("name").value;
    const email = document.getElementById("email").value;

    const errorContainer = document.querySelector("errorContainer"); 

  
    errorContainer.innerHTML = ''; 
    console.log(3423);
    let errors = [];

    if (name.length >= 40) {
        errors.push("Votre nom est trop long, veuillez l'abréger.");
    }

    if (name.length < 2) {
        errors.push("Votre nom est trop court.");
    } else if (name.match(/^[!@#$%^&*()_+{}:"<>?|]*$/)) {
        errors.push("Votre nom contient des caractères non acceptés, par exemple : !@#$%^&*()_+{}:");
    }

    if (!email.includes("@")) {
        errors.push("Il se peut qu'il vous manque le caractère '@' ou que l'adresse email soit invalide.");
    }

    if (errors.length > 0) {
        let message = "Vous avez des erreurs";
        errors.forEach(err => {
            message += "<br/> - " + err; 
        });
        errorContainer.innerHTML = message; 
       
    }

};
