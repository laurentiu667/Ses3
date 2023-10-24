let sprite = [];

window.addEventListener("load", () => {
    for (let i = 1; i <= 3; i++) {
        sprite.push(new Frame("blades" + i));
    }
    
    tick();
});

const tick = () => {
    for (let i = 0; i < sprite.length; i++) {
        const frame = sprite[i];
        frame.tick();
    }
    window.requestAnimationFrame(tick);
};
