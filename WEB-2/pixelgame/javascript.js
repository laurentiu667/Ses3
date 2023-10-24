window.addEventListener("load", () => {
    let input_colonne = document.querySelector("#square_by");
    let parent = document.querySelector("#game_pixel");
    let couleur = document.querySelector("#color1ST");
    let draw = false; // Move draw variable here
    let isMouseDown = false;
    let reset = document.querySelector("#reset")
    var regex = /^\d+$/;
    let blob = document.querySelectorAll("#blob")
    const sprite = [];
    input_colonne.onkeyup = (event) => {
        if (event.key == "Enter") {
            if (regex.test(input_colonne.value)) {
                const colonne = input_colonne.value;
                parent.style.setProperty('--size', colonne); // ca sert a donner la variable au css 
                input_colonne.value = "";
    
                for (let i = 0; i < colonne * colonne; i++) {
                    let noeud = document.createElement('div');
                    noeud.classList.add("pixel");
                    parent.append(noeud);
    
                    noeud.addEventListener('mousedown', () => {
                        draw = true;
                    });
                    noeud.addEventListener('mousemove', () => {
                        if (draw) {
                            noeud.style.backgroundColor = couleur.value;
                            noeud.style.border = "0.1px solid " + couleur.value;
                        }
                    });
                    noeud.addEventListener('mouseup', () => {
                        draw = false;
                    });
    
                    reset.addEventListener('click', () =>{
                        noeud.style.backgroundColor = "white"
                        noeud.style.border = "0.1px solid black"
                        noeud.remove();

                    })
                }
            }
            else{
                input_colonne.value = "";
            }
        }
    }

    sprite.push(new Frame("blob"));

    const tick = () => {
        for (let i = 0; i < sprite.length; i++) {
            const frame = sprite[i];
            frame.tick();
        }
        window.requestAnimationFrame(tick);
    };
    tick();


});
