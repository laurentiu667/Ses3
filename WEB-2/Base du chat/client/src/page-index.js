import { signin, sKeyon } from './chat-api';

window.addEventListener("load", () => {
    document.querySelector("form").onsubmit = function () {
        return signin(this);
    };
    let lobbyAudioPlayed = false;

    function handleAudioEnded() {
        lobbyAudioPlayed = false;
        console.log('Audio has ended');
    }
});
