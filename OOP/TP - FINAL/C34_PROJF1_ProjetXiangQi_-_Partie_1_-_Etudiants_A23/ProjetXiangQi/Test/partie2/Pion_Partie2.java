package partie2;

import org.junit.jupiter.api.*;
import xiangqi.Position;

import static org.junit.jupiter.api.Assertions.*;
import xiangqiPartie2.*;
public class Pion_Partie2 {
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

    @Test
    public void testCheminPossible() {
        Echiquier echiquier = new Echiquier();
        echiquier.debuter();

    }
//    @Test
//    public void testVerifPion() {
//        Echiquier echiquier = new Echiquier();
//        echiquier.debuter();
//
//        assertTrue(echiquier.cheminPossible(new Position(6, 0), new Position(5, 0)));
//
//        assertFalse(echiquier.cheminPossible(new Position(6, 0), new Position(4, 0)));
//
//        assertFalse(echiquier.cheminPossible(new Position(6, 0), new Position(5, 1)));
//
//        assertFalse(echiquier.cheminPossible(new Position(4, 0), new Position(3, 0)));
//
//    }
//    @Test
//    public void testRoisNePouvantPasEtreFaceAFace() {
//        Echiquier echiquier = new Echiquier();
//        echiquier.debuter();
//
//
//        assertTrue(echiquier.roisNePouvantPasEtreFaceAFace(new Position(0, 4), new Position(9, 4)));
//
//
//    }


}
