package partie1;

import org.junit.jupiter.api.*;
import xiangqi.Mandarin;
import xiangqi.Position;

import static org.junit.jupiter.api.Assertions.*;
public class Mandarin_Test {
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
        Mandarin mandarin = new Mandarin("m1", "rouge");
        Position depart = new Position(8, 4);
        Position arrivee = new Position(8, 4);
        assertTrue(mandarin.estValide(depart, arrivee));
    }
    @Test
    public void deplacementLigneEnDiagonal(){
        Mandarin mandarin = new Mandarin("m1", "rouge");
        Position depart = new Position(8, 4);
        Position arrivee = new Position(7, 5);
        assertTrue(mandarin.estValide(depart, arrivee));
    }
    @Test
    public void deplacementLigneEnDiagonal2(){
        Mandarin mandarin = new Mandarin("m1", "rouge");
        Position depart = new Position(8, 4);
        Position arrivee = new Position(9, 3);
        assertTrue(mandarin.estValide(depart, arrivee));
    }
    @Test
    public void deplacementLigneEnDiagonal3(){
        Mandarin mandarin = new Mandarin("m1", "rouge");
        Position depart = new Position(8, 4);
        Position arrivee = new Position(7, 3);
        assertTrue(mandarin.estValide(depart, arrivee));
    }
    @Test
    public void deplacementLigneEnDiagonal4(){
        Mandarin mandarin = new Mandarin("m1", "rouge");
        Position depart = new Position(8, 4);
        Position arrivee = new Position(9, 5);
        assertTrue(mandarin.estValide(depart, arrivee));
    }

    // MOUVEMENT INTERDIT EN AVANT

    @Test
    public void deplacementLigneEnAvant(){
        Mandarin mandarin = new Mandarin("m1", "rouge");
        Position depart = new Position(8, 4);
        Position arrivee = new Position(7, 4);
        assertFalse(mandarin.estValide(depart, arrivee));
    }
    @Test
    public void deplacementLigneEnAvant2(){
        Mandarin mandarin = new Mandarin("m1", "rouge");
        Position depart = new Position(8, 4);
        Position arrivee = new Position(8, 3);
        assertFalse(mandarin.estValide(depart, arrivee));
    }
    @Test
    public void deplacementLigneEnAvant3(){
        Mandarin mandarin = new Mandarin("m1", "rouge");
        Position depart = new Position(8, 4);
        Position arrivee = new Position(8, 5);
        assertFalse(mandarin.estValide(depart, arrivee));
    }
    @Test
    public void deplacementLigneEnAvant4(){
        Mandarin mandarin = new Mandarin("m1", "rouge");
        Position depart = new Position(8, 4);
        Position arrivee = new Position(9, 4);
        assertFalse(mandarin.estValide(depart, arrivee));
    }
    @Test
    public void deplacementLigneEnDiagonal2Plus(){
        Mandarin mandarin = new Mandarin("m1", "rouge");
        Position depart = new Position(8, 4);
        Position arrivee = new Position(6, 2);
        assertFalse(mandarin.estValide(depart, arrivee));
    }
    @Test
    public void deplacementLigneEnDiagonal2PlusAutre(){
        Mandarin mandarin = new Mandarin("m1", "rouge");
        Position depart = new Position(8, 4);
        Position arrivee = new Position(6, 6);
        assertFalse(mandarin.estValide(depart, arrivee));
    }
    @Test
    public void deplacementLigneEnLigne2Plus(){
        Mandarin mandarin = new Mandarin("m1", "rouge");
        Position depart = new Position(8, 4);
        Position arrivee = new Position(8, 2);
        assertFalse(mandarin.estValide(depart, arrivee));
    }
    @Test
    public void deplacementLigneEnLigne2PlusAutre(){
        Mandarin mandarin = new Mandarin("m1", "rouge");
        Position depart = new Position(8, 4);
        Position arrivee = new Position(8, 6);
        assertFalse(mandarin.estValide(depart, arrivee));
    }
    @Test
    public void deplacementLigneEnLigne2PlusAutre2(){
        Mandarin mandarin = new Mandarin("m1", "rouge");
        Position depart = new Position(8, 4);
        Position arrivee = new Position(8, 2);
        assertFalse(mandarin.estValide(depart, arrivee));
    }


     // NOIR
     // MOUVEMENT PERMIT
    @Test
    public void NoirdeplacementSurPlace(){
        Mandarin mandarin = new Mandarin("m1", "noir");
        Position depart = new Position(1, 4);
        Position arrivee = new Position(1, 4);
        assertTrue(mandarin.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementLigneEnDiagonal(){
        Mandarin mandarin = new Mandarin("m1", "noir");
        Position depart = new Position(1, 4);
        Position arrivee = new Position(2, 5);
        assertTrue(mandarin.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementLigneEnDiagonal2(){
        Mandarin mandarin = new Mandarin("m1", "noir");
        Position depart = new Position(1, 4);
        Position arrivee = new Position(2, 3);
        assertTrue(mandarin.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementLigneEnDiagonal3(){
        Mandarin mandarin = new Mandarin("m1", "noir");
        Position depart = new Position(1, 4);
        Position arrivee = new Position(0, 3);
        assertTrue(mandarin.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementLigneEnDiagonal4(){
        Mandarin mandarin = new Mandarin("m1", "noir");
        Position depart = new Position(1, 4);
        Position arrivee = new Position(0, 5);
        assertTrue(mandarin.estValide(depart, arrivee));
    }

    // MOUVEMENT INTERDIT EN AVANT

    @Test
    public void NoirdeplacementLigneEnAvant(){
        Mandarin mandarin = new Mandarin("m1", "noir");
        Position depart = new Position(1, 4);
        Position arrivee = new Position(2, 4);
        assertFalse(mandarin.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementLigneEnAvant2(){
        Mandarin mandarin = new Mandarin("m1", "noir");
        Position depart = new Position(1, 4);
        Position arrivee = new Position(1, 3);
        assertFalse(mandarin.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementLigneEnAvant3(){
        Mandarin mandarin = new Mandarin("m1", "noir");
        Position depart = new Position(1, 4);
        Position arrivee = new Position(1, 5);
        assertFalse(mandarin.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementLigneEnAvant4(){
        Mandarin mandarin = new Mandarin("m1", "noir");
        Position depart = new Position(1, 4);
        Position arrivee = new Position(0, 4);
        assertFalse(mandarin.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementLigneEnDiagonal2Plus(){
        Mandarin mandarin = new Mandarin("m1", "noir");
        Position depart = new Position(8, 4);
        Position arrivee = new Position(6, 2);
        assertFalse(mandarin.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementLigneEnDiagonal2PlusAutre(){
        Mandarin mandarin = new Mandarin("m1", "noir");
        Position depart = new Position(1, 4);
        Position arrivee = new Position(3, 6);
        assertFalse(mandarin.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementLigneEnLigne2Plus(){
        Mandarin mandarin = new Mandarin("m1", "noir");
        Position depart = new Position(1, 4);
        Position arrivee = new Position(3, 2);
        assertFalse(mandarin.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementLigneEnLigne2PlusAutre(){
        Mandarin mandarin = new Mandarin("m1", "noir");
        Position depart = new Position(1, 4);
        Position arrivee = new Position(1, 6);
        assertFalse(mandarin.estValide(depart, arrivee));
    }
    @Test
    public void NoirdeplacementLigneEnLigne2PlusAutre2(){
        Mandarin mandarin = new Mandarin("m1", "noir");
        Position depart = new Position(1, 4);
        Position arrivee = new Position(1, 2);
        assertFalse(mandarin.estValide(depart, arrivee));
    }

}
