import org.junit.jupiter.api.*;
import xiangqi.Bombarde;
import xiangqi.Position;

import static org.junit.jupiter.api.Assertions.*;
public class Bombarde_Test {
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
        Bombarde bombarde = new Bombarde("c1", "rouge");
        Position depart = new Position(9, 0);
        Position arrivee = new Position(9, 0);
        assertTrue(bombarde.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnAvantUneCase(){
        Bombarde bombarde = new Bombarde("c1", "rouge");
        Position depart = new Position(9, 0);
        Position arrivee = new Position(9, 1);
        assertTrue(bombarde.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnAvantPlusieursCase(){
        Bombarde bombarde = new Bombarde("c1", "rouge");
        Position depart = new Position(9, 0);
        Position arrivee = new Position(9, 5);
        assertTrue(bombarde.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnAvantApresRiviere(){
        Bombarde bombarde = new Bombarde("c1", "rouge");
        Position depart = new Position(9, 0);
        Position arrivee = new Position(9, 3);
        assertTrue(bombarde.estValide(depart, arrivee));
    }
    @Test
    public void deplacementEnArriere(){
        Bombarde bombarde = new Bombarde("c1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(9, 4);
        assertTrue(bombarde.estValide(depart, arrivee));
    }
    @Test
    public void deplacementGauche(){
        Bombarde bombarde = new Bombarde("c1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(7, 1);
        assertTrue(bombarde.estValide(depart, arrivee));
    }
    @Test
    public void deplacementDroite(){
        Bombarde bombarde = new Bombarde("c1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(7, 8);
        assertTrue(bombarde.estValide(depart, arrivee));
    }
    // MOUVEMENT INTERDIT
    @Test
    public void deplacementDiagonal(){
        Bombarde bombarde = new Bombarde("c1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(6, 5);
        assertFalse(bombarde.estValide(depart, arrivee));
    }
    @Test
    public void deplacementDiagonalAutre(){
        Bombarde bombarde = new Bombarde("c1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(8, 3);
        assertFalse(bombarde.estValide(depart, arrivee));
    }



}
