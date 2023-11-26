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
        this.speedY = 6;
        this.nouvelleDiv.style.top = this.Y + "px";
        this.nouvelleDiv.style.left = this.X + "px";
        this.nouvelleDiv.style.transform = `scale(${-1.5})`;
        this.nouvelleDiv.style.opacity = 1;
        this.opacityRemove = 0.008;
    }

    tick() {
        this.Y += this.speedY;
        this.nouvelleDiv.style.opacity -= this.opacityRemove; // Gradually reduce the opacity

        if (this.nouvelleDiv.style.opacity === "0") {
            this.nouvelleDiv.remove();  // Remove the entire node from the DOM
        }

        this.nouvelleDiv.style.top = this.Y + "px";
    }
}
