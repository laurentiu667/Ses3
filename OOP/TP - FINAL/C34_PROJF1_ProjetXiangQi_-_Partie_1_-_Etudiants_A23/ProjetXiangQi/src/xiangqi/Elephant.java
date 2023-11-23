package xiangqi;

public class Elephant extends Piece{
    // Constructeur
    public Elephant(String nom, String couleur) {
        super(nom, couleur);
    }

    @Override
    public boolean estValide(Position depart, Position arrivee) {
       if (norme(depart,arrivee) == 8){ // En diagonal de 2

            if(getCouleur().equals("rouge") && arrivee.getLigne() >= 5){  // Pour rester dans l'axe des y, cela évite de dépasser son cadre
                return true;
            }
            else return getCouleur().equals("noir") && arrivee.getLigne() <= 4; // Pour rester dans l'axe des y, cela évite de dépasser son cadre

        }
        // Si la pièce n'a pas bouger alors false;
        return norme(depart, arrivee) == 0;
    }

}

