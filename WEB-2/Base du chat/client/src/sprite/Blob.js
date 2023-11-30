import TiledImage from '@ftheriault/animatedsprite';

export default class Blob {
    constructor() {
        let colCount = [12];
        let rowCount = 1;
        let refreshDelay = 100;
        let loopColumns = true;
        let scale = 2;

        this.node = document.createElement("div");
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
  
    }

    tick() {
        this.x -= 0.3;
        this.idleImage.tick(this.x, this.y);
        return true;
    }
}
