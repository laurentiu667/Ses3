package partie2;

import org.junit.jupiter.api.*;
import static org.junit.jupiter.api.Assertions.*;

import xiangqi.*;

public class Char_Test2 {
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

    @Test
    public void verifChar(){
        echiquier.getIntersection(9,4).setPiece(new Char("c1", couleur1));
        echiquier.getIntersection(6,4).setPiece(new Pion("p1", couleur2));

        assertTrue(echiquier.cheminPossible(new Position(9,4), new Position(6,4)));
        assertTrue(echiquier.cheminPossible(new Position(9,4), new Position(9,0)));
        echiquier.getIntersection(7,4).setPiece(new Pion("p2", couleur2));

        assertFalse(echiquier.cheminPossible(new Position(9,4), new Position(6,4)));

        echiquier.getIntersection(3,8).setPiece(new Char("c1", couleur1));
        echiquier.getIntersection(3,4).setPiece(new Pion("p3", couleur2));
        assertTrue(echiquier.cheminPossible(new Position(3,8), new Position(3,4)));
        echiquier.getIntersection(3,0).setPiece(new Pion("p4", couleur2));
        assertFalse(echiquier.cheminPossible(new Position(3,8), new Position(3,0)));
    }
}
