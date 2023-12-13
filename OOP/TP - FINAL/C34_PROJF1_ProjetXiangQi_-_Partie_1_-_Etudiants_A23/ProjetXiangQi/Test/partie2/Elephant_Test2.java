package partie2;

import org.junit.jupiter.api.*;

import xiangqi.*;

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

        // pas de piece entre
        assertTrue(echiquier.cheminPossible(new Position(0,2 ), new Position(2,4)));

        echiquier.getIntersection(1,3).setPiece(new Pion("p2", couleur2)); // Pion rouge
        // Essayer mais faire en sorte qu il y a un pion entre

        assertFalse(echiquier.cheminPossible(new Position(0,2 ), new Position(2,4)));


        // Essayer d acceder avec aucun obstacle
        echiquier.getIntersection(9,6).setPiece(new Elephant("e2", couleur2));
        echiquier.getIntersection(7,4).setPiece(new Pion("p1", couleur1));
        assertTrue(echiquier.cheminPossible(new Position(9,6 ), new Position(7,4)));

        //Essayer si il y a une piece
        echiquier.getIntersection(8,5).setPiece(new Pion("p2", couleur1));
        assertFalse(echiquier.cheminPossible(new Position(9,6 ), new Position(7,4)));

        // Essayer d acceder avec aucun obstacle 2
        echiquier.getIntersection(0,6).setPiece(new Elephant("e2", couleur2));
        echiquier.getIntersection(2,4).setPiece(new Pion("p1", couleur1));
        assertTrue(echiquier.cheminPossible(new Position(0,6 ), new Position(2,4)));

        //Essayer si il y a une piece 2
        echiquier.getIntersection(1,5).setPiece(new Pion("p2", couleur1));
        assertFalse(echiquier.cheminPossible(new Position(0,6 ), new Position(2,4)));

        assertTrue(echiquier.cheminPossible(new Position(0,6 ), new Position(2,8)));
    }




}
