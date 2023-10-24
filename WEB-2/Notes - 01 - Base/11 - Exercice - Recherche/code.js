const validate = () => {


    let cityNode = document.getElementById("searchBox");
    let cityValue = cityNode.value;
    // regrouper toutes les erreures faite dans le input du clien
    let errors = []
    // si le string enter est moisn que deux char
    if (cityValue.length == 0 ){
        errors.push("Il n y a rien cousin, rentre quelques chose")
    }

    if (cityValue == "Mots clés") {
        errors.push("Rentre quelques chose d autre que Mots clés");
        
    }
    // si c est a 0 est plus donc >=

    // if (cityValue.match(/^[a-z\sA-Z]*$/))
    /*if (cityValue.indexOf("1") >= 0 ) {
        
        errors.push("La ville ne doit pas contenir de 1")
    }*/

    if (errors.length > 0){
        
        let message = "Vous avez des erreurs : ";
        errors.forEach(err => {
            message += "\n - " + err;
        } )

        cityNode.value = "";
        alert(message);
    }
    //si le champ est invalide
    // success

    // si il n y a pas de erreur bah c a fait true et s il y en c  est  false
    return errors.length == 0;
}