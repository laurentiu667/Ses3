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

        if(norme(depart, arrivee) == 0){
            return true;
        }
        else if ((soustractionColonne == 0 && soustractionLigne != 0) || (soustractionColonne != 0 && soustractionLigne == 0)){
            return true;
        }
        return false;
    }

}
