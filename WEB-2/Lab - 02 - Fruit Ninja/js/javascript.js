// Variables
const FRUIT_COUNT = 6; // Number of fruits to create
let score = 0;
let lives = 3;
let gameOver = false;
let spriteList = [];

const fruct = ["../images/coconut.png", "../images/lemon.png", "../images/mango.png", "../images/orange.png", "../images/pineapple.png", "../images/watermelon.png"];
const cut_fruct = ["../images/coconut-cut.png", "../images/lemon-cut.png", "../images/mango-cut.png", "../images/orange-cut.png", "../images/pineapple-cut.png", "../images/watermelon-cut.png"];
const sword_slash = "../images/sword-slash.png";

window.addEventListener("load", () => {
    let game = document.querySelector("#game");
    let fruitIndex = 1;

    delaiDesFruits = () => {
        if (fruitIndex <= FRUIT_COUNT) {
            let fruit = document.createElement("div");
            fruit.classList.add("fruit", "fruit_" + fruitIndex);
            game.appendChild(fruit); 
            spriteList.push(new Fruit("fruit_" + fruitIndex));
            fruitIndex++;

            setTimeout(delaiDesFruits, 100); 
        }
    }

    delaiDesFruits(); 
    tick();
});

const tick = () => {
    for (let i = 0; i < spriteList.length; i++) {
        const fruit = spriteList[i];
        fruit.tick();
        let alive = fruit.tick();
        if (!alive) {
            spriteList.splice(i, 1);
            i--;
        }
    }
    
    requestAnimationFrame(tick);
};
