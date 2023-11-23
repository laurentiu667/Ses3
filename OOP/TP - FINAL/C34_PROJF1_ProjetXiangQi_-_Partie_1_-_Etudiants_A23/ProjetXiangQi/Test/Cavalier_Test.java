import org.junit.jupiter.api.*;
import xiangqi.Cavalier;

import xiangqi.Position;

import static org.junit.jupiter.api.Assertions.*;
public class Cavalier_Test {

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
    @Test
    public void deplacementSurPlace(){
        Cavalier pion = new Cavalier("c1", "rouge");
        Position depart = new Position(9, 1);
        Position arrivee = new Position(9, 1);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementHabituel(){
        Cavalier pion = new Cavalier("c1", "rouge");
        Position depart = new Position(9, 1);
        Position arrivee = new Position(7, 0);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementHabituel2(){
        Cavalier pion = new Cavalier("c1", "rouge");
        Position depart = new Position(9, 1);
        Position arrivee = new Position(7, 2);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementHabituel3(){
        Cavalier pion = new Cavalier("c1", "rouge");
        Position depart = new Position(9, 1);
        Position arrivee = new Position(8, 3);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementHabituel4(){
        Cavalier pion = new Cavalier("c1", "rouge");
        Position depart = new Position(6, 4);
        Position arrivee = new Position(8, 3);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementHabituel5(){
        Cavalier pion = new Cavalier("c1", "rouge");
        Position depart = new Position(6, 4);
        Position arrivee = new Position(5, 2);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementHabituel6(){
        Cavalier pion = new Cavalier("c1", "rouge");
        Position depart = new Position(6, 4);
        Position arrivee = new Position(8, 5);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementHabituelRiviere(){
        Cavalier pion = new Cavalier("c1", "rouge");
        Position depart = new Position(6, 4);
        Position arrivee = new Position(4, 5);
        assertTrue(pion.estValide(depart, arrivee));
    }

    // NOIR

    @Test
    public void NoirdeplacementSurPlace(){
        Cavalier pion = new Cavalier("c1", "rouge");
        Position depart = new Position(0, 1);
        Position arrivee = new Position(0, 1);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementHabituel(){
        Cavalier pion = new Cavalier("c1", "rouge");
        Position depart = new Position(0, 1);
        Position arrivee = new Position(2, 0);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementHabituel2(){
        Cavalier pion = new Cavalier("c1", "rouge");
        Position depart = new Position(0, 1);
        Position arrivee = new Position(2, 2);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementHabituel3(){
        Cavalier pion = new Cavalier("c1", "rouge");
        Position depart = new Position(0, 1);
        Position arrivee = new Position(1, 3);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementHabituel4(){
        Cavalier pion = new Cavalier("c1", "rouge");
        Position depart = new Position(2, 2);
        Position arrivee = new Position(3, 4);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementHabituel5(){
        Cavalier pion = new Cavalier("c1", "rouge");
        Position depart = new Position(3, 4);
        Position arrivee = new Position(1, 5);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementHabituel6(){
        Cavalier pion = new Cavalier("c1", "rouge");
        Position depart = new Position(1, 5);
        Position arrivee = new Position(2, 3);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementHabituelRiviere(){
        Cavalier pion = new Cavalier("c1", "rouge");
        Position depart = new Position(3, 4);
        Position arrivee = new Position(5, 5);
        assertTrue(pion.estValide(depart, arrivee));
    }





}
