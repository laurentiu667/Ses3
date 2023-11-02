let spriteList = [];

window.addEventListener("load", () => {
    tick();
});

document.onmousemove = banane => {
    spriteList.push(new Square(banane.pageX, banane.pageY));
};

const tick = () => {
    for (let i = 0; i < spriteList.length; i++) {
        const sprite = spriteList[i];
        let alive = sprite.tick();

        if (!alive) {
            spriteList.splice(i, 1);
            i--;
        }
    }

    window.requestAnimationFrame(tick);
};

class Square {
    constructor(x, y) {
        this.carre = document.createElement("div");
        this.carre.classList.add("square");
        this.carre.style.top = y + "px";
        this.carre.style.left = x + "px";
        this.carre.style.backgroundColor = "red"; // Initial color is red
        this.color = "red"; // Add a color property

        document.body.append(this.carre);
        this.y = y;
        this.velocity = 0.9;
        this.speed = 1;
    }

    tick() {
        let alive = true;
        this.speed += this.velocity;
        this.y -= this.speed;
        this.carre.style.top = this.y + "px";

        if (this.y < 0) {
            alive = false;
            this.carre.remove();
        }

        if (this.y <= 300) {
            this.carre.style.backgroundColor = "#BB0000";
            this.color = "orange";
        }
        if (this.y <= 250) {
            this.carre.style.backgroundColor = "#EE4A00";
            this.color = "white";
        }
        if (this.y <= 200) {
            this.carre.style.backgroundColor = "#FFB180";
            this.color = "orange";
        }
        if (this.y <= 100) {
            this.carre.style.backgroundColor = "#FFFFFF";
            this.color = "white";
        }

        return alive;
    }
}
