window.addEventListener("load", () => {
    const boite = document.querySelector(".the-box"), SPEED = 20; 

    let cliquer = false, x = 0, y = 0, clickx = 0, clicky = 0;

    function moveBox() {
        x += (clickx - x) / SPEED;
        y += (clicky - y) / SPEED;

        boite.style.left = x + "px";
        boite.style.top = y + "px";
    }
    
    setInterval(moveBox, 0); 

    document.addEventListener('click', (event) => {
        clickx = event.clientX; 
        clicky = event.clientY; 

        cliquer = !cliquer;

        boite.style.backgroundColor = cliquer ? "red" : "blue";
    });
});


// Ici c est si on donne des coordonnées x et y

// window.addEventListener("load", () => {
//     const boite = document.querySelector(".the-box"), SPEED = 40; 
//     let cliquer = false, x = 0, y = 0, clickx = 400, clicky = 200;

//     function moveBox() {
        
//         if (cliquer){
//             x += (clickx - x) / SPEED;
//             y += (clicky - y) / SPEED;
//         }
//         else{
//             x = (0 + x) / SPEED;
//             y = (0 + y) / SPEED;
//         }
        
//         boite.style.left = x + "px";
//         boite.style.top = y + "px";

//     }

//     setInterval(moveBox, 0); 

//     boite.addEventListener("click", () => {
//         console.log(true);
//         cliquer = !cliquer
//     })

    
// });
