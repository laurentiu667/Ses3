import org.junit.jupiter.api.*;
import xiangqi.Elephant;
import xiangqi.Position;

import static org.junit.jupiter.api.Assertions.*;
public class Elephant_Test {
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

    // ROUGE

    // MOUVEMENT PERMIT
    @Test
    public void deplacementSurPlace(){
        Elephant pion = new Elephant("m1", "rouge");
        Position depart = new Position(9, 2);
        Position arrivee = new Position(9, 2);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnDiagonalDe2(){
        Elephant pion = new Elephant("m1", "rouge");
        Position depart = new Position(9, 2);
        Position arrivee = new Position(7, 0);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnDiagonalDe2Autre(){
        Elephant pion = new Elephant("m1", "rouge");
        Position depart = new Position(7, 0);
        Position arrivee = new Position(5, 2);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnDiagonalDe2Autre2(){
        Elephant pion = new Elephant("m1", "rouge");
        Position depart = new Position(5, 2);
        Position arrivee = new Position(7, 4);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnDiagonalDe2Autre3(){
        Elephant pion = new Elephant("m1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(9, 2);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnDiagonalDe2Autre4(){
        Elephant pion = new Elephant("m1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(5, 6);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnDiagonalDe2Autre5(){
        Elephant pion = new Elephant("m1", "rouge");
        Position depart = new Position(5, 6);
        Position arrivee = new Position(7, 8);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnDiagonalDe2Autre6(){
        Elephant pion = new Elephant("m1", "rouge");
        Position depart = new Position(7, 8);
        Position arrivee = new Position(9, 6);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnDiagonalDe2Autre7(){
        Elephant pion = new Elephant("m1", "rouge");
        Position depart = new Position(9, 6);
        Position arrivee = new Position(7, 4);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnDiagonalDe2Autre8(){
        Elephant pion = new Elephant("m1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(9, 2);
        assertTrue(pion.estValide(depart, arrivee));
    }

    // TEST PAS PERMIS

    @Test
    public void deplacementEnDiagonalDeUn(){
        Elephant pion = new Elephant("m1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(6, 3);
        assertFalse(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnDiagonalDeUnAutre(){
        Elephant pion = new Elephant("m1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(6, 5);
        assertFalse(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnDiagonalDeUnAutre2(){
        Elephant pion = new Elephant("m1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(8, 5);
        assertFalse(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnDiagonalDeUnAutre3(){
        Elephant pion = new Elephant("m1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(8, 3);
        assertFalse(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnAvant(){
        Elephant pion = new Elephant("m1", "noir");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(6, 4);
        assertFalse(pion.estValide(depart, arrivee));
    }

    // ESSAYER DE TRAVERSER LA RIVIERE

    @Test
    public void deplacementEnDiagonalTraverserRiviere(){
        Elephant pion = new Elephant("m1", "rouge");
        Position depart = new Position(5, 2);
        Position arrivee = new Position(3, 4);
        assertFalse(pion.estValide(depart, arrivee));
    }

     // NOIR

     // MOUVEMENT PERMIT
    @Test
    public void NoirdeplacementSurPlace(){
        Elephant pion = new Elephant("m1", "noir");
        Position depart = new Position(0, 2);
        Position arrivee = new Position(0, 2);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnDiagonalDe2(){
        Elephant pion = new Elephant("m1", "noir");
        Position depart = new Position(2, 4);
        Position arrivee = new Position(2, 4);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnDiagonalDe2Autre(){
        Elephant pion = new Elephant("m1", "noir");
        Position depart = new Position(2, 4);
        Position arrivee = new Position(0, 6);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnDiagonalDe2Autre2(){
        Elephant pion = new Elephant("m1", "noir");
        Position depart = new Position(0, 6);
        Position arrivee = new Position(2, 8);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnDiagonalDe2Autre3(){
        Elephant pion = new Elephant("m1", "noir");
        Position depart = new Position(2, 8);
        Position arrivee = new Position(4, 6);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnDiagonalDe2Autre4(){
        Elephant pion = new Elephant("m1", "noir");
        Position depart = new Position(4, 6);
        Position arrivee = new Position(2, 4);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnDiagonalDe2Autre5(){
        Elephant pion = new Elephant("m1", "noir");
        Position depart = new Position(2, 4);
        Position arrivee = new Position(4, 2);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnDiagonalDe2Autre6(){
        Elephant pion = new Elephant("m1", "noir");
        Position depart = new Position(4, 2);
        Position arrivee = new Position(2, 0);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnDiagonalDe2Autre7(){
        Elephant pion = new Elephant("m1", "noir");
        Position depart = new Position(2, 0);
        Position arrivee = new Position(0, 2);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnDiagonalDe2Autre8(){
        Elephant pion = new Elephant("m1", "noir");
        Position depart = new Position(0, 2);
        Position arrivee = new Position(2, 4);
        assertTrue(pion.estValide(depart, arrivee));
    }

    // TEST PAS PERMIS

    @Test
    public void NoirdeplacementEnDiagonalDeUn(){
        Elephant pion = new Elephant("m1", "noir");
        Position depart = new Position(2, 4);
        Position arrivee = new Position(3, 3);
        assertFalse(pion.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnDiagonalDeUnAutre(){
        Elephant pion = new Elephant("m1", "noir");
        Position depart = new Position(2, 4);
        Position arrivee = new Position(1, 5);
        assertFalse(pion.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnDiagonalDeUnAutre2(){
        Elephant pion = new Elephant("m1", "noir");
        Position depart = new Position(2, 4);
        Position arrivee = new Position(1, 3);
        assertFalse(pion.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnDiagonalDeUnAutre3(){
        Elephant pion = new Elephant("m1", "noir");
        Position depart = new Position(2, 4);
        Position arrivee = new Position(3, 5);
        assertFalse(pion.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnAvant(){
        Elephant pion = new Elephant("m1", "noir");
        Position depart = new Position(2, 4);
        Position arrivee = new Position(3, 4);
        assertFalse(pion.estValide(depart, arrivee));
    }

    // ESSAYER DE TRAVERSER LA RIVIERE

    @Test
    public void NoirdeplacementEnDiagonalTraverserRiviere(){
        Elephant pion = new Elephant("m1", "noir");
        Position depart = new Position(4, 2);
        Position arrivee = new Position(6, 0);
        assertFalse(pion.estValide(depart, arrivee));
    }

}
