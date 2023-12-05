package partie2;

import org.junit.jupiter.api.*;
import xiangqi.Position;

import xiangqi.*;

import static org.junit.jupiter.api.Assertions.*;
import xiangqiPartie2.*;
public class Echequier_Test {
    @BeforeAll
    public static void setup(){
        System.out.println("===================");
        System.out.println("= DÉBUT DES TESTS =");
        System.out.println("===================");
    }

    @AfterAll
    public static void finTests(){
        System.out.println("=================");
        System.out.println("= FIN DES TESTS =");
        System.out.println("=================");
    }

    @AfterEach
    public void apresChaqueTest(){
        System.out.println("= Test complété =");
    }

    Echiquier echiquier = new Echiquier();

    String couleur1 = "noir";

    String couleur2 = "rouge";

    // M'assurer que toutes les pièces sont présentes à leur positions initiales avants de commencer une partie
    @Test
    public void verification_PieceEchiquier(){

        echiquier.debuter();

        assertEquals(echiquier.getIntersection(0, 0).getPiece().getNom(),new Char("t1", couleur1).getNom());
        assertEquals(echiquier.getIntersection(0, 0).getPiece().getCouleur(),new Char("t1", couleur1).getCouleur());

    }

    @Test
    public void testRoisNePouvantPasEtreFaceAFace() {
        Echiquier echiquier = new Echiquier();
        echiquier.debuter();

        // Avancer
        assertTrue(echiquier.roisNePouvantPasEtreFaceAFace(new Position(3, 4), new Position(4, 4)));
        // Aller a droite
        assertTrue(echiquier.roisNePouvantPasEtreFaceAFace(new Position(4, 4), new Position(4, 5)));

        assertTrue(echiquier.roisNePouvantPasEtreFaceAFace(new Position(6, 4), new Position(5, 4)));

//        assertTrue(echiquier.roisNePouvantPasEtreFaceAFace(new Position(6, 4), new Position(5, 4)));
    }

    @Test
    public void Pion(){
        echiquier.debuter();

        // Aller vers cases Ennemi en face de soi en etant noir pour manger Rouge
        echiquier.getIntersection(5, 4).setPiece(new Pion("p1",couleur1));
        assertTrue(echiquier.cheminPossible(new Position(5,4), new Position(6,4)));

        // Aller vers cases Ennemi a droite en etant allier
        echiquier.getIntersection(6, 3).setPiece(new Pion("p2",couleur1));
        assertTrue(echiquier.cheminPossible(new Position(6,3), new Position(6,2)));

        // Aller vers cases Ennemi a gauche en etant allier
        echiquier.getIntersection(6, 3).setPiece(new Pion("p3",couleur1));
        assertTrue(echiquier.cheminPossible(new Position(6,3), new Position(6,4)));


        // Aller vers cases Ennemi a droite en etant allier
        echiquier.getIntersection(6, 3).setPiece(new Pion("p2",couleur2));
        assertFalse(echiquier.cheminPossible(new Position(6,3), new Position(6,2)));

        // Aller vers cases Ennemi a gauche en etant allier
        echiquier.getIntersection(6, 3).setPiece(new Pion("p3",couleur2));
        assertFalse(echiquier.cheminPossible(new Position(6,3), new Position(6,4)));



    }


}
