import org.junit.jupiter.api.*;
import xiangqi.Char;
import xiangqi.Elephant;
import xiangqi.Position;

import static org.junit.jupiter.api.Assertions.*;
public class Char_Test {
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
    public void deplacementSurPlace(){
        Char pion = new Char("c1", "rouge");
        Position depart = new Position(9, 0);
        Position arrivee = new Position(9, 0);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnAvantUneCase(){
        Char pion = new Char("c1", "rouge");
        Position depart = new Position(9, 0);
        Position arrivee = new Position(9, 1);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnAvantPlusieursCase(){
        Char pion = new Char("c1", "rouge");
        Position depart = new Position(9, 0);
        Position arrivee = new Position(9, 5);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnAvantApresRiviere(){
        Char pion = new Char("c1", "rouge");
        Position depart = new Position(9, 0);
        Position arrivee = new Position(9, 3);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnArriere(){
        Char pion = new Char("c1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(9, 4);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementGauche(){
        Char pion = new Char("c1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(7, 1);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementDroite(){
        Char pion = new Char("c1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(7, 8);
        assertTrue(pion.estValide(depart, arrivee));
    }
    // MOUVEMENT INTERDIT
    @Test
    public void deplacementDiagonal(){
        Char pion = new Char("c1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(6, 5);
        assertFalse(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementDiagonalAutre(){
        Char pion = new Char("c1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(8, 3);
        assertFalse(pion.estValide(depart, arrivee));
    }



}
