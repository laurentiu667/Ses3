class Frame {
    constructor(id) {
        this.id = id;
        this.node = document.querySelector("#" + this.id);
        this.opacity = 0.0; // Initialisez l'opacité à 0
        this.speed = 0.05; // Initialisez la vitesse

        this.node.onmouseover = () => {
            this.speed = -this.speed;
        };
        this.node.onmouseout = () => {
            this.speed = -this.speed;
        };
    }

    tick() {
        // Mettez à jour l'opacité en fonction de la vitesse
        this.opacity += this.speed;

        // Limitez l'opacité entre 0 et 1
        this.opacity = Math.max(0, Math.min(1, this.opacity));

        // Appliquez l'opacité à l'image
        this.node.style.opacity = this.opacity.toString();
    }
}