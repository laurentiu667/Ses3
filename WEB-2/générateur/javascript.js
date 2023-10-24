const getRandomLetter = () => {
    let letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";
    let rnd = Math.random() * letters.length;
    return letters.substring(rnd, rnd + 1);
}
window.addEventListener("load", () => {
    const moins = document.querySelector(".minus");
    const plus = document.querySelector(".plus");
    const ajouter_total = document.querySelector(".ajouter_plus_moins");
    const confirmer_grid = document.querySelector(".button_conf");

    const wrapper_code = document.querySelector(".wrapper-code");
    const generer = document.querySelector(".generer");
    const reinitialiser = document.querySelector(".reinitialiser");
    const avant_wrapper_code = document.querySelector(".avant_wrapper_code");

    moins.addEventListener("click", () => {
        let currentValue = parseInt(ajouter_total.textContent);
        if (!isNaN(currentValue) && currentValue > 5) {
            ajouter_total.textContent = currentValue - 1;
        }
    });

    plus.addEventListener("click", () => {
        let currentValue = parseInt(ajouter_total.textContent);
        if (!isNaN(currentValue) && currentValue <= 9) {
            ajouter_total.textContent = currentValue + 1;
        }
    });

    confirmer_grid.addEventListener("click", () => {
        const ajouter_totalValue = parseInt(ajouter_total.textContent);
    
        if (ajouter_totalValue > 0) {
            console.log(234);
            for (let i = 0; i < ajouter_totalValue; i++) {
                const newDiv = document.createElement("div");
                newDiv.classList.add("carrer_char");
                newDiv.classList.add("carrer" + i);
                wrapper_code.appendChild(newDiv);
            }
            generer.style.display = "inline";
            confirmer_grid.style.display = "none";
            avant_wrapper_code.style.display = "none";
        }
       
    });
    
    const generateur = (ajouter_totalValue) => {
        for (let i = 0; i < ajouter_totalValue; i++) {
            let chiffre = getRandomLetter();
            const carrer = document.querySelector(".carrer" + i);
            carrer.textContent = chiffre;    
        }
    }
    
    generer.addEventListener('click', () => {
        const ajouter_totalValue = parseInt(ajouter_total.textContent); 
        for (let i = 1; i <= 100; i++) {
            console.log(i);
            setTimeout(() => {
                generateur(ajouter_totalValue); 
            }, 10 * i);
        }
        reinitialiser.style.display = "inline";

    });

    reinitialiser.addEventListener("click", () => {
        wrapper_code.textContent = "";
        ajouter_total.textContent = "5";
        generer.style.display = "none";
        confirmer_grid.style.display = "inline";
        reinitialiser.style.display = "none";
        avant_wrapper_code.style.display = "block";
      
    });
    
});
