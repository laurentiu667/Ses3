package xiangqi;

public class Cavalier extends Piece{
    // Constructeur
    public Cavalier(String nom, String couleur) {
        super(nom, couleur);
    }

    @Override
    public boolean estValide(Position depart, Position arrivee) {
        int soustractionLigne = Math.abs(depart.getLigne() - arrivee.getLigne());
        int soustractionColonne = Math.abs(depart.getColonne() - arrivee.getColonne());


        if ((soustractionColonne == 2 && soustractionLigne == 1) || (soustractionColonne == 1 && soustractionLigne == 2)) {
            return true;
        }

        // Si la pièce n'a pas bougé alors false;
        return norme(depart, arrivee) == 0;
    }

}
