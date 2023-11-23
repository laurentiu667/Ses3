package xiangqi;

public class Cavalier extends Piece{
    // Constructeur
    public Cavalier(String nom, String couleur) {
        super(nom, couleur);
    }

    @Override
    public boolean estValide(Position depart, Position arrivee) {
        // LIGNE -----------
        int soustractionLigne = Math.abs(depart.getLigne() - arrivee.getLigne());
        // COLONNE |||||||||||
        int soustractionColonne = Math.abs(depart.getColonne() - arrivee.getColonne());

        if(norme(depart, arrivee) == 0){
            return true;
        }
        if (getCouleur().equals("rouge") || getCouleur().equals("noir")){
            if ((soustractionColonne == 2 && soustractionLigne == 1) || soustractionColonne == 1 && soustractionLigne == 2){
                return true;
            }
        }
        return false;
    }
}
