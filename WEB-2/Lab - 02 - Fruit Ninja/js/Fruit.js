class Fruit {
    constructor(id) {
        this.id = id;
        this.fruit = document.querySelector("." + this.id);
        this.speed = 1;
        this.velocity = 1;
        this.gravity = 0.009;

        let game = document.getElementById('game').parentNode;
        this.gameWidth = game.offsetWidth;
        this.gameHeight = game.offsetHeight;

        this.randomX = Math.floor(Math.random() * (this.gameWidth - 100));
        this.randomY = Math.floor(Math.random() * (300) - 500);
        this.fruit.style.left = this.randomX + "px";
        this.fruit.style.bottom = this.randomY + "px"; 
    }

    tick() {
        let alive = true;
        this.randomY += this.velocity;
        this.velocity += this.gravity;
    
        if (this.randomY >= this.gameHeight / 3) {
            this.velocity *= -0.6;
        }
       
        this.fruit.style.bottom = this.randomY + "px";

        this.fruit.addEventListener("mouseover", () => {
         
            this.fruit.style.backgroundImage = "url('images/sword-slash.png')";
    
            setTimeout(() => {
                this.fruit.style.backgroundImage = "none"; 
                this.fruit.remove();
            }, 100);
        });
        
        return alive;

    }

    
    
}
