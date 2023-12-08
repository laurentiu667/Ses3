import TiledImage from "@ftheriault/animatedsprite"

export default class Maison {
    constructor() {
    

        let colCount = [6];
        let rowCount = 1;
        let refreshDelay = 100;
        let loopColumns = true;
        let scale = 2;

        this.speedX = 8;

        this.node = document.createElement("div");
        document.body.append(this.node);

        this.idleImage = new TiledImage(
            "../decorations/shop_anim.png",
            colCount[0],
            rowCount,
            refreshDelay,
            loopColumns,
            scale,
            this.node
        );

        
        this.currentImage = this.idleImage;
        this.idleImage.changeRow(0);
        this.idleImage.changeMinMaxInterval(0, colCount[0] - 1);
        
        this.node.style.bottom = 67 + "px"
        this.node.style.left = (window.innerWidth - 400) + "px";
       
    }
    posxy() {        
        const position = this.node.getBoundingClientRect();
        return position;
    }
    tick() {
        


        this.currentImage.tick(this.x, this.y);
        return true;
    }
}
