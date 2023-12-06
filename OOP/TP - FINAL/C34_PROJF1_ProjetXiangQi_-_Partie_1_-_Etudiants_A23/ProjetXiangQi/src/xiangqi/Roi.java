package xiangqi;

public class Roi extends Piece{
    // Constructeur
    public Roi(String nom, String couleur) {
        super(nom, couleur);
    }

    @Override
    public boolean estValide(Position depart, Position arrivee) {
        // LIGNE -----------
        int soustractionLigne = depart.getLigne() - arrivee.getLigne();
        // COLONNE |||||||||||
        int soustractionColonne = depart.getColonne() - arrivee.getColonne();

        if (soustractionColonne == 1 || soustractionColonne == -1 || soustractionLigne == 1 || soustractionLigne == -1){ // Si le pion avance de un dans un axe de -1 ou 1
            if(arrivee.getColonne() <= 5 && arrivee.getColonne() >= 3){ // Pour rester dans l'axe des x pour les rouges et les noirs
                if(getCouleur().equals("noir") && arrivee.getLigne() <= 2){  // Pour rester dans l'axe des y, cela évite de dépasser son cadre
                    return true;
                }
                else return getCouleur().equals("rouge") && arrivee.getLigne() >= 7; // Pour rester dans l'axe des y, cela évite de dépasser son cadre
            }
            else
                return false;
        }
        // Si la pièce n'a pas bouger alors false;
        return norme(depart, arrivee) == 0;
    }

}
