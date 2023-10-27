import org.junit.jupiter.api.*;
import static org.junit.jupiter.api.Assertions.*;
import validations_speciales.Validation;

public class TestContractUn {

    @BeforeAll
    public static void setup() {
        System.out.println("===================");
        System.out.println("= DÉBUT DES TESTS =");
        System.out.println("===================");
    }

    @AfterAll
    public static void finTests() {

        System.out.println("=================");
        System.out.println("= FIN DES TESTS =");
        System.out.println("=================");
    }

    @AfterEach
    public void apresChaqueTest() {
        System.out.println("= Test complété =");
    }

    @Test
    public void testValidationCodeClientValide() {
        assertTrue(Validation.validerCodeClient("ABC12345678"));
    }
    @Test
    public void testValidationCodeClientValideAsterix() {
        assertTrue(Validation.validerCodeClient("ABC12345678*"));
    }
    @Test
    public void testValidationCodeClientValideHashTag() {
        assertTrue(Validation.validerCodeClient("XYZ98765432#"));
    }
    @Test
    public void testValidationCodeClientInvalide() {
        assertFalse(Validation.validerCodeClient("XYZ98765432# "));
    }
    @Test
    public void testValidationCodeClientInvalide2() {
        assertFalse(Validation.validerCodeClient("XY98765432# ")); // Sans le Z - 2 caractère au début
    }
    @Test
    public void testValidationCodeClientInvalide3() {
        assertFalse(Validation.validerCodeClient("XY9 8765432# ")); // Sans le Z - 2 caractère au début
    }
    @Test
    public void testValidationCodeClientInvalide4() {
        assertFalse(Validation.validerCodeClient("XY9Z8765432# ")); // Sans le Z - 2 caractère au début
    }

    @Test
    public void testValidationNumeroDeSerieValide() {
        assertTrue(Validation.validerNumeroDeSerie("DEF567890-G"));
    }
    @Test
    public void testValidationNumeroDeSerieValide2() {
        assertTrue(Validation.validerNumeroDeSerie("DEFBKSJL567890-G"));
    }

    @Test
    public void testValidationNumeroDeSerieInvalide() {
        assertFalse(Validation.validerNumeroDeSerie("PQR123456- "));
    }
    @Test
    public void testValidationNumeroDeSerieInvalide2() {
        assertFalse(Validation.validerNumeroDeSerie("PQR1234563-    ")); // 7 Chiffres et TAB
    }

    @Test
    public void testValidationTelephoneValideParentheses() {
        assertTrue(Validation.validerTelephone("(123)456-7890"));
    }

    @Test
    public void testValidationTelephoneValideSansSeparateurs() {
        assertTrue(Validation.validerTelephone("5469809808"));
    }

    @Test
    public void testValidationTelephoneValideTirets() {
        assertTrue(Validation.validerTelephone("234-345-0879"));
    }

    @Test
    public void testValidationTelephoneValideEspacesEtTirets() {
        assertTrue(Validation.validerTelephone("234 435-1237"));
    }


    // Problème dans le REGEX du numéro de téléphone
    @Test
    public void testValidationTelephoneValideCrochets() {
        assertTrue(Validation.validerTelephone("[514) 789-0123"));
    }

    @Test
    public void testValidationTelephoneValideCrochets2() {
        assertTrue(Validation.validerTelephone("[456] 689-3245"));
    }

    @Test
    public void testValidationTelephoneInvalideFormat() {
        assertFalse(Validation.validerTelephone("(1234) 567-8901")); // Mauvaise longueur
    }

    @Test
    public void testValidationTelephoneInvalideCaracteres() {
        assertFalse(Validation.validerTelephone("(12A) 456-7890")); // Caractères non numériques
    }

    @Test
    public void testValidationTelephoneInvalideParanthese() {
        assertFalse(Validation.validerTelephone("(123 567-8901")); // sans fermer le ()
    }

    @Test
    public void testValidationTelephoneInvalidechiffre() {
        assertFalse(Validation.validerTelephone("1245 456-7890")); // 4 Caractères début
    }
}