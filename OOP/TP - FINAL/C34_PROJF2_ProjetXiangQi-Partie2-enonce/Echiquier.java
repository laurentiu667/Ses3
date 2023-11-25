package xiangqi;



public class Echiquier {

    private final int LIGNE = 10;
    private final int COLONNE = 9;
    private Intersection[][] jeu ;

    public Echiquier(){
        // Initialisation dans le constructeur
        for (int i = 0; i < LIGNE; i++){
            for (int j = 0; j < COLONNE; j++) {
                this.jeu[i][j] = new Intersection();
            }
        }
    }


}
