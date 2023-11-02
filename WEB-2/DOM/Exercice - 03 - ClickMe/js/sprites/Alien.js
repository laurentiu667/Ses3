class Frame {
    constructor(id) {
        this.id = id;
        this.monstre = document.querySelector(this.id);
        this.scoreInput = document.querySelector("#input-score");
        this.timerInput = document.querySelector("#input-timer");
        this.timerStarted = false;
        this.finjeux = false;
        this.boxfin = document.querySelector(".box_fin");
        this.scoreptn = document.querySelector(".lescore");
        this.restart = document.querySelector("#restart");

        if (this.finjeux === false) {
            this.monstre.addEventListener("click", () => {
                if (this.timerInput.value === 0) {

                    return;
                }
                this.move();
                this.score();
                if (!this.timerStarted) {
                    this.startTimer();
                    this.timerStarted = true;
                }
            });
        }
    }

    move() {
        this.monstre.style.left = 100 + Math.random() * (window.innerWidth - 200) + "px";
        this.monstre.style.top = "400px";
    }

    score() {
        this.scoreInput.value++;
    }

    startTimer() {
        this.timerStarted = true;
        let currentTimer = parseInt(this.timerInput.value);
        const countdown = setInterval(() => {
            currentTimer--;
            this.timerInput.value = currentTimer;
            if (currentTimer === 0) {
                clearInterval(countdown);
                this.timerStarted = false;
                this.boxfin.style.display = "flex";
                this.boxfin.style.flexDirection = "column";
                this.boxfin.style.alignItems = "center";
                this.scoreptn.textContent = this.scoreInput.value;
                this.restart.addEventListener("click", () => {
                    this.boxfin.style.display = "none";
                    this.scoreInput.value = 0;
                    this.timerInput.value = 10;
                });
            }
        }, 1000);
    }
}