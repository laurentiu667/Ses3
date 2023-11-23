package xiangqi;

public class Elephant extends Piece{
    // Constructeur
    public Elephant(String nom, String couleur) {
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
        else if (norme(depart,arrivee) == 8){ // En diagonal

            if(getCouleur().equals("rouge") && arrivee.getLigne() >= 5){  // Pour rester dans l'axe des x, cela évite de dépasser son cadre
                return true;
            }
            else return getCouleur().equals("noir") && arrivee.getLigne() <= 4; // Pour rester dans l'axe des x, cela évite de dépasser son cadre

        }
        return false;
    }

}

