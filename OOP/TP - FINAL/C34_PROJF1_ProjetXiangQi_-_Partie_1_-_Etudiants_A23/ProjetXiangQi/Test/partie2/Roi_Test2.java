package partie2;

import org.junit.jupiter.api.*;
import static org.junit.jupiter.api.Assertions.*;

import xiangqi.*;

public class Roi_Test2 {
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
    public void verifRoi(){
        echiquier.getIntersection(0,3).setPiece(new Mandarin("m1", couleur1));
        echiquier.getIntersection(0,4).setPiece(new Roi("r1", couleur1));
        echiquier.getIntersection(0,5).setPiece(new Char("c2", couleur2));
        assertFalse(echiquier.cheminPossible(new Position(0,4), new Position(0,3)));
        assertTrue(echiquier.cheminPossible(new Position(0,4), new Position(0,5)));

        assertTrue(echiquier.cheminPossible(new Position(0,4), new Position(1,4)));
    }
}
