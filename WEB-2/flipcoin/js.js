window.addEventListener("load", () =>{
    const coin = document.querySelector('.coin');
    const flipButton = document.querySelector('.flip');

    flipButton.addEventListener('click', () => {
        coin.classList.add('rotate'); 
        setTimeout(() => {
            coin.classList.remove('rotate')
        }, 1000);
    });
})