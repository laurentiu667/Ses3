package partie2;

import org.junit.jupiter.api.*;
import static org.junit.jupiter.api.Assertions.*;

import xiangqi.*;
import xiangqiPartie2.*;
public class Cavalier_Test2 {
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
    public void testVerifCavalier() {
        echiquier.getIntersection(0, 3).setPiece(new Cavalier("m1", couleur1));
        echiquier.getIntersection(2, 4).setPiece(new Roi("r1", couleur1));

       assertTrue(echiquier.cheminPossible(new Position(0, 3), new Position(2, 4)));
    }
}
