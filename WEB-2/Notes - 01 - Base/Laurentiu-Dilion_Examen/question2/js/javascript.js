const getRandomLetter = () => {
    let letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    let rnd = Math.random() * letters.length;

    return letters.substring(rnd, rnd + 1);
}
