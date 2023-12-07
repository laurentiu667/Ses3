package partie1;

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
        Elephant elephant = new Elephant("m1", "rouge");
        Position depart = new Position(9, 2);
        Position arrivee = new Position(9, 2);
        assertTrue(elephant.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnDiagonalDe2(){
        Elephant elephant = new Elephant("m1", "rouge");
        Position depart = new Position(9, 2);
        Position arrivee = new Position(7, 0);
        assertTrue(elephant.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnDiagonalDe2Autre(){
        Elephant elephant = new Elephant("m1", "rouge");
        Position depart = new Position(7, 0);
        Position arrivee = new Position(5, 2);
        assertTrue(elephant.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnDiagonalDe2Autre2(){
        Elephant elephant = new Elephant("m1", "rouge");
        Position depart = new Position(5, 2);
        Position arrivee = new Position(7, 4);
        assertTrue(elephant.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnDiagonalDe2Autre3(){
        Elephant elephant = new Elephant("m1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(9, 2);
        assertTrue(elephant.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnDiagonalDe2Autre4(){
        Elephant elephant = new Elephant("m1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(5, 6);
        assertTrue(elephant.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnDiagonalDe2Autre5(){
        Elephant elephant = new Elephant("m1", "rouge");
        Position depart = new Position(5, 6);
        Position arrivee = new Position(7, 8);
        assertTrue(elephant.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnDiagonalDe2Autre6(){
        Elephant elephant = new Elephant("m1", "rouge");
        Position depart = new Position(7, 8);
        Position arrivee = new Position(9, 6);
        assertTrue(elephant.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnDiagonalDe2Autre7(){
        Elephant elephant = new Elephant("m1", "rouge");
        Position depart = new Position(9, 6);
        Position arrivee = new Position(7, 4);
        assertTrue(elephant.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnDiagonalDe2Autre8(){
        Elephant elephant = new Elephant("m1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(9, 2);
        assertTrue(elephant.estValide(depart, arrivee));
    }

    // TEST PAS PERMIS

    @Test
    public void deplacementEnDiagonalDeUn(){
        Elephant elephant = new Elephant("m1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(6, 3);
        assertFalse(elephant.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnDiagonalDeUnAutre(){
        Elephant elephant = new Elephant("m1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(6, 5);
        assertFalse(elephant.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnDiagonalDeUnAutre2(){
        Elephant elephant = new Elephant("m1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(8, 5);
        assertFalse(elephant.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnDiagonalDeUnAutre3(){
        Elephant elephant = new Elephant("m1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(8, 3);
        assertFalse(elephant.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnAvant(){
        Elephant elephant = new Elephant("m1", "noir");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(6, 4);
        assertFalse(elephant.estValide(depart, arrivee));
    }

    // ESSAYER DE TRAVERSER LA RIVIERE

    @Test
    public void deplacementEnDiagonalTraverserRiviere(){
        Elephant elephant = new Elephant("m1", "rouge");
        Position depart = new Position(5, 2);
        Position arrivee = new Position(3, 4);
        assertFalse(elephant.estValide(depart, arrivee));
    }

     // NOIR

     // MOUVEMENT PERMIT
    @Test
    public void NoirdeplacementSurPlace(){
        Elephant elephant = new Elephant("m1", "noir");
        Position depart = new Position(0, 2);
        Position arrivee = new Position(0, 2);
        assertTrue(elephant.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnDiagonalDe2(){
        Elephant elephant = new Elephant("m1", "noir");
        Position depart = new Position(2, 4);
        Position arrivee = new Position(2, 4);
        assertTrue(elephant.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnDiagonalDe2Autre(){
        Elephant elephant = new Elephant("m1", "noir");
        Position depart = new Position(2, 4);
        Position arrivee = new Position(0, 6);
        assertTrue(elephant.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnDiagonalDe2Autre2(){
        Elephant elephant = new Elephant("m1", "noir");
        Position depart = new Position(0, 6);
        Position arrivee = new Position(2, 8);
        assertTrue(elephant.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnDiagonalDe2Autre3(){
        Elephant elephant = new Elephant("m1", "noir");
        Position depart = new Position(2, 8);
        Position arrivee = new Position(4, 6);
        assertTrue(elephant.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnDiagonalDe2Autre4(){
        Elephant elephant = new Elephant("m1", "noir");
        Position depart = new Position(4, 6);
        Position arrivee = new Position(2, 4);
        assertTrue(elephant.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnDiagonalDe2Autre5(){
        Elephant elephant = new Elephant("m1", "noir");
        Position depart = new Position(2, 4);
        Position arrivee = new Position(4, 2);
        assertTrue(elephant.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnDiagonalDe2Autre6(){
        Elephant elephant = new Elephant("m1", "noir");
        Position depart = new Position(4, 2);
        Position arrivee = new Position(2, 0);
        assertTrue(elephant.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnDiagonalDe2Autre7(){
        Elephant elephant = new Elephant("m1", "noir");
        Position depart = new Position(2, 0);
        Position arrivee = new Position(0, 2);
        assertTrue(elephant.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnDiagonalDe2Autre8(){
        Elephant elephant = new Elephant("m1", "noir");
        Position depart = new Position(0, 2);
        Position arrivee = new Position(2, 4);
        assertTrue(elephant.estValide(depart, arrivee));
    }

    // TEST PAS PERMIS

    @Test
    public void NoirdeplacementEnDiagonalDeUn(){
        Elephant elephant = new Elephant("m1", "noir");
        Position depart = new Position(2, 4);
        Position arrivee = new Position(3, 3);
        assertFalse(elephant.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnDiagonalDeUnAutre(){
        Elephant elephant = new Elephant("m1", "noir");
        Position depart = new Position(2, 4);
        Position arrivee = new Position(1, 5);
        assertFalse(elephant.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnDiagonalDeUnAutre2(){
        Elephant elephant = new Elephant("m1", "noir");
        Position depart = new Position(2, 4);
        Position arrivee = new Position(1, 3);
        assertFalse(elephant.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnDiagonalDeUnAutre3(){
        Elephant elephant = new Elephant("m1", "noir");
        Position depart = new Position(2, 4);
        Position arrivee = new Position(3, 5);
        assertFalse(elephant.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementEnAvant(){
        Elephant elephant = new Elephant("m1", "noir");
        Position depart = new Position(2, 4);
        Position arrivee = new Position(3, 4);
        assertFalse(elephant.estValide(depart, arrivee));
    }

    // ESSAYER DE TRAVERSER LA RIVIERE

    @Test
    public void NoirdeplacementEnDiagonalTraverserRiviere(){
        Elephant elephant = new Elephant("m1", "noir");
        Position depart = new Position(4, 2);
        Position arrivee = new Position(6, 0);
        assertFalse(elephant.estValide(depart, arrivee));
    }

}
