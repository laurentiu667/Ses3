class Frame {
    constructor(id) {
       this.id = id;
       this.node = document.querySelector("#" + this.id);

       this.btnLess = document.querySelector("#btn-less");
       this.btnMore = document.querySelector("#btn-more");
       this.windSpeed = 1;
       this.angle = 0; 
       
       this.btnLess.addEventListener("click", () => {
           this.windSpeed -= 1;

       });

       this.btnMore.addEventListener("click", () => {
           this.windSpeed += 1;

       });
    }

    tick() {
        this.angle += this.windSpeed;
        this.node.style.transform = `rotate(${this.angle}deg)`;
    }
}