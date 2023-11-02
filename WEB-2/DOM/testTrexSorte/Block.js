class Block {
    constructor() {
        this.node = document.createElement("div");
        this.node.classList.add("block");
        this.x = 1100; // Commencer depuis la gauche (position 0)
        document.querySelector(".game").append(this.node);
        this.node.style.left = this.x + "px"; // Utiliser 'left' au lieu de 'right'
        this.speedX = 0.1;
        this.velocity = 0.01;
    }

    tick() {
        this.speedX += this.velocity;
        this.x -= this.speedX; // Pour aller vers la gauche, on soustrait la position
        if (this.x < 710){
            this.node.remove()
        }
        this.node.style.left = this.x + "px"; // Utiliser 'left' au lieu de 'right'
    }
}
