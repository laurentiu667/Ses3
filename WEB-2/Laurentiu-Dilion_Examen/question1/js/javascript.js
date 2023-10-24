const validate = () => {
    const div_reussi = document.querySelector(".msg-ok");
    const div_echouer = document.querySelector(".msg-err");
    const inscription = document.querySelector("#typeInscription").value;
    const nombre_inscription = document.querySelector("#nbInscription").value;
    if (inscription == "individuel" || inscription == "ind"){
        if (nombre_inscription <= 5){
            div_reussi.style.display = "block";
            div_echouer.style.display = "none";
        } 
        else {
            div_echouer.style.display = "block";
            div_reussi.style.display = "none";
        }
    }
    if (inscription == "groupe"){
        if (nombre_inscription >= 10){
            div_reussi.style.display = "block";
            div_echouer.style.display = "none";
        }
        else {
            div_echouer.style.display = "block";
            div_reussi.style.display = "none";
        }
    } 
    return false;
}