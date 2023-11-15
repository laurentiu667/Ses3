import TiledImage from '@ftheriault/animatedsprite';
import { upArrowOn, downArrowOn, leftArrowOn, rightArrowOn, nKeyon, mKeyOn } from '../page-chat';
export default class SecondWizard {
    constructor() {
        if (window.innerWidth < 600) {
            
            return;
        }
        let colCount = [8, 7, 3];
        let rowCount = 1;
        let refreshDelay = 50;
        let refreshDelayDeath = 120;
        let loopColumns = true;
        let scale = 4;

		this.speedX = 5;
        this.health = 100;

		this.sideOfCharacterLeft = false;

        this.node = document.createElement("div");
        document.body.append(this.node);
		this.currentImage = this.idleImage;
   
        this.idleImage = new TiledImage(
            "../second-wizard/Idle.png",
            colCount[0],
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
        this.runImage = new TiledImage(
            "../second-wizard/Run.png",
            colCount[0],
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
        this.attackPrincipalImage = new TiledImage(
            "../second-wizard/Attack1.png",
            colCount[0],
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
        this.attackSecondaireImage = new TiledImage(
            "../second-wizard/Attack2.png",
            colCount[0],
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
        this.deathImage = new TiledImage(
            "../second-wizard/Death.png",
            colCount[1],
            rowCount,
            refreshDelayDeath,
            loopColumns,
            scale,
            this.node
        );
        this.hitImage = new TiledImage(
            "../second-wizard/Hit.png",
            colCount[2],
            rowCount,
            refreshDelayDeath,
            loopColumns,
            scale,
            this.node
        );
      

		this.idleImage.changeRow(0);
		this.idleImage.changeMinMaxInterval(0, colCount[0] - 1);
        this.runImage.changeRow(0);
        this.runImage.changeMinMaxInterval(0, colCount[0] - 1);
        this.attackPrincipalImage.changeRow(0);
        this.attackPrincipalImage.changeMinMaxInterval(0, colCount[0] - 1);
        this.attackPrincipalImage.changeRow(0);
        this.attackSecondaireImage.changeMinMaxInterval(0, colCount[0] - 1);
        this.deathImage.changeRow(0);
        this.deathImage.changeMinMaxInterval(0, colCount[1] - 1);
        this.hitImage.changeRow(0);
        this.hitImage.changeMinMaxInterval(0, colCount[2] - 1);
        
        this.currentImage = this.idleImage; 

        this.node.style.transform = 'scaleX(-1)';
       
        this.x = 1000;
        this.y = 690;

    }

    tick() {
        
        if (window.innerWidth < 600) {
            return false;
        }

        if (leftArrowOn) {
            this.currentImage = this.runImage;
            this.node.style.transform = 'scaleX(-1)';
            this.x -= this.speedX;
			this.sideOfCharacterLeft = false;

        } 
		else if (rightArrowOn) {
            this.currentImage = this.runImage;
            this.node.style.transform = 'scaleX(1)';
            this.x += this.speedX;
			this.sideOfCharacterLeft = true;
        } 
        else if (nKeyon) {
            this.currentImage = this.attackPrincipalImage;

        } 
        else if (mKeyOn) {
            this.currentImage = this.attackSecondaireImage;

        } 
        else if (downArrowOn) {
          
            this.currentImage = this.deathImage;
    
        } 
        else if (upArrowOn) {
         
            this.currentImage = this.hitImage;
        } 
        else {
            this.currentImage = this.idleImage; 
        }
      
        this.currentImage.tick(this.x, this.y);

        return true;
    }
}
