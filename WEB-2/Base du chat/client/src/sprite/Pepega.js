export default class Pepega {
    constructor(id) {
        this.id = id;
        this.node = document.querySelector("#" + this.id);
        this.nouvelleDiv = document.createElement("div");
        this.nouvelleDiv.classList.add("pepega");
        document.body.append(this.nouvelleDiv);

        this.largeurEcran = window.innerWidth;
        this.X = Math.random() * this.largeurEcran;
        this.Y = Math.random() * -50;
        this.speedY = 1;
        this.nouvelleDiv.style.top = this.Y + "px";
        this.nouvelleDiv.style.left = this.X + "px";
    }

    tick() {
        this.Y += this.speedY;
        console.log("Y Position:", this.Y); // Add this line
        this.nouvelleDiv.style.top = this.Y + "px";
    }
}
