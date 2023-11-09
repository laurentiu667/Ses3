// On peut l utilsier de l exterieure cette fonction
export const generateAsciiArt = () => {
    document.body.innerHTML = "<pre>" +
"    _,                          _                  \n"+
"    .'  `.                  ___.&gt;\"''-..-.      \n"+
"    `-.   ;           .--\"\"\"        .-._@;      \n"+
"       ;  !_.--..._ .'      /     .[_@'`'.         \n"+
"      ;            /       : .'  ; :_.._  `.       \n"+
"      :           ;        ;[   _T-\"  `.'-. `-.   \n"+
"       \\        .-:      ; `.`-=_,88p.   _.}.-\"  \n"+
"        `-.__.-'   \\    /L._ Y\",P$T888;  \"\"    \n"+
"                 .-'_.-'  / ;$$$$$$]8P;            \n"+
"                 \\ /     / / \"Y$$P\" ^\"         \n"+
"         fsc      ;\\_    `.\\_._                  \n"+
"                  ]__\\     \\___;   \n"+
    "</pre>";
}

export const alertMessage = msg => {
    alert(msg);
}