import TiledImage from '@ftheriault/animatedsprite';
import { aKeyOn, dKeyOn, qKeyon, eKeyon, sKeyon } from '../page-chat.js';


export default class Wizard {
    constructor() {
        
        if (window.innerWidth < 600) {
           
            return;
        }

        let colCount = [6, 8, 7, 4];
        let rowCount = 1;
        let refreshDelay = 50;
        let refreshDelayDeath = 120;
        let loopColumns = true;
        let scale = 1.5;
        this.death = false;
		this.speedX = 3;
        this.speedY = 5;
        this.health = 100;
		this.sideOfCharacterLeft = false;

        this.node = document.createElement("div");
        this.node.classList.add("wizzard")
        document.body.append(this.node);
		this.currentImage = this.idleImage;
   
        this.idleImage = new TiledImage(
            "../wizard/Idle.png",
            colCount[0],
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
        this.runImage = new TiledImage(
            "../wizard/Run.png",
            colCount[1],
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
        this.attackPrincipalImage = new TiledImage(
            "../wizard/Attack1.png",
            colCount[1],
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
        this.attackSecondaireImage = new TiledImage(
            "../wizard/Attack2.png",
            colCount[1],
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
        this.deathImage = new TiledImage(
            "../wizard/Death.png",
            colCount[2],
            rowCount,
            refreshDelayDeath,
            loopColumns,
            scale,
            this.node
        );
        this.hitImage = new TiledImage(
            "../wizard/Hit.png",
            colCount[3],
            rowCount,
            refreshDelayDeath,
            loopColumns,
            scale,
            this.node
        );
       
		this.idleImage.changeRow(0);
		this.idleImage.changeMinMaxInterval(0, colCount[0] - 1);
        this.runImage.changeRow(0);
        this.runImage.changeMinMaxInterval(0, colCount[1] - 1);
        this.attackPrincipalImage.changeRow(0);
        this.attackPrincipalImage.changeMinMaxInterval(0, colCount[1] - 1);
        this.attackPrincipalImage.changeRow(0);
        this.attackSecondaireImage.changeMinMaxInterval(0, colCount[1] - 1);
        this.deathImage.changeRow(0);
        this.deathImage.changeMinMaxInterval(0, colCount[2] - 1);
        this.hitImage.changeRow(0);
        this.hitImage.changeMinMaxInterval(0, colCount[3] - 1);

        this.currentImage = this.idleImage; 
      

        this.x = window.innerWidth - window.innerWidth + 150;
        this.y = window.innerHeight - 200;
    }   

    tick() {
        if (window.innerWidth < 600) {
            return false;
        }
    
        if (this.death) {
            this.currentImage = this.deathImage;
        } else if (qKeyon) {
            this.currentImage = this.attackPrincipalImage;
            this.currentImage.setLooped(false);
        } else if (aKeyOn) {
            this.currentImage = this.runImage;
            this.node.style.transform = 'scaleX(-1)';
            this.x -= this.speedX;
            this.sideOfCharacterLeft = false;
        } else if (dKeyOn) {
            this.currentImage = this.runImage;
            this.node.style.transform = 'scaleX(1)';
            this.x += this.speedX;
            this.sideOfCharacterLeft = true;
        } else if (eKeyon) {
            this.currentImage = this.attackSecondaireImage;
        } else if (false) {
            this.currentImage = this.deathImage;
            this.currentImage.setLooped(false);
        } else if (false) {
            this.currentImage = this.hitImage;
        } else {
            this.currentImage = this.idleImage;
        }
    
        this.currentImage.tick(this.x, this.y);
    
        return true;
    }
    
    
      
	
      
        

    
}
