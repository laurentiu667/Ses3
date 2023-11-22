import org.junit.jupiter.api.*;
import xiangqi.Pion;
import xiangqi.Position;

import static org.junit.jupiter.api.Assertions.*;
public class test {
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

    // ROUGE - Avant la riviere

    // MOUVEMENT PERMIT
    @Test
    public void deplacementLigneEnAvant(){
        Pion pion = new Pion("p1", "rouge");
        Position depart = new Position(9, 4);
        Position arrivee = new Position(8, 4);
        assertTrue(pion.estValide(depart, arrivee));
    }
    // ROUGE -  Mouvement interdit
    @Test
    public void deplacementLigneEnArriere(){
        Pion pion = new Pion("p1", "rouge");
        Position depart = new Position(7, 0);
        Position arrivee = new Position(8, 0);
        assertFalse(pion.estValide(depart, arrivee));
    }

    @Test
    public void deplacementLigneADroite(){
        Pion pion = new Pion("p1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(7, 5);
        assertFalse(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementLigneAGauche(){
        Pion pion = new Pion("p1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(7, 3);
        assertFalse(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementLigneEnDiagonalDroite(){
        Pion pion = new Pion("p1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(6, 5);
        assertFalse(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementLigneEnDiagonalGauche(){
        Pion pion = new Pion("p1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(6, 3);
        assertFalse(pion.estValide(depart, arrivee));
    }

    // ROUGE - APRÈS LA RIVIÈRE
    @Test // Mouvement Permis
    public void deplacementLigneEnAvantApresRiviere(){
        Pion pion = new Pion("p1", "rouge");
        Position depart = new Position(4, 4);
        Position arrivee = new Position(3, 4);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test // Mouvement Permis
    public void deplacementLigneADroiteApresRiviere(){
        Pion pion = new Pion("p1", "rouge");
        Position depart = new Position(4, 4);
        Position arrivee = new Position(4, 5);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test // Mouvement Permis
    public void deplacementLigneAGaucheApresRiviere(){
        Pion pion = new Pion("p1", "rouge");
        Position depart = new Position(0, 4);
        Position arrivee = new Position(0, 3);
        assertTrue(pion.estValide(depart, arrivee));
    }


    // ROUGE -  Mouvement interdit
    @Test
    public void deplacementLigneEnArriereApresRiviere(){
        Pion pion = new Pion("p1", "rouge");
        Position depart = new Position(4, 4);
        Position arrivee = new Position(5, 4);
        assertFalse(pion.estValide(depart, arrivee));
    }

    @Test
    public void deplacementLigneEnDiagonalDroiteApresRiviere(){
        Pion pion = new Pion("p1", "rouge");
        Position depart = new Position(3, 4);
        Position arrivee = new Position(2, 5);
        assertFalse(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementLigneEnDiagonalGaucheApresRiviere(){
        Pion pion = new Pion("p1", "rouge");
        Position depart = new Position(3, 4);
        Position arrivee = new Position(2, 3);
        assertFalse(pion.estValide(depart, arrivee));
    }

    // NOIR - Avant la rivière

    // MOUVEMENT PERMIT
    @Test // Mouvement permis
    public void NoirdeplacementLigneEnAvant(){
        Pion pion = new Pion("p1", "noir");
        Position depart = new Position(4, 4);
        Position arrivee = new Position(5, 4);
        assertTrue(pion.estValide(depart, arrivee));
    }

    // NOIR -  Mouvement interdit
    @Test // Mouvement pas permis
    public void NoirdeplacementLigneEnArriere(){
        Pion pion = new Pion("p1", "noir");
        Position depart = new Position(1, 4);
        Position arrivee = new Position(0, 4);
        assertFalse(pion.estValide(depart, arrivee));
    }

    @Test // Mouvement pas permis
    public void NoirdeplacementLigneADroite(){
        Pion pion = new Pion("p1", "noir");
        Position depart = new Position(1, 4);
        Position arrivee = new Position(1, 5);
        assertFalse(pion.estValide(depart, arrivee));
    }

    @Test // Mouvement pas permis
    public void NoirdeplacementLigneAGauche(){
        Pion pion = new Pion("p1", "noir");
        Position depart = new Position(1, 4);
        Position arrivee = new Position(1, 3);
        assertFalse(pion.estValide(depart, arrivee));
    }

    @Test // Mouvement pas permis
    public void NoirdeplacementLigneEnDiagonalDroite(){
        Pion pion = new Pion("p1", "noir");
        Position depart = new Position(1, 4);
        Position arrivee = new Position(2, 5);
        assertFalse(pion.estValide(depart, arrivee));
    }

    @Test // Mouvement pas permis
    public void NoirdeplacementLigneEnDiagonalGauche(){
        Pion pion = new Pion("p1", "noir");
        Position depart = new Position(1, 4);
        Position arrivee = new Position(2, 3);
        assertFalse(pion.estValide(depart, arrivee));
    }

    // NOIR - APRÈS LA RIVIÈRE

    @Test // Mouvement pas permis
    public void NoirdeplacementLigneEnArriereApresRiviere(){
        Pion pion = new Pion("p1", "noir");
        Position depart = new Position(5, 4);
        Position arrivee = new Position(4, 4);
        assertFalse(pion.estValide(depart, arrivee));
    }

    @Test // Mouvement Permis
    public void NoirdeplacementLigneEnAvantApresRiviere(){
        Pion pion = new Pion("p1", "noir");
        Position depart = new Position(6, 4);
        Position arrivee = new Position(7, 4);
        assertTrue(pion.estValide(depart, arrivee));
    }

    @Test // Mouvement Permis
    public void NoirdeplacementLigneADroiteApresRiviere(){
        Pion pion = new Pion("p1", "noir");
        Position depart = new Position(5, 4);
        Position arrivee = new Position(5, 5);
        assertTrue(pion.estValide(depart, arrivee));
    }

    @Test // Mouvement Permis
    public void NoirdeplacementLigneAGaucheApresRiviere(){
        Pion pion = new Pion("p1", "noir");
        Position depart = new Position(9, 4);
        Position arrivee = new Position(9, 3);
        assertTrue(pion.estValide(depart, arrivee));
    }
}
