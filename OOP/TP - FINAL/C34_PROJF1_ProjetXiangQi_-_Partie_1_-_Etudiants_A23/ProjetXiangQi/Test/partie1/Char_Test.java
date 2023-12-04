package partie1;

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

    // Les tests marcheront aussi pour les noirs autant que les rouges
    @Test
    public void deplacementSurPlace(){
        Char char1 = new Char("c1", "rouge");
        Position depart = new Position(9, 0);
        Position arrivee = new Position(9, 0);
        assertTrue(char1.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnAvantUneCase(){
        Char char1 = new Char("c1", "rouge");
        Position depart = new Position(9, 0);
        Position arrivee = new Position(9, 1);
        assertTrue(char1.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnAvantPlusieursCase(){
        Char char1 = new Char("c1", "rouge");
        Position depart = new Position(9, 0);
        Position arrivee = new Position(9, 5);
        assertTrue(char1.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnAvantApresRiviere(){
        Char char1 = new Char("c1", "rouge");
        Position depart = new Position(9, 0);
        Position arrivee = new Position(9, 3);
        assertTrue(char1.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnArriere(){
        Char char1 = new Char("c1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(9, 4);
        assertTrue(char1.estValide(depart, arrivee));
    }
    @Test
    public void deplacementGauche(){
        Char char1 = new Char("c1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(7, 1);
        assertTrue(char1.estValide(depart, arrivee));
    }
    @Test
    public void deplacementDroite(){
        Char char1 = new Char("c1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(7, 8);
        assertTrue(char1.estValide(depart, arrivee));
    }
    // MOUVEMENT INTERDIT
    @Test
    public void deplacementDiagonal(){
        Char char1 = new Char("c1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(6, 5);
        assertFalse(char1.estValide(depart, arrivee));
    }
    @Test
    public void deplacementDiagonalAutre(){
        Char char1 = new Char("c1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(8, 3);
        assertFalse(char1.estValide(depart, arrivee));
    }



}
