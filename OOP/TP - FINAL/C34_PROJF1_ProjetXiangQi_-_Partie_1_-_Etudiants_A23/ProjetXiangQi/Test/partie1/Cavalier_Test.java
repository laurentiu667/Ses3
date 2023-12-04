package partie1;

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
        Cavalier cavalier = new Cavalier("c1", "rouge");
        Position depart = new Position(9, 1);
        Position arrivee = new Position(9, 1);
        assertTrue(cavalier.estValide(depart, arrivee));
    }
    @Test
    public void deplacementHabituel(){
        Cavalier cavalier = new Cavalier("c1", "rouge");
        Position depart = new Position(9, 1);
        Position arrivee = new Position(7, 0);
        assertTrue(cavalier.estValide(depart, arrivee));
    }
    @Test
    public void deplacementHabituel2(){
        Cavalier cavalier = new Cavalier("c1", "rouge");
        Position depart = new Position(9, 1);
        Position arrivee = new Position(7, 2);
        assertTrue(cavalier.estValide(depart, arrivee));
    }
    @Test
    public void deplacementHabituel3(){
        Cavalier cavalier = new Cavalier("c1", "rouge");
        Position depart = new Position(9, 1);
        Position arrivee = new Position(8, 3);
        assertTrue(cavalier.estValide(depart, arrivee));
    }
    @Test
    public void deplacementHabituel4(){
        Cavalier cavalier = new Cavalier("c1", "rouge");
        Position depart = new Position(6, 4);
        Position arrivee = new Position(8, 3);
        assertTrue(cavalier.estValide(depart, arrivee));
    }
    @Test
    public void deplacementHabituel5(){
        Cavalier cavalier = new Cavalier("c1", "rouge");
        Position depart = new Position(6, 4);
        Position arrivee = new Position(5, 2);
        assertTrue(cavalier.estValide(depart, arrivee));
    }
    @Test
    public void deplacementHabituel6(){
        Cavalier cavalier = new Cavalier("c1", "rouge");
        Position depart = new Position(6, 4);
        Position arrivee = new Position(8, 5);
        assertTrue(cavalier.estValide(depart, arrivee));
    }
    @Test
    public void deplacementHabituelRiviere(){
        Cavalier cavalier = new Cavalier("c1", "rouge");
        Position depart = new Position(6, 4);
        Position arrivee = new Position(4, 5);
        assertTrue(cavalier.estValide(depart, arrivee));
    }

    // NOIR

    @Test
    public void NoirdeplacementSurPlace(){
        Cavalier cavalier = new Cavalier("c1", "noir");
        Position depart = new Position(0, 1);
        Position arrivee = new Position(0, 1);
        assertTrue(cavalier.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementHabituel(){
        Cavalier cavalier = new Cavalier("c1", "noir");
        Position depart = new Position(0, 1);
        Position arrivee = new Position(2, 0);
        assertTrue(cavalier.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementHabituel2(){
        Cavalier cavalier = new Cavalier("c1", "noir");
        Position depart = new Position(0, 1);
        Position arrivee = new Position(2, 2);
        assertTrue(cavalier.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementHabituel3(){
        Cavalier cavalier = new Cavalier("c1", "noir");
        Position depart = new Position(0, 1);
        Position arrivee = new Position(1, 3);
        assertTrue(cavalier.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementHabituel4(){
        Cavalier cavalier = new Cavalier("c1", "noir");
        Position depart = new Position(2, 2);
        Position arrivee = new Position(3, 4);
        assertTrue(cavalier.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementHabituel5(){
        Cavalier cavalier = new Cavalier("c1", "noir");
        Position depart = new Position(3, 4);
        Position arrivee = new Position(1, 5);
        assertTrue(cavalier.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementHabituel6(){
        Cavalier cavalier = new Cavalier("c1", "noir");
        Position depart = new Position(1, 5);
        Position arrivee = new Position(2, 3);
        assertTrue(cavalier.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementHabituelRiviere(){
        Cavalier cavalier = new Cavalier("c1", "noir");
        Position depart = new Position(3, 4);
        Position arrivee = new Position(5, 5);
        assertTrue(cavalier.estValide(depart, arrivee));
    }

    // NOIR ET ROUGES

    @Test
    public void NoirdeplacementPasPermis(){
        Cavalier cavalier = new Cavalier("c1", "noir");
        Position depart = new Position(7, 2);
        Position arrivee = new Position(6, 2);
        assertFalse(cavalier.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementPasPermis2(){
        Cavalier cavalier = new Cavalier("c1", "noir");
        Position depart = new Position(7, 2);
        Position arrivee = new Position(6, 3);
        assertFalse(cavalier.estValide(depart, arrivee));
    }





}
