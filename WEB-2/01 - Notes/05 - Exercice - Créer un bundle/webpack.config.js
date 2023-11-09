const path = require("path")

// webpack fait un fichier pour tous les autres et ca permet de regrouper par exemple 50 fichier js pour ne pas importer les 50. 
module.exports = {
    entry : {
        main: './js/animation.js'
    },
    mode: 'development',
    output: {
        filename: '[name].js',
        path: path.resolve(__dirname, 'dist')
    }
}