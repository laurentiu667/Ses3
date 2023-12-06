package partie1;

import org.junit.jupiter.api.*;
import xiangqi.Roi;
import xiangqi.Position;

import static org.junit.jupiter.api.Assertions.*;
public class Roi_Test {
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

    // MOUVEMENT PERMIT
    @Test
    public void deplacementSurPlace(){
        Roi pion = new Roi("r1", "rouge");
        Position depart = new Position(8, 4);
        Position arrivee = new Position(8, 4);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementLigneEnAvant(){
        Roi pion = new Roi("r1", "rouge");
        Position depart = new Position(8, 4);
        Position arrivee = new Position(7, 4);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementLigneEnArriere(){
        Roi pion = new Roi("r1", "rouge");
        Position depart = new Position(8, 4);
        Position arrivee = new Position(9, 4);
        assertTrue(pion.estValide(depart, arrivee));
    }
    @Test
    public void deplacementLigneAdroite(){
        Roi roi = new Roi("r1", "rouge");
        Position depart = new Position(8, 4);
        Position arrivee = new Position(8, 5);
        assertTrue(roi.estValide(depart, arrivee));
    }
    @Test
    public void deplacementLigneAgauche(){
        Roi roi = new Roi("r1", "rouge");
        Position depart = new Position(8, 4);
        Position arrivee = new Position(8, 3);
        assertTrue(roi.estValide(depart, arrivee));
    }
    @Test
    public void deplacementLigneEnDiagonalHautDroite(){
        Roi roi = new Roi("r1", "rouge");
        Position depart = new Position(7, 3);
        Position arrivee = new Position(8, 4);
        assertTrue(roi.estValide(depart, arrivee));
    }
    @Test
    public void deplacementLigneEnDiagonalBasGauche(){
        Roi roi = new Roi("r1", "rouge");
        Position depart = new Position(8, 4);
        Position arrivee = new Position(7, 3);
        assertTrue(roi.estValide(depart, arrivee));
    }
    @Test // TEST PAS PERMIS
    public void deplacementLigneEnAvantDeuxCases(){
        Roi roi = new Roi("r1", "rouge");
        Position depart = new Position(9, 4);
        Position arrivee = new Position(7, 4);
        assertFalse(roi.estValide(depart, arrivee));
    }
    @Test // TEST PAS PERMIS
    public void deplacementSortieGaucheCadre(){
        Roi roi = new Roi("r1", "rouge");
        Position depart = new Position(9, 3);
        Position arrivee = new Position(9, 2);
        assertFalse(roi.estValide(depart, arrivee));
    }
    @Test // TEST PAS PERMIS
    public void deplacementSortieDroiteCadre(){
        Roi roi = new Roi("r1", "rouge");
        Position depart = new Position(9, 5);
        Position arrivee = new Position(9, 6);
        assertFalse(roi.estValide(depart, arrivee));
    }
    @Test // TEST PAS PERMIS
    public void deplacementSortieEnfaceDuCadre(){
        Roi roi = new Roi("r1", "rouge");
        Position depart = new Position(7, 4);
        Position arrivee = new Position(6, 4);
        assertFalse(roi.estValide(depart, arrivee));
    }
    @Test // TEST PAS PERMIS
    public void deplacementSortieEnDiagonalGaucheDuCadre(){
        Roi roi = new Roi("r1", "rouge");
        Position depart = new Position(2, 3);
        Position arrivee = new Position(3, 2);
        assertFalse(roi.estValide(depart, arrivee));
    }
    @Test // TEST PAS PERMIS
    public void deplacementSortieEnDiagonalDroiteDuCadre(){
        Roi roi = new Roi("r1", "rouge");
        Position depart = new Position(2, 5);
        Position arrivee = new Position(3, 6);
        assertFalse(roi.estValide(depart, arrivee));
    }
    @Test // TEST PAS PERMIS
    public void deplacementInterieurDiagonalDeuxCasesBasDroite(){
        Roi roi = new Roi("r1", "rouge");
        Position depart = new Position(9, 3);
        Position arrivee = new Position(7, 5);
        assertFalse(roi.estValide(depart, arrivee));
    }
    @Test // TEST PAS PERMIS
    public void deplacementInterieurDiagonalDeuxCasesHautGauche(){
        Roi roi = new Roi("r1", "rouge");
        Position depart = new Position(7, 5);
        Position arrivee = new Position(9, 3);
        assertFalse(roi.estValide(depart, arrivee));
    }
    @Test // TEST PAS PERMIS
    public void deplacementInterieurDiagonalDeuxCasesHautDroite(){
        Roi roi = new Roi("r1", "rouge");
        Position depart = new Position(7, 3);
        Position arrivee = new Position(9, 5);
        assertFalse(roi.estValide(depart, arrivee));
    }
    @Test // TEST PAS PERMIS
    public void deplacementInterieurDiagonalDeuxCasesBahGauche(){
        Roi roi = new Roi("r1", "rouge");
        Position depart = new Position(9, 5);
        Position arrivee = new Position(7, 3);
        assertFalse(roi.estValide(depart, arrivee));
    }

    // Rouge

    @Test
    public void RougedeplacementLigneEnAvant(){
        Roi roi = new Roi("r1", "noir");
        Position depart = new Position(1, 4);
        Position arrivee = new Position(2, 4);
        assertTrue(roi.estValide(depart, arrivee));
    }
    @Test
    public void RougedeplacementLigneEnArriere(){
        Roi roi = new Roi("r1", "noir");
        Position depart = new Position(1, 4);
        Position arrivee = new Position(0, 4);
        assertTrue(roi.estValide(depart, arrivee));
    }
    @Test
    public void RougedeplacementLigneAdroite(){
        Roi roi = new Roi("r1", "noir");
        Position depart = new Position(1, 4);
        Position arrivee = new Position(1, 5);
        assertTrue(roi.estValide(depart, arrivee));
    }
    @Test
    public void RougedeplacementLigneAgauche(){
        Roi roi = new Roi("r1", "noir");
        Position depart = new Position(1, 4);
        Position arrivee = new Position(1, 3);
        assertTrue(roi.estValide(depart, arrivee));
    }
    @Test
    public void RougedeplacementLigneEnDiagonalHautDroite(){
        Roi roi = new Roi("r1", "noir");
        Position depart = new Position(0, 3);
        Position arrivee = new Position(1, 4);
        assertTrue(roi.estValide(depart, arrivee));
    }
    @Test
    public void RougedeplacementLigneEnDiagonalBasGauche(){
        Roi roi = new Roi("r1", "noir");
        Position depart = new Position(1, 4);
        Position arrivee = new Position(0, 3);
        assertTrue(roi.estValide(depart, arrivee));
    }
    @Test // TEST PAS PERMIS
    public void RougedeplacementLigneEnAvantDeuxCases(){
        Roi roi = new Roi("r1", "noir");
        Position depart = new Position(0, 4);
        Position arrivee = new Position(2, 4);
        assertFalse(roi.estValide(depart, arrivee));
    }
    @Test // TEST PAS PERMIS
    public void RougedeplacementSortieGaucheCadre(){
        Roi roi = new Roi("r1", "noir");
        Position depart = new Position(0, 3);
        Position arrivee = new Position(0, 2);
        assertFalse(roi.estValide(depart, arrivee));
    }
    @Test // TEST PAS PERMIS
    public void RougedeplacementSortieDroiteCadre(){
        Roi roi = new Roi("r1", "noir");
        Position depart = new Position(0, 5);
        Position arrivee = new Position(0, 6);
        assertFalse(roi.estValide(depart, arrivee));
    }
    @Test // TEST PAS PERMIS
    public void RougedeplacementSortieEnfaceDuCadre(){
        Roi roi = new Roi("r1", "noir");
        Position depart = new Position(2, 4);
        Position arrivee = new Position(3, 4);
        assertFalse(roi.estValide(depart, arrivee));
    }
    @Test // TEST PAS PERMIS
    public void RougedeplacementSortieEnDiagonalGaucheDuCadre(){
        Roi roi = new Roi("r1", "noir");
        Position depart = new Position(2, 3);
        Position arrivee = new Position(3, 2);
        assertFalse(roi.estValide(depart, arrivee));
    }
    @Test // TEST PAS PERMIS
    public void RougedeplacementSortieEnDiagonalDroiteDuCadre(){
        Roi roi = new Roi("r1", "noir");
        Position depart = new Position(2, 5);
        Position arrivee = new Position(3, 6);
        assertFalse(roi.estValide(depart, arrivee));
    }
    @Test // TEST PAS PERMIS
    public void RougedeplacementInterieurDiagonalDeuxCasesBasDroite(){
        Roi roi = new Roi("r1", "noir");
        Position depart = new Position(2, 3);
        Position arrivee = new Position(0, 5);
        assertFalse(roi.estValide(depart, arrivee));
    }
    @Test // TEST PAS PERMIS
    public void RougedeplacementInterieurDiagonalDeuxCasesHautGauche(){
        Roi roi = new Roi("r1", "noir");
        Position depart = new Position(0, 5);
        Position arrivee = new Position(2, 3);
        assertFalse(roi.estValide(depart, arrivee));
    }
    @Test // TEST PAS PERMIS
    public void RougedeplacementInterieurDiagonalDeuxCasesHautDroite(){
        Roi roi = new Roi("r1", "noir");
        Position depart = new Position(0, 3);
        Position arrivee = new Position(2, 5);
        assertFalse(roi.estValide(depart, arrivee));
    }
    @Test // TEST PAS PERMIS
    public void RougedeplacementInterieurDiagonalDeuxCasesBahGauche(){
        Roi roi = new Roi("r1", "noir");
        Position depart = new Position(2, 5);
        Position arrivee = new Position(0, 3);
        assertFalse(roi.estValide(depart, arrivee));
    }

}
