import TiledImage from '@ftheriault/animatedsprite';
import { startGame } from '../page-chat';
export default class Bat {
    constructor() {
        
        if (window.innerWidth < 600) {
          
            return;
        }

        let colCount = 6;
        let rowCount = 3.1;
        let refreshDelay = 50;
        let loopColumns = true;
        let scale = 3.5;

		this.speedX = 5;
        this.health = 100;

		this.sideOfCharacterLeft = false;

        this.node = document.createElement("div");
        document.body.append(this.node);
        this.node.classList.add("bat");
		this.currentImage = this.idleImage;
   
        this.idleImage = new TiledImage(
            "../bat/idle.png",
            colCount,
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
        
		this.idleImage.changeRow(1);
        this.idleImage.changeMinMaxInterval(0, 6);
        this.currentImage = this.idleImage; 

        this.node.style.transform = 'scaleX(-1)';
        
        const largeurEcran = window.innerWidth;
        const hauteurEcran = window.innerHeight;
        
        
        const xAleatoire = Math.floor(Math.random() * largeurEcran);
        const yAleatoire = Math.floor(Math.random() * hauteurEcran);
        
        this.direction = Math.random() < 0.5 ? -1 : 1; // -1 pour x - 1, 1 pour x + 1

        this.x = xAleatoire;
        this.y = yAleatoire;

    }

    tick() {
        if (window.innerWidth < 600) {
           
            return false;
        }

    
        this.x += this.direction * this.speedX;

      
        const largeurEcran = window.innerWidth;
        if (this.x < 0) {
            this.x = 0;
            this.direction = 1; 
            this.node.style.transform = 'scaleX(-1)';
        } else if (this.x > largeurEcran) {
            this.x = largeurEcran;
            this.node.style.transform = 'scaleX(1)';
            this.direction = -1; 
        }
    
        
        
        this.currentImage.tick(this.x, this.y);

        return true;
    }
}
