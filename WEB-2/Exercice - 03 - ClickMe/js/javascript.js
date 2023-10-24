let monstre;

window.addEventListener("load", () => {
    monstre = new Frame("#alien");
    tick();
});

const tick = () => {
    monstre.tick();
    requestAnimationFrame(tick);
};