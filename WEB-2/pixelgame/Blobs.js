class Frame {
    constructor(id) {
        this.id = id;
        this.node = document.querySelectorAll("." + this.id);
        this.blobSize = 50;
        this.screenWidth = window.innerWidth - this.blobSize;
        this.screenHeight = window.innerHeight - this.blobSize;

        // Position et vitesse initiale aléatoires
        this.node.forEach(node => {
            const randomX = Math.random() * (this.screenWidth - this.blobSize - 140); // -100 pour laisser un espace de 100px
            const randomY = Math.random() * (this.screenHeight - this.blobSize - 140); // -100 pour laisser un espace de 100px
            node.style.left = randomX + "px";
            node.style.top = randomY + "px";
            node.speedX = 0.1; // Vitesse horizontale
            node.speedY =0.1; // Vitesse verticale
        });
    }

    tick() {
        
        
    }
}
