package partie2;

import org.junit.jupiter.api.*;
import static org.junit.jupiter.api.Assertions.*;

import xiangqi.*;

public class Mandarin_Test2 {
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
    public void verifMandarin(){
        echiquier.getIntersection(0,3).setPiece(new Mandarin("m1", couleur1));
        echiquier.getIntersection(1,4).setPiece(new Pion("r1", couleur2));

        assertTrue(echiquier.cheminPossible(new Position(0,3), new Position(1,4)));
        echiquier.getIntersection(1,4).setPiece(null);

        echiquier.getIntersection(1,4).setPiece(new Pion("r1", couleur1));
        assertFalse(echiquier.cheminPossible(new Position(0,3), new Position(1,4)));
        echiquier.getIntersection(1,4).setPiece(null);
        assertTrue(echiquier.cheminPossible(new Position(0,3), new Position(1,4)));

    }
}
