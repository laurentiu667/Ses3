class Fruit {
    constructor(id) {
        this.id = id;
        this.fruit = document.querySelector("." + this.id);
        let game = document.getElementById('game').parentNode;
        this.gameWidth = game.offsetWidth;
        this.gameHeight = game.offsetHeight;
  
        this.velocityY = 0.09;
		this.speedY = -9;

		this.speedX = Math.random() * 5 - 2.5;

		this.x = Math.random() * 700 + 100;
		this.y = 500;

        this.xSword;
        this.ySword;

        this.fruit.addEventListener("mousemove", (banane) => {
            this.sliceFruit(banane);
        });
    }

    sliceFruit(banane) {
        this.fruit.classList.add(this.id + "-cut");
        this.xSword = banane.clientX; 
        this.ySword = banane.clientY;
        spriteList.push(new Sword(this.xSword, this.ySword))
    }

    tick() {
        this.speedY += this.velocityY;
        this.x += this.speedX;
        this.y += this.speedY;

        if (this.y >= this.gameHeight) {
            this.resetFruit(); // Réinitialiser le fruit si le fruit est tombé en bas
        }

        this.fruit.style.top = this.y + "px";
        this.fruit.style.left = this.x + "px";

        return this.alive;
    }

    resetFruit() {
        this.alive = false; // Marquer le fruit actuel comme éteint
        this.fruit.remove(); // Supprimer l'élément du fruit actuel

        // Créer un nouveau fruit
        let newFruit = document.createElement("div");
        newFruit.classList.add("fruit", this.id);
        game.appendChild(newFruit);

        this.id = "fruit_" + Math.floor(Math.random() * 1000); // Générer un nouvel ID unique
        this.fruit = newFruit;

        this.speedY = -9;
        this.speedX = Math.random() * 5 - 2.5;
        this.x = Math.random() * 700 + 100;
        this.y = 0; // Placer le nouveau fruit en haut de l'écran

        this.alive = true; // Marquer le nouveau fruit comme actif
    }
}
