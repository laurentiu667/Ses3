window.addEventListener("load", () => {
    const account = document.querySelector(".acc"); // Add appropriate selector here
    const Password = document.querySelector(".pass"); // Add appropriate selector here
    const acc = document.querySelector(".acces-acc"); // Add appropriate selector here
    const pass = document.querySelector(".acces-pass"); // Add appropriate selector here
    Password.addEventListener("click", () => {
        account.style.backgroundColor = "#28292c";
        Password.style.backgroundColor = "#18191B";
        acc.style.display = "none"
        pass.style.display = "block"
    });
    account.addEventListener("click", () => {
        Password.style.backgroundColor = "#28292c";
        account.style.backgroundColor = "#18191B"; 
        pass.style.display = "none"
        acc.style.display = "block"

    });
});
