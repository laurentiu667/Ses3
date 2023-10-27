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
        this.randomY = -200;
        this.fruit.style.left = this.randomX + "px";
        this.fruit.style.bottom = this.randomY + "px"; 
        this.speed = 10;
        this.speedX = 1;
        this.velocityY = 0.5; // Acceleration (0.5 par tick)

        
    }

    tick() {
        let alive = true;
    
        this.speed += this.velocityY
        this.randomY += this.speed;

    
        if (this.randomY > 220){
            this.speed = -this.speed/1.5;
            this.randomY = 220;
        }
        
    
        this.fruit.style.bottom = this.randomY + "px";
        this.fruit.style.left = this.randomX + "px";
    
        this.fruit.addEventListener("mouseover", () => {
            setTimeout(() => {
                this.fruit.classList.add("sword-slash");
            }, 0);

            setTimeout(() => {
                
                this.fruit.classList.add(this.id + "-cut");
                
            }, 200);
        });
        
    
        return alive;
    }
    
}