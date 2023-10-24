const button = document.querySelector("#analyze-btn")

button.addEventListener('click', () =>{

    setTimeout(() => {
        document.querySelector("#analyze-icon").style.opacity = 1;
    }, 2000)
    setTimeout(() => {
        document.querySelector("#analyze-icon").style.opacity = 0;
        document.querySelector("#analyze-result").style.opacity = 1;
    }, 4000)

})
/*
window.addEventListener("load", () => {
    let buttonNode = document.querySelector("button")

    buttonNode.oncancel = () => {
        let iconNode = document.querySelector("#analyze-icon");
        iconNode.style.display = "block";

        setTimeout(() => {
            iconNode.style.display = "none";

            let resultNode = document.querySelector("#analyze-result");
            resultNode.style.display = "block";

        }, 2000);
    }
})
*/