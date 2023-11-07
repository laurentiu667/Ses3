window.addEventListener("load", () =>{
    let close = document.querySelector(".close-pop");
    let pop_up = document.querySelector('.pop-up');
    const articles = [
        {
            title: "Bubble Tea Pastel Emoji 1",
            author: "onekey",
            startDate: "Nov. 4th 20:00EST"
        },
        {
            title: "Chinese Zodiac Keycaps",
            author: "BY MORTAL STUDIO",
            startDate: "Join gb"
        },
        {
            title: "Arc60 Last Batch",
            author: "BY VERTEX",
            startDate: "Live Now"
        },
        {
            title: "Aeroboard70",
            author: "BY SMIT6Y WORKS",
            startDate: "Nov. 4th 20:00EST"
        },
        {
            title: "R63",
            author: "FROM JOJO STUDIO",
            startDate: "In-stock"
        }

    ];


    const articleSection = document.getElementById("articleSection");

    const createArticleElement = (article, index) => {
        const articleElement = document.createElement("article");
        articleElement.classList.add("art-" + (index + 1), "art");
        articleElement.style.backgroundImage = `url(../img/img${index + 1}.webp)`;

        articleElement.innerHTML = `
            <div class="global-art">
                <h1 class="article-title">${article.title}</h1>
                <p class="autor">By ${article.author}</p>
                <button class="button-gb-join">${article.startDate}</button>
            </div>
        `;

        articleSection.appendChild(articleElement);
    }

    articles.forEach((article, index) => {
        createArticleElement(article, index);
    });

    let burger_clickX2 = document.querySelector(".burger-quit")
    let burger_clickX = document.querySelector(".burger")
    let menuBurger = document.querySelector(".menuburger")

    burger_clickX.addEventListener("click", () =>{
        menuBurger.style.display = "block";
        menuBurger.classList.toggle("transition")
    })
    burger_clickX2.addEventListener("click", () =>{
        menuBurger.style.display = "none";
        menuBurger.classList.toggle("transition-x-remove")
    })
 
    let menuLinks = document.querySelectorAll('.menu-link');
    menuLinks.forEach(function(link) {
        link.addEventListener('click', () => {
            let target = link.getAttribute('data-target');
            let subMenu = document.querySelector('[data-submenu="' + target + '"]');
            subMenu.classList.toggle('show-menu');
            let classshowmenu = document.querySelector('.show-menu')
          
        });
    });
 
      // POP-UP
    let show_pop = () =>{
        setTimeout(() => {
            pop_up.style.display = "grid";
            
        }, 1000);
    }
   
    let pop_uup = () => {
        close.addEventListener("click", () => {
            pop_up.style.display = "none";
            
        })
    }
    show_pop()
    pop_uup()
 
    let search_click = document.querySelector(".search")
    let search = document.querySelector(".search-container")
    let search_form = document.querySelector(".forum-search")


})