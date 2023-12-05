package xiangqiPartie2;

import xiangqi.*;


public class Echiquier extends Intersection implements MethodesEchiquier {

    // 	Un échiquier sera donc un tableau 10x9 ( 10 lignes, 9 colonnes ) d’objets jesais.Intersection
    private final int LIGNE = 10;
    private final int COLONNE = 9;
    private final Intersection[][] jeu;


    public Echiquier() {

        this.jeu = new Intersection[LIGNE][COLONNE];
        for (int i = 0; i < LIGNE; i++) {
            for (int j = 0; j < COLONNE; j++) {

                Position position = new Position(i, j);
                this.jeu[i][j] = new Intersection(position);
            }
        }
    }



    public Intersection getIntersection(int ligne, int colonne) {
        return jeu[ligne][colonne];
    }


    public void debuter() {
        // Placement des pièces noires
        // Roi
        jeu[0][4].setPiece(new Roi("r", "noir"));
        // Char (Tour)
        jeu[0][0].setPiece(new Char("t1", "noir"));
        jeu[0][8].setPiece(new Char("t2", "noir"));
        // Cavalier
        jeu[0][1].setPiece(new Cavalier("c1", "noir"));
        jeu[0][7].setPiece(new Cavalier("c2", "noir"));
        // Elephant
        jeu[0][2].setPiece(new Elephant("e1", "noir"));
        jeu[0][6].setPiece(new Elephant("e2", "noir"));
        // Mandarin (Garde)
        jeu[0][3].setPiece(new Mandarin("m1", "noir"));
        jeu[0][5].setPiece(new Mandarin("m2", "noir"));
        // Bombarde (Canon)
        jeu[2][1].setPiece(new Bombarde("b1", "noir"));
        jeu[2][7].setPiece(new Bombarde("b2", "noir"));
        // Pion
        jeu[3][0].setPiece(new Pion("p1", "noir"));
        jeu[3][2].setPiece(new Pion("p2", "noir"));
        jeu[3][4].setPiece(new Pion("p3", "noir"));
        jeu[3][6].setPiece(new Pion("p4", "noir"));
        jeu[3][8].setPiece(new Pion("p5", "noir"));

        // Placement des pièces rouges
        // Roi
        jeu[9][4].setPiece(new Roi("r", "rouge"));
        // Char (Tour)
        jeu[9][0].setPiece(new Char("t1", "rouge"));
        jeu[9][8].setPiece(new Char("t2", "rouge"));
        // Cavalier
        jeu[9][1].setPiece(new Cavalier("c1", "rouge"));
        jeu[9][7].setPiece(new Cavalier("c2", "rouge"));
        // Elephant
        jeu[9][2].setPiece(new Elephant("e1", "rouge"));
        jeu[9][6].setPiece(new Elephant("e2", "rouge"));
        // Mandarin (Garde)
        jeu[9][3].setPiece(new Mandarin("m1", "rouge"));
        jeu[9][5].setPiece(new Mandarin("m2", "rouge"));
        // Bombarde (Canon)
        jeu[7][1].setPiece(new Bombarde("b1", "rouge"));
        jeu[7][7].setPiece(new Bombarde("b2", "rouge"));
        // Pion
        jeu[6][0].setPiece(new Pion("p1", "rouge"));
        jeu[6][2].setPiece(new Pion("p2", "rouge"));
        jeu[6][4].setPiece(new Pion("p3", "rouge"));
        jeu[6][6].setPiece(new Pion("p4", "rouge"));
        jeu[6][8].setPiece(new Pion("p5", "rouge"));

    }

    public boolean cheminPossible(Position depart, Position arrivee) {
        Intersection intersectionDepart = getIntersection(depart.getLigne(), depart.getColonne());
        Intersection intersectionArrivee = getIntersection(arrivee.getLigne(), arrivee.getColonne());
        // Si le joueur ne bouge la piece
        if (arrivee.getColonne() == depart.getColonne() && arrivee.getLigne() == depart.getLigne()) {
            return true;
        }
        // S il y a une piece alors on prends sa couleur et on la compare avec l arrive de la case en prennant en compte s il y a une piece
        if (intersectionArrivee.getPiece() != null && intersectionDepart.getPiece().getCouleur().equals(intersectionArrivee.getPiece().getCouleur())) {
            return false;
        }
        // Si la piece en trouver contient la lettre en question entre le premier et le cinquieme alors on verifie le mouvement dans sa fonction
        // Pion
        if (intersectionDepart.getPiece().getNom().contains("p")) {
            return verifPion(depart, arrivee, intersectionDepart, intersectionArrivee);
        } else if (intersectionDepart.getPiece().getNom().contains("r")){
            return verifRoi(depart, arrivee, intersectionDepart, intersectionArrivee);
        }
        return false;
    }

    private boolean verifPion(Position depart, Position arrivee, Intersection interDepart, Intersection interArrivee) {

        return interArrivee.getPiece() != null && interDepart.getPiece().getCouleur() != interArrivee.getPiece().getCouleur();

    }
    private boolean verifRoi(Position depart, Position arrivee, Intersection interDepart, Intersection interArrivee){
        return false;
    }

    @Override
    public boolean roisNePouvantPasEtreFaceAFace(Position posPremierRoi, Position posDeuxiemeRoi) {
//        Intersection intersectionDepart = getIntersection(posPremierRoi.getLigne(), posPremierRoi.getColonne());
//        Intersection intersectionArrivee = getIntersection(posDeuxiemeRoi.getLigne(), posDeuxiemeRoi.getColonne());
//
//        // Roi est dans la meme colonne
//        if (posPremierRoi.getColonne() == posDeuxiemeRoi.getColonne()) {
//            // Detection d'une piece entre les deux rois
//            // Commencer la detection une case apres la position du roi
//            for (int i = posPremierRoi.getLigne() + 1; i <= posDeuxiemeRoi.getLigne(); i++) {
//                // Vérifier si la pièce à l'intersection n'est pas null avant d'appeler getNom()
//                if (jeu[i][posPremierRoi.getColonne()].getPiece() != null && jeu[i][posPremierRoi.getColonne()].getPiece().getNom().equals("p")) {
//                    return false;
//                }
//            }
//            // Pas de piece détectée
//            return true;
//        } else {
//            // Roi ne sont pas face a face
//            return true;
//        }
//    }


}
