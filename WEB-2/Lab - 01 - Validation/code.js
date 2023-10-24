const validate = () => {

    let firstName = document.getElementById("firstName").value;

    let lastName = document.getElementById("lastName").value;
    let password = document.getElementById("password").value;
    let errors = [];

    if (!firstName.match(/^[a-z\sA-Z]*$/) && !lastName.match(/^[a-z\sA-Z]*$/)){
        errors.push("Votre nom et prenom doivent contenir a - z et A - Z")
    }
    

    if ((lastName.length && firstName.length) > 19 ){
        errors.push("Le nom ou le prenom depasse 20 caractere")
        lastName.value = "";
        firstName.value = "";
    }
    
    if (password.length < 6){
        errors.push("Le mot de passe doit contenir plus de 6 caractere");
        password.value = "";
    }

    if (errors.length > 0){
					
        let message = "Vous avez des erreurs : ";
        errors.forEach(err => {
            message += "\n - " + err;
        } )
        alert(message);
    }
}

 
    

    
