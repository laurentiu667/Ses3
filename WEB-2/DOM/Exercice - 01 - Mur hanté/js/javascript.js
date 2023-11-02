let spriteList = [];

window.addEventListener("load", () => {
    for (let i = 1; i <= 6; i++) {
        // Utilisez l'ID correct pour chaque image diabolique
        spriteList.push(new Frame("frame-" + i + "-evil"));
    }
    tick();
});

const tick = () => {
    for (let i = 0; i < spriteList.length; i++) {
        const frame = spriteList[i];
        frame.tick();
    }
    window.requestAnimationFrame(tick);
};
