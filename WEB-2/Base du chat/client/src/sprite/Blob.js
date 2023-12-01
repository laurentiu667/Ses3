import TiledImage from '@ftheriault/animatedsprite';

export default class Blob {
    constructor() {
        let colCount = [12];
        let rowCount = 1;
        let refreshDelay = 100;
        let loopColumns = true;
        let scale = 2;

        this.speedX = 2;
        this.scale = -1;

        this.node = document.createElement("div");
        this.node.classList.add("blob")
        document.body.append(this.node);
        this.node.style.zIndex = 100;

        this.idleImage = new TiledImage(
            "../decorations/blob.png",
            colCount[0],
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );
       

        this.idleImage.changeRow(0);
        this.idleImage.changeMinMaxInterval(0, colCount[0] - 1);

        this.x = Math.floor(Math.random() * window.innerWidth)
        this.y = window.innerHeight - 100;
        this.node.style.bottom = this.y + "px";
        this.node.style.transform = `scaleX(${this.scale})`;


        this.largeur = window.innerWidth;
    }
    remove2() {
        this.node.remove();
    }
    posxy() {        
        const position = this.node.getBoundingClientRect();
        return position;
    }
    tick() {
        if (this.x >= this.largeur) {
            this.speedX = -Math.abs(this.speedX);
            this.scale = 1;
        } else if (this.x <= 0) {
            this.speedX = Math.abs(this.speedX);
            this.scale = -1;
        }

        this.x += this.speedX;
        this.node.style.transform = `scaleX(${this.scale})`;
        this.idleImage.tick(this.x, this.y);
        this.posxy();
        // setTimeout(() => {
        //     this.remove2();  
        // }, 1000);
        return true;
    }
    
}
