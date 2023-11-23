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

        // Si la pièce fait un bas dans l axe de x ou y en s'aidant de Math.abs
        if (getCouleur().equals("rouge") || getCouleur().equals("noir")){
            if ((soustractionColonne == 2 && soustractionLigne == 1) || soustractionColonne == 1 && soustractionLigne == 2){
                return true;
            }
        }
        // Si la pièce n'a pas bouger alors false;
        return norme(depart, arrivee) == 0;
    }
}
