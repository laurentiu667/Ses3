package partie2;

import org.junit.jupiter.api.*;
import static org.junit.jupiter.api.Assertions.*;

import xiangqi.*;
import xiangqiPartie2.*;
public class Bombarde_Test2 {
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

    Echiquier echiquier = new Echiquier();

    String couleur1 = "noir";

    String couleur2 = "rouge";

    @Test
    public void verifBombarde(){
        echiquier.getIntersection(7,1).setPiece(new Bombarde("b1", couleur1));
        echiquier.getIntersection(7,4).setPiece(new Pion("p1", couleur2));
        echiquier.getIntersection(7,7).setPiece(new Pion("p2", couleur2));

        // Sauter une piece et manger une piece apres
        assertTrue(echiquier.cheminPossible(new Position(7,1), new Position(7,7)));
        // Sauter apres 2 piece impossible
        assertFalse(echiquier.cheminPossible(new Position(7,1), new Position(7,8)));
        // si aucune piece entre alors on peut pas car il y aucune piece entre
        echiquier.getIntersection(7,4).setPiece(null);
        assertFalse(echiquier.cheminPossible(new Position(7,1), new Position(7,7)));
        // Sauter une piece et arriver vers case libre
        assertTrue(echiquier.cheminPossible(new Position(7,1), new Position(7,8)));

        // Essayer d aller si aucune piece vers champ libre
        assertFalse(echiquier.cheminPossible(new Position(7,1), new Position(1,1)));
    }
}
