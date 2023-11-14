import TiledImage from '@ftheriault/animatedsprite';
import { leftArrowOn, rightArrowOn, cKeyOn, vKeyon, downArrowOn, startGame } from '../page-chat.js';


export default class Knight {
    constructor() {
        
        if (window.innerWidth < 600) {
           
            return;
        }

        let colCount = 10;
		let colCountSlide = 4;
		let colCountCrouch = 3;
        let colCountJump = 3;
        let rowCount = 2;
        let rowCountJUmp = 2;
        let refreshDelay = 80;
		let refreshDelaySlide = 200;
		let refreshDelayCrouch = 100;
        let loopColumns = true;
        let scale = 4.0;
		this.speedX = 5;
        this.speedY = 5;
        this.health = 100;
		this.sideOfCharacterLeft = false;

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
		this.crouchALLImage = new TiledImage(
            "../knight/_CrouchAll.png",
            colCountCrouch,
            rowCount,
            refreshDelayCrouch,
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
		this.slideALLImage = new TiledImage(
            "../knight/_SlideAll.png",
            colCountSlide,
            rowCount,
            refreshDelaySlide,
            loopColumns,
            scale,
            this.node
        );
        this.jumpImage = new TiledImage(
            "../knight/_Jump.png",
            colCountJump,
            rowCountJUmp,
            refreshDelaySlide,
            loopColumns,
            scale,
            this.node
        );
		this.idleImage.changeRow(1);
		this.idleImage.changeMinMaxInterval(0, 10);

		this.runImage.changeRow(1);
		this.runImage.changeMinMaxInterval(0, 10);
		
		this.crouchALLImage.changeRow(1);
		this.crouchALLImage.changeMinMaxInterval(0, 3);

		this.attackImage.changeRow(1);
		this.attackImage.changeMinMaxInterval(0, 10);

		this.slideALLImage.changeRow(1);
		this.slideALLImage.changeMinMaxInterval(0, 4);
        this.jumpImage.changeRow(1);
        this.jumpImage.changeMinMaxInterval(0, 3);

        this.currentImage = this.idleImage; 

        this.x = 100;
        this.y = 967;
    }   

    tick() {
        if (startGame || window.innerWidth < 600) {

            return false;
        }
      
        if (rightArrowOn) {
            this.currentImage = this.runImage;
            this.node.style.transform = 'scaleX(1)';
            this.x += this.speedX;
			this.sideOfCharacterLeft = false;

        } 
		else if (leftArrowOn) {
            this.currentImage = this.runImage;
            this.node.style.transform = 'scaleX(-1)';
            this.x -= this.speedX;
			this.sideOfCharacterLeft = true;
        } 
		else if (cKeyOn) {
            this.currentImage = this.attackImage;

        } 
		else if (vKeyon) {
			this.currentImage = this.slideALLImage;
			if (this.sideOfCharacterLeft) {
				setTimeout(() => {
					for (let i = 0; i < 5; i++) {
						this.x -= i;
					}
				}, 1 );
				this.node.style.transform = 'scaleX(-1)';
			} else{
				setTimeout(() => {
					for (let i = 0; i < 5; i++) {
						this.x += i;
					}
				}, 1 );
				this.node.style.transform = 'scaleX(1)';
				this.sideOfCharacterLeft = false;
			}
		} else if (downArrowOn){
			this.currentImage = this.crouchALLImage;
		}
		else {
            this.currentImage = this.idleImage; 
        }

     
        this.currentImage.tick(this.x, this.y);

        return true;
    }
}
