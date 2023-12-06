package partie2;

import org.junit.jupiter.api.*;

import xiangqi.*;

import xiangqiPartie2.*;
import static org.junit.jupiter.api.Assertions.*;
public class Elephant_Test2 {
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
    public void Elephant_Test(){
        echiquier.getIntersection(0,2).setPiece(new Elephant("e1", couleur1)); //  Mandarin
        echiquier.getIntersection(2,4).setPiece(new Pion("p1", couleur2)); // Pion rouge

//        // Essayer de le manger si (possible)
//        assertTrue(echiquier.cheminPossible(new Position(0,2 ), new Position(2,4)));

        echiquier.getIntersection(1,3).setPiece(new Pion("p2", couleur2)); // Pion rouge
        assertFalse(echiquier.cheminPossible(new Position(0,2 ), new Position(2,4)));

    }




}
