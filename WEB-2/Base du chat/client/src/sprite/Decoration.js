export default class Decoration{
    constructor(){
        this.lamp = document.createElement("div");
        this.rock = document.createElement("div");
        document.body.append(this.lamp , this.rock);

        this.lamp.style.backgroundImage = "url('../decorations/lamp.png')";
        this.lamp.classList.add("decorations")
        this.lamp.style.bottom = 75 + "px"
        this.lamp.style.left = (window.innerWidth - 800) + "px";
        
        // this.rock.style.backgroundImage = "url('../decorations/rock_3.png')";
        // this.rock.classList.add("decorations")
        // this.rock.classList.add("roche")
        // this.rock.style.bottom = 75 + "px"
        // this.rock.style.left = (window.innerWidth - 1200) + "px";
        // this.rock.style.scale = 1
       
    }
    tick(){
        
    }
}