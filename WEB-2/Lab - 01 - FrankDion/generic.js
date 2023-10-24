window.addEventListener("load", () => {
    const genericDiv = document.querySelector(".generic"); 
    
    let currentTop = 660;
    let moveUp = false;
    // Faut mettre le generic en position relative 
    function moveGeneric() {
        if (moveUp) {
            currentTop++;
        } else {
            currentTop--;
        }

        genericDiv.style.top = currentTop + "px";

        if (currentTop <= 0) {
            moveUp = false;
        } else if (currentTop >= 600) {
            moveUp = true;
        }
    }

    setInterval(moveGeneric, 30);

    genericDiv.addEventListener('click', () => {
        moveUp = !moveUp;
    });
});
