import { signin, sKeyon } from './chat-api';

window.addEventListener("load", () => {
    document.querySelector("form").onsubmit = function () {
        return signin(this);
    };
   
});
