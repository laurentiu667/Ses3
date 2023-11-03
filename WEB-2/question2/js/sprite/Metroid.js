class Metroid{
    constructor(id){
        
        // Création des objets
        this.id = id;
        this.node = document.querySelector("#" + this.id);
        this.noeud = document.createElement("div");
        this.noeud.classList.add("metroid");
        this.pause = document.querySelector(".btn-container")
        document.body.append(this.noeud);
        // Largeur et hauteur du windows
        const minX = 0;
        const maxX = window.innerWidth;
        const minY = 0;
        const maxY = window.innerHeight;
        // Random 
        this.X = Math.floor(Math.random() * (maxX - minX + 1)) + minX;
        this.Y = Math.floor(Math.random() * (maxY - minY + 1)) + minY;
        this.chance = Math.floor(Math.random() * 4) + 1;
        // Speed
        this.speed =1;
        // Button Pause
        this.pause = document.querySelector("btn-container")
        
        if ( this.chance == 1){
            this.noeud.style.top = this.Y + "px"; 
            this.noeud.style.left = this.X + "px"; 
        }else if ( this.chance == 2){
            this.noeud.style.left = this.Y + "px"; 
            this.noeud.style.bottom = this.X + "px"; 
        }else if ( this.chance == 3){
            this.noeud.style.right = this.Y + "px"; 
            this.noeud.style.bottom = this.X + "px"; 
        }else if ( this.chance == 4){
            this.noeud.style.bottom = this.Y + "px"; 
            this.noeud.style.left = this.X + "px"; 
        } 

    }

    tick(){

        if ( this.chance == 1){
            this.Y -= this.speed;
            this.noeud.style.top = this.Y + "px"; 
        }else if ( this.chance == 2){
            this.Y -= this.speed;
            this.noeud.style.left = this.Y + "px"; 
        }else if ( this.chance == 3){
            this.Y -= this.speed;
            this.noeud.style.right = this.Y + "px"; 
        }else if ( this.chance == 4){
            this.Y -= this.speed;
            this.noeud.style.bottom = this.Y + "px"; 
        } 

    }
}


// Méthode qui n est moins repetitive

/*
class Metroid {
    constructor(id) {
        this.id = id;
        this.noeud = document.createElement("div");
        this.noeud.classList.add("metroid");
        document.body.append(this.noeud);

        const minX = 0;
        const maxX = window.innerWidth;
        const minY = 0;
        const maxY = window.innerHeight;

        this.X = Math.floor(Math.random() * (maxX - minX + 1)) + minX;
        this.Y = Math.floor(Math.random() * (maxY - minY + 1)) + minY;
        this.speed = 1;
        this.chance = Math.floor(Math.random() * 4) + 1;

        this.setPosition();

        // Set the movement direction based on 'chance'
        switch (this.chance) {
            case 1:
                this.direction = 'top';
                break;
            case 2:
                this.direction = 'left';
                break;
            case 3:
                this.direction = 'right';
                break;
            case 4:
                this.direction = 'bottom';
                break;
            default:
                this.direction = 'top';
        }
    }

    setPosition() {
        if (this.chance === 1) {
            this.noeud.style.top = this.Y + "px";
            this.noeud.style.left = this.X + "px";
        } else if (this.chance === 2) {
            this.noeud.style.left = this.Y + "px";
            this.noeud.style.bottom = this.X + "px";
        } else if (this.chance === 3) {
            this.noeud.style.right = this.Y + "px";
            this.noeud.style.bottom = this.X + "px";
        } else if (this.chance === 4) {
            this.noeud.style.bottom = this.Y + "px";
            this.noeud.style.left = this.X + "px";
        }
    }

    tick() {
        this.moveMetroid();
    }

    moveMetroid() {
        this.Y -= this.speed;
        this.noeud.style[this.direction] = this.Y + "px";
    }
}

*/