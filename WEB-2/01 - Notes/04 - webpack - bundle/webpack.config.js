const path = require("path")

// webpack fait un fichier pour tous les autres et ca permet de regrouper par exemple 50 fichier js pour ne pas importer les 50. 
module.export = {
    entry : {
        main : './src/index.html'
    },
    mode: 'development',
    output: {
        filename: '[name].js',
        path: path.resolve(__dirname, 'dist')
    }
}