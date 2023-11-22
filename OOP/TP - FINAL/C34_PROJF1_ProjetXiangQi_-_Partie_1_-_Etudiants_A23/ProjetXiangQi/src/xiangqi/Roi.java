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

        if(norme(depart, arrivee) == 0){
            return true;
        }
        else if (soustractionColonne == 1 || soustractionColonne == -1 || soustractionLigne == 1 || soustractionLigne == -1){ // Si le pion avance de un dans un axe de -1 ou 1
            if(arrivee.getColonne() <= 5 && arrivee.getColonne() >= 3){ // Pour rester dans l'axe des y pour les rouges et les noirs
                if(getCouleur().equals("rouge") && arrivee.getLigne() <= 2){  // Pour rester dans l'axe des x, cela évite de dépasser son cadre
                    return true;
                }
                else return getCouleur().equals("noir") && arrivee.getLigne() >= 7; // Pour rester dans l'axe des x, cela évite de dépasser son cadre
            }
            else
                return false;
        }
        return false;
    }

}
