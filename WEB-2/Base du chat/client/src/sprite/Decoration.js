export default class Decoration{
    constructor(){
        this.lamp = document.createElement("div");
   
        document.body.append(this.lamp);

        this.lamp.style.backgroundImage = "url('../decorations/lamp.png')";
        this.lamp.classList.add("decorations")
        this.lamp.style.bottom = 75 + "px"
        this.lamp.style.left = (window.innerWidth - 800) + "px";
       
    }
    tick(){
        
    }
}