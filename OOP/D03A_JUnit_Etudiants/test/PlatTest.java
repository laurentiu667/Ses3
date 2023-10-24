import org.junit.jupiter.api.*;

import static org.junit.jupiter.api.Assertions.*;

import plats_prepares.Plat;
import plats_prepares.Plat.*;

public class PlatTest {
    Plat platTest;
    @Test
    public void testNomEstValide(){
        assertEquals(true, this.platTest.isNomValide("Lasagne"));
    }

    @BeforeEach
    public void avantChaqueTest(){
        platTest = new Plat("Lasagne", 430, 350, 40 ,7.92, 9.99);
    }

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
    public void testSetPrix(){
        this.platTest.setPrix(11.99);
        assertEquals(11.99, this.platTest.getPrix());
    }


}

