package xiangqi;

public class Pion extends Piece{

    // Constructeur
    public Pion(String nom, String couleur) {
        super(nom, couleur);
    }

    @Override
    public boolean estValide(Position depart, Position arrivee) {
        // LIGNE -----------
        int soustractionLigne = depart.getLigne() - arrivee.getLigne();
        // COLONNE |||||||||||
        int soustractionColonne = depart.getColonne() - arrivee.getColonne();

        if(getCouleur().equals("rouge")){
            // Avant la rivière
            if (depart.getLigne() >= 5){
                if (soustractionLigne == 1 && soustractionColonne == 0){
                    return true;
                }
            }
            // Après la rivière
            else{
                if ((soustractionLigne == 1 && soustractionColonne == 0) || (soustractionLigne == 0 && Math.abs(soustractionColonne) == 1)){
                    return true;
                }
            }
        }

        if(getCouleur().equals("noir")){
            // Avant la rivière
            if (depart.getLigne() <= 4){
                if (soustractionLigne == -1 && soustractionColonne == 0){
                    return true;
                }
            }
            // Après la rivière
            else{
                if ((soustractionLigne == -1 && soustractionColonne == 0) || (soustractionLigne == 0 && Math.abs(soustractionColonne) == 1)){
                    return true;
                }
            }
        }

        return false;
    }

//    // Constructeur
//    public Pion(String nom, String couleur) {
//        super(nom, couleur);
//    }
//
//    @Override
//    public boolean estValide(Position depart, Position arrivee) {
//        // LIGNE -----------
//        int soustractionLigne = Math.abs(depart.getLigne() - arrivee.getLigne());
//        // COLONNE |||||||||||
//        int soustractionColonne = Math.abs(depart.getColonne() - arrivee.getColonne());
//
//        if( (getCouleur().equals("rouge") && (depart.getLigne() >= 5) ) || ( getCouleur().equals("noir") && (depart.getLigne() <= 4) ) ){
//            // Avant la riviere
//            if (soustractionLigne == 1 && soustractionColonne == 0){
//                return true;
//            }
//            // Après la rivière
//            else{
//                if ((soustractionLigne == 1 && soustractionColonne == 0) || (soustractionLigne == 0 && soustractionColonne == 1)){
//                    return true;
//                }
//            }
//        }
//
//        return false;
//    }
}


