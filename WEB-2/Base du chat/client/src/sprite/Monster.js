import TiledImage from '@ftheriault/animatedsprite';
import { wKeyon, sKeyon, aKeyOn, dKeyOn, qKeyon, eKeyon } from '../page-chat';

export default class Monster {
    constructor() {
        let colCount = [4, 6, 8];
        let rowCount = 1;
        let refreshDelay = 100;
        let loopColumns = true;
        let scale = 2.5;

        this.speedX = 2.6;
        this.speedY = 1;
        this.health = 100;
        this.gravity = 0.5;
        this.jumpForce = -10;
        this.velocityY = 0;
        this.node = document.createElement("div");
        document.body.append(this.node);
        this.node.style.zIndex = 100;

        this.idleImage = new TiledImage(
            "../monster/Dude_Monster_Idle_4.png",
            colCount[0],
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
        this.RunImage = new TiledImage(
            "../monster/Dude_Monster_Run_6.png",
            colCount[1],
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
        this.JumpImage = new TiledImage(
            "../monster/Dude_Monster_Jump_8.png",
            colCount[2],
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
        this.PushImage = new TiledImage(
            "../monster/Dude_Monster_Push_6.png",
            colCount[1],
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
        this.AttackImage = new TiledImage(
            "../monster/Dude_Monster_Attack2_6.png",
            colCount[1],
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );

        this.idleImage.changeRow(0);
        this.idleImage.changeMinMaxInterval(0, colCount[0] - 1);

        this.RunImage.changeRow(0);
        this.RunImage.changeMinMaxInterval(0, colCount[1] - 1);
     

        this.JumpImage.changeRow(0);
        this.JumpImage.changeMinMaxInterval(0, colCount[2] - 1);

        this.PushImage.changeRow(0);
        this.PushImage.changeMinMaxInterval(0, colCount[1] - 1);

        this.AttackImage.changeRow(0);
        this.AttackImage.changeMinMaxInterval(0, colCount[1] - 1);

        this.x = (window.innerWidth) / 2;
        this.y = window.innerHeight - 110;
        this.node.style.bottom = this.y + "px";
        this.minY = window.innerHeight - 110;
    }

    jump() {
        if (!this.isJumping) {
            this.isJumping = true;
            this.jumpStartY = this.y;
            this.velocityY = this.jumpForce;
        }
    }


    tick() {
        if ((wKeyon && aKeyOn) || (wKeyon && dKeyOn)) {
            this.jump();
            const speedX = 3
            if(aKeyOn){
                this.x -= speedX;
                this.node.style.transform = 'scaleX(-1)';
            } else{
                this.x += speedX;
                this.node.style.transform = 'scaleX(1)';
            }
        } else if (dKeyOn) {
            this.currentImage = this.RunImage;
          
            this.node.style.transform = 'scaleX(1)';
            this.x += this.speedX;
        } else if (aKeyOn) {
          
            this.currentImage = this.RunImage;
            
            this.node.style.transform = 'scaleX(-1)';
            this.x -= this.speedX;
            
        } else if(wKeyon) {
            let canJump = 1000
            if (canJump == 1000) {
                this.jump();
                canJump--;
            }
            canJump == 1000;
        }else if (eKeyon) {
            this.currentImage = this.AttackImage;
        }else {
            this.currentImage = this.idleImage;
        }

        if (this.isJumping) {
            this.velocityY += this.gravity;
            this.y += this.velocityY;

            if (this.y >= this.minY) {
                this.y = this.minY;
                this.isJumping = false;
                this.velocityY = 0;
            }
        } else if (!wKeyon && this.y < this.minY) {
            this.y += this.gravity;
        }
        this.currentImage.tick(this.x, this.y);
        return true;
    }
}
