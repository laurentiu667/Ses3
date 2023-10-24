window.addEventListener("load", () => {
    let posY = -100;
    let posX = -100;
    let winNode = document.querySelector("#youwin");

    window.onmouseover = () => {
        // Générez des positions aléatoires pour déplacer la div
        posX = Math.random() * 120;
        posY = Math.random() * 120;

        // Appliquez les nouvelles positions
        winNode.style.left = posX + "px";
        winNode.style.top = posY + "px";
    }

    const SPEED = 10;
    let counter = 0;
    let greenState = true;

    const goDown = () => {
        counter++;
        winNode.style.tranform = "rotate(" + counter + "deg)";
        if (posY < 250){
            posY += SPEED;
        }

        if (counter > 20) {
            counter = 0;
            greenState = !greenState;
            winNode.style.color = greenState ? "green" : "red";
            winNode.style.backgroundColor = greenState ? "red" : "green";
        }
        winNode.style.top = posY + "px";
        setTimeout(goDown, 30);
    }
    goDown();
})