import TiledImage from '@ftheriault/animatedsprite';
import { leftArrowOn, rightArrowOn, cKeyOn } from '../page-index';

export default class Knight {
    constructor() {
        let colCount = 10;
		let colCountAttack = 6;
        let rowCount = 2;
        let refreshDelay = 80;
		let refreshDelayAttack = 100;
        let loopColumns = true;
        let scale = 4.0;
		this.speedX = 4;

        this.node = document.createElement("div");
        document.body.append(this.node);
        this.node.classList.add("knight");
		this.currentImage = this.idleImage;
   
        this.idleImage = new TiledImage(
            "../knight/_Idle.png",
            colCount,
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );

        this.runImage = new TiledImage(
            "../knight/_Run.png",
            colCount,
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
		this.attackImage = new TiledImage(
            "../knight/_AttackComboNoMovement.png",
            colCount,
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
		this.idleImage.changeRow(1);
		this.idleImage.changeMinMaxInterval(0, 10);

		this.runImage.changeRow(1);
		this.runImage.changeMinMaxInterval(0, 10);

		this.attackImage.changeRow(1);
		this.attackImage.changeMinMaxInterval(0, 10);

        this.currentImage = this.idleImage; 

        this.x = 80;
        this.y = 940;
    }

    tick() {
      
        if (rightArrowOn) {
            this.currentImage = this.runImage;
            this.node.style.transform = 'scaleX(1)';
            this.x += this.speedX;

        } else if (leftArrowOn) {
            this.currentImage = this.runImage;
            this.node.style.transform = 'scaleX(-1)';
            this.x -= this.speedX;

        } else if (cKeyOn) {
            this.currentImage = this.attackImage;

        }else {
            this.currentImage = this.idleImage; 
        }

     
        this.currentImage.tick(this.x, this.y);

        return true;
    }
}
