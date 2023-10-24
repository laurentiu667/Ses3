const getRandomLetter = () => {
    let letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";
    let rnd = Math.random() * letters.length;
    return letters.substring(rnd, rnd + 1);
}
window.addEventListener('load', () => {
    const button_click = document.querySelector(".btn-start");
    const generateur = () => {
        for (let i = 1; i <= 8; i++) {
            let chiffre = getRandomLetter();
            const carrer = document.querySelector("#c" + i);
            carrer.value = chiffre;    
        }
    }
    button_click.addEventListener('click', () => {
        for (let i = 1; i <= 20; i++) {
            console.log(i);
            setTimeout(() => {
                generateur();
            }, 50 * i);
        }
    });
})