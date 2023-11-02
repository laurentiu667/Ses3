let planet = ["img/earth.png", "img/jupiter.png", "img/mars.png", "img/neptune.png", "img/saturn.png"];

window.addEventListener("load", () => {
    let backGrColor = document.querySelector("#sColor");
    let backGroundSpace = document.querySelector(".space");
    let addStar = document.querySelector(".add-star");
    let addplanet = document.querySelector(".add-planet");
    let sun = document.querySelector(".sun")
    placementAleatoire = (node) => {
        const minX = 0;
        const maxX = window.innerWidth;
        const minY = 0;
        const maxY = window.innerHeight;
        const X = Math.floor(Math.random() * (maxX - minX + 1)) + minX;
        const Y = Math.floor(Math.random() * (maxY - minY + 1)) + minY;
        node.style.top = Y + "px"; 
        node.style.left = X + "px"; 
    };

    backGrColor.addEventListener("input", () => {

        backGroundSpace.style.backgroundColor = backGrColor.value;
    });

    addStar.addEventListener("click", () => {
        let node = document.createElement("div");
        backGroundSpace.appendChild(node); 

        node.classList.add("ui-comp", "sun");

        placementAleatoire(node);
        node.addEventListener("mousemove", () => {
            node.remove()
        })
    });
    sun.addEventListener("click", () => {
        let sun = document.querySelectorAll(".sun");
        sun.forEach((element) => {
            setTimeout(() => {
                element.remove();
            }, 2000);
        });
    });

    addplanet.addEventListener("click", () => {
       
        let node = document.createElement("div");
        backGroundSpace.appendChild(node); 
        let randomImage = planet[Math.floor(Math.random() * planet.length)];
        node.style.backgroundImage = `url(${randomImage})`;
  
        node.classList.add("ui-comp");

        placementAleatoire(node);
        node.addEventListener("click", () => {
            node.remove()
        })
    });
    document.addEventListener("keydown", (event) => { if (event.key === "Escape") {window.location.reload(); } });
});
