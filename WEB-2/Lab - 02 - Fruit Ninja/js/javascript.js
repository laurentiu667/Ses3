// Variables
const FRUIT_COUNT = 6; // Number of fruits to create
let score = 0;
let lives = 3;
let gameOver = false;
let spriteList = [];

const fruct = ["../images/coconut.png", "../images/lemon.png", "../images/mango.png", "../images/orange.png", "../images/pineapple.png", "../images/watermelon.png"];


window.addEventListener("load", () => {

    let game = document.querySelector("#game");
    // Index du fruit
    var index = Math.floor(Math.random() * fruct.length) + 1;
    var imageFruit = fruct[index]
    console.log(imageFruit);

    let fruit = document.createElement("div");
    fruit.classList.add("fruit", "fruit_" + index );
    game.appendChild(fruit); 
    spriteList.push(new Fruit("fruit_" + index ));
    
    tick()
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
