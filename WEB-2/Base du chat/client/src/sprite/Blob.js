import TiledImage from '@ftheriault/animatedsprite';
import Monster from './Monster';
export default class Blob {
    constructor(monster) {
        this.monster = monster
        let colCount = [13, 5, 14];
        let rowCount = 1;
        let refreshDelay = 50;
        let loopColumns = true;
        let scale = 1.3;
        
        
        this.speedX = 1;
        this.scale = -1;
        this.idle = true;
        this.node = document.createElement("div");
        document.body.append(this.node);
        this.node.classList.add("blob")
  
        this.node.style.zIndex = 100;

        this.idleImage = new TiledImage(
            "../chicken/Idle.png",
            colCount[0],
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
        this.HitImage = new TiledImage(
            "../chicken/Hit.png",
            colCount[1],
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
        this.RunImage = new TiledImage(
            "../chicken/Run.png",
            colCount[2],
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
       
       

        this.idleImage.changeRow(0);
        this.idleImage.changeMinMaxInterval(0, colCount[0] - 1);

        this.HitImage.changeRow(0);
        this.HitImage.changeMinMaxInterval(0, colCount[1] - 1);

        this.RunImage.changeRow(0);
        this.RunImage.changeMinMaxInterval(0, colCount[2] - 1);

        this.x = Math.floor(Math.random() * window.innerWidth)
        this.y = window.innerHeight - 100;
        this.node.style.bottom = this.y + "px";
        this.node.style.transform = `scaleX(${this.scale})`;


        this.largeur = window.innerWidth;
    }
    posxy() {        
        const position = this.node.getBoundingClientRect();
        return position;
    }
    
    remove2() {
        this.node.remove();
    }
    tick() {
        console.log(this.monster.hit);

        if (this.monster.hit){

            this.currentImage = this.HitImage;
            this.currentImage.setLooped(false)
        } else{
            this.currentImage = this.RunImage;
            if (this.x >= this.largeur) {
                this.speedX = -Math.abs(this.speedX);
                this.scale = 1;
            } else if (this.x <= 0) {
                this.speedX = Math.abs(this.speedX);
                this.scale = -1;
            }
            this.x += this.speedX;
        }
        
    
        this.node.style.transform = `scaleX(${this.scale})`;
        this.currentImage.tick(this.x, this.y);
    
    
        return true;
    }
    
    
}
