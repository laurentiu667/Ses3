package xiangqi;

public class Char extends Piece{
    // Constructeur
    public Char(String nom, String  couleur) {
        super(nom, couleur);
    }

    @Override
    public boolean estValide(Position depart, Position arrivee) {
        // LIGNE -----------
        int soustractionLigne = depart.getLigne() - arrivee.getLigne();
        // COLONNE |||||||||||
        int soustractionColonne = depart.getColonne() - arrivee.getColonne();
        // Vérifier si on fait des pas horizontal ou vertical
        if ((soustractionColonne == 0 && soustractionLigne != 0) || (soustractionColonne != 0 && soustractionLigne == 0)){
            return true;
        }
        // Si la pièce n'a pas bouger alors false;
        return norme(depart, arrivee) == 0;
    }

}
