import jeu.Joueur;
import org.junit.jupiter.api.*;
import static org.junit.jupiter.api.Assertions.*;
public class JoueurTest {

    Joueur joueurTest;

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

    @BeforeEach
    public void initJoueur(){
        this.joueurTest = new Joueur("Laurentiu", 1000, 20, "Couteau", 2, "Diamant", 2);
    }

    @Test  // Test 1.
    public void testGetCredits(){
        assertEquals(1000, joueurTest.getCredits());
    }

    @Test
    public void testCoutAmeliorerArmure() {
        // Test 2.a
        assertEquals(30, joueurTest.coutAmeliorerArmure(10));

        // Test 2.b
        assertEquals(0, joueurTest.coutAmeliorerArmure(0));

        // Test 2.c
        assertEquals(30, joueurTest.coutAmeliorerArmure(-10));
    }

}
