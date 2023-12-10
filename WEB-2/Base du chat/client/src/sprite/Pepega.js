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
        this.speedY = 3;
        this.stop = false;
        this.nouvelleDiv.style.top = this.Y + "px";
        this.nouvelleDiv.style.left = this.X + "px";
        this.nouvelleDiv.style.transform = `scale(${-1.5})`;
        this.nouvelleDiv.style.opacity = 1;
        this.opacityRemove = 0.003;

        this.nouvelleDiv.addEventListener("mouseover", () => {
      
            this.nouvelleDiv.style.transform = "scale(1.5)";
        });
   
         this.nouvelleDiv.addEventListener("mouseout", () => {
            this.nouvelleDiv.style.transform = "scale(1)";
        });


       
       
    }

    tick() {
       

        this.X += 2 * Math.cos(this.Y / 50);
            
        this.Y += this.speedY;
       
        this.nouvelleDiv.style.opacity -= this.opacityRemove;

        if (parseFloat(this.nouvelleDiv.style.opacity) <= 0) {
            this.nouvelleDiv.remove();  
        }

        this.nouvelleDiv.style.top = this.Y + "px";
        this.nouvelleDiv.style.left = this.X + "px";
    }
   
}
