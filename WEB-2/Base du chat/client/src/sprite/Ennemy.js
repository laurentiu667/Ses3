import TiledImage from '@ftheriault/animatedsprite';
import { aKeyOn, dKeyOn, qKeyon, eKeyon } from '../page-chat';

export default class Ennemy {
    constructor() {
        let colCount = 2.1;
        let rowCount = 4;
        let colCountAttack = 8;
        let rowCountAttack = 4.9;
        let refreshDelay = 200;
        let refreshDelayAttack = 100;
        let refreshDelayHealth = 100;
        let loopColumns = false;
        let loopColumnsAttack = true;
        let scale = 3.5;

		this.speedX = 5;
        this.health = 100;

		this.sideOfCharacterLeft = false;

        this.node = document.createElement("div");
        document.body.append(this.node);
        this.node.classList.add("ennemy");
		this.currentImage = this.idleImage;
   
        this.idleImage = new TiledImage(
            "../enemy/Idle.png",
            colCount,
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
        this.runImage = new TiledImage(
            "../enemy/Run.png",
            colCount,
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
        this.attackImage = new TiledImage(
            "../enemy/Attacks.png",
            colCountAttack,
            rowCountAttack,
            refreshDelayAttack,
            loopColumnsAttack,
            scale,
            this.node
        );
        this.healthImage = new TiledImage(
            "../enemy/Health.png",
            colCount,
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );

		this.idleImage.changeCol(1);
        this.runImage.changeCol(1);
        this.attackImage.changeRow(1);
        this.healthImage.changeCol(1);
        this.currentImage = this.idleImage; 

        this.node.style.transform = 'scaleX(-1)';
        
        this.x = window.innerWidth - 100;
        this.y = 875;

    }

    tick() {

        if (aKeyOn) {
            this.currentImage = this.runImage;
            this.node.style.transform = 'scaleX(-1)';
            this.x -= this.speedX;
			this.sideOfCharacterLeft = false;

        } 
		else if (dKeyOn) {
            this.currentImage = this.runImage;
            this.node.style.transform = 'scaleX(1)';
            this.x += this.speedX;
			this.sideOfCharacterLeft = true;
        } else if (qKeyon) {
            this.currentImage = this.attackImage;

        } else if (eKeyon) {
            this.currentImage = this.healthImage;

        } else {
            this.currentImage = this.idleImage; 
        }
      
        this.currentImage.tick(this.x, this.y);

        return true;
    }
}
