// default pas obliger cela nous permet de l import sans les {} et que un default par fichier
// C est comme si on a plein de fonction dans un fichier et qu on veux utiliser tous les fonctions
export default class Square {
    constructor () {
        this.node = document.createElement("div");
        this.node.style = "width:10px;height:10px;background-color:black;position:absolute";
        document.body.append(this.node);
    }

    tick() {
        this.node.style.left = this.node.offsetLeft + 2 + "px";

        return true;
    }
}