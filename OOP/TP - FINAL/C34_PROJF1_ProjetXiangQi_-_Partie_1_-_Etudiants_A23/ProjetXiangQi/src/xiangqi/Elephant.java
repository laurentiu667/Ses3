package xiangqi;

public class Elephant extends Piece{
    // Constructeur
    public Elephant(String nom, String couleur) {
        super(nom, couleur);
    }

    @Override
    public boolean estValide(Position depart, Position arrivee) {
        return false;
    }
}
