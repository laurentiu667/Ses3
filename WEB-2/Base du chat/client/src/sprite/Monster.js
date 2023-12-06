import TiledImage from '@ftheriault/animatedsprite';
import Blob from './Blob.js';
import {spriteList, wKeyon, sKeyon, aKeyOn, dKeyOn, qKeyon, eKeyon } from '../page-chat.js';

export default class Monster {
    constructor(existingBlobInstance) {
        this.blob = existingBlobInstance;
        
        let colCount = [4, 6, 8];
        let rowCount = 1;
        let refreshDelay = 100;
        let loopColumns = true;
        let scale = 2.5;

        this.hit = false;
        this.collisionperso = false;
        this.speedX = 3;
        this.speedY = 1;
        this.health = 100;
        this.gravity = 1;
        this.jumpForce = -15;
        this.velocityY = 0;
        this.canJump = 1000
        this.vie = 0;
        this.backgroundVie = ["url('../monster/vie4.png')", "url('../monster/vie3.png')", "url('../monster/vie2.png')", "url('../monster/vie1.png')", "url('../monster/vie0.png')"]
        this.isJumping = false;
        this.node = document.createElement("div");
        this.node.classList.add("monster")
        this.vieDiv = document.createElement("div")
        this.vieDiv.classList.add("vie")

        document.body.appendChild(this.node);
        document.body.appendChild(this.vieDiv);
        
        this.node.style.zIndex = 100;
        this.idleImage = new TiledImage(
            "../monster/Owlet_Monster_Idle_4.png",
            colCount[0],
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
        this.RunImage = new TiledImage(
            "../monster/Owlet_Monster_Run_6.png",
            colCount[1],
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
        this.JumpImage = new TiledImage(
            "../monster/Owlet_Monster_Jump_8.png",
            colCount[2],
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
        this.PushImage = new TiledImage(
            "../monster/Owlet_Monster_Push_6.png",
            colCount[1],
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
        this.AttackImage = new TiledImage(
            "../monster/Owlet_Monster_Attack2_6.png",
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

    updateVie() {
        this.vieDiv.style.backgroundImage = this.backgroundVie[this.vie];
    }

    jump() {
        if (!this.isJumping) {
            this.isJumping = true;
            this.jumpStartY = this.y;
            this.velocityY = this.jumpForce;
        }
    }

    collision() {
        let rect1 = this.node.getBoundingClientRect();
        let rect2 = this.blob.posxy();
        if (rect1.right >= rect2.left && rect1.left <= rect2.left + rect2.width ) {
            
           return true;
        } else {
            
            return false;
        }
    }
    
    deplacement(){
        if ((wKeyon && aKeyOn) || (wKeyon && dKeyOn)) {
            this.jump();
            const speedX = 4
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
            
        } else if (wKeyon) {
            if (this.canJump === 1000 && !this.isJumping) {
                this.jump();
                this.canJump--;
                setTimeout(() => {
                    this.canJump = 1000;
                }, 700);
            }
        } else if (eKeyon) {
            if (this.collision()) {
                this.hit = true;
                
                setTimeout(() => {
                    this.blob.remove2()
                }, 2000);
            }
            this.currentImage = this.AttackImage;
        } else {
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
    }

    sortie() {
     
        if (this.x >= window.innerWidth) {
        
           this.x = 30
        } else if (this.x < 0) {
            this.x = 1920
        }
    }
    

    ptsPerdue(){
       
        setTimeout(() => {
            if (this.collision()){
           
                this.vie = 1
            }
        }, 50);
    }
    

    tick() {
        this.collision();
        this.deplacement();

        this.sortie();
        
        const vieDivOffsetY = -65; 
        this.vieDiv.style.left = this.x + vieDivOffsetY + 'px';
        this.vieDiv.style.top = this.y - 170 + 'px';

        this.currentImage.tick(this.x, this.y);
     
        this.updateVie();
        
        return true;
    }
}