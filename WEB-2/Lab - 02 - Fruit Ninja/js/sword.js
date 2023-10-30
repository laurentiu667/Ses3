class Sword{
    constructor(x, y){
        this.x = x;
        this.y = y;
        
		this.node = document.createElement("div");
		this.node.classList.add("sword-slash");
		this.node.style.left = this.x + "px";
		this.node.style.top = this.y + "px";
		document.getElementById("game").append(this.node);

    }

    tick() {
		

		let alive = this.counter;

		if (!alive) {
			this.node.remove();
		}

		return alive;
	}
}