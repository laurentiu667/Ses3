package test_chaine;

import validations_speciales.Validation;

public class TestChaine {
    public static void main(String[] args) {

        String codeClient1 = "ABC12345678";
        String codeClient2 = "ABC12345678*";
        String codeClient3 = "XYZ98765432#";
        String codeClient4 = "XYZ98765432# ";
        String codeClient5 = "XY98765432# ";
        String codeClient6 = "XY9 8765432# ";
        String codeClient7 = "XY9Z8765432# ";

        boolean codeClientValide1 = Validation.validerCodeClient(codeClient1);
        boolean codeClientValide2 = Validation.validerCodeClient(codeClient2);
        boolean codeClientValide3 = Validation.validerCodeClient(codeClient3);
        boolean codeClientValide4 = Validation.validerCodeClient(codeClient4);
        boolean codeClientValide5 = Validation.validerCodeClient(codeClient5);
        boolean codeClientValide6 = Validation.validerCodeClient(codeClient6);
        boolean codeClientValide7 = Validation.validerCodeClient(codeClient7);

        System.out.println("Code Client 1 est : " + codeClientValide1);
        System.out.println("Code Client 2 est : " + codeClientValide2);
        System.out.println("Code Client 3 est : " + codeClientValide3);
        System.out.println("Code Client 4 est : " + codeClientValide4);
        System.out.println("Code Client 5 est : " + codeClientValide5);
        System.out.println("Code Client 6 est : " + codeClientValide6);
        System.out.println("Code Client 7 est : " + codeClientValide7);

        String numeroSerie1 = "DEF567890-G";
        String numeroSerie2 = "DEFBKSJL567890-G";
        String numeroSerie3 = "PQR123456- ";
        String numeroSerie4 = "PQR1234563-    ";

        boolean numeroSerieValide1 = Validation.validerNumeroDeSerie(numeroSerie1);
        boolean numeroSerieValide2 = Validation.validerNumeroDeSerie(numeroSerie2);
        boolean numeroSerieValide3 = Validation.validerNumeroDeSerie(numeroSerie3);
        boolean numeroSerieValide4 = Validation.validerNumeroDeSerie(numeroSerie4);

        System.out.println("Numéro de Série 1 est : " + numeroSerieValide1);
        System.out.println("Numéro de Série 2 est : " + numeroSerieValide2);
        System.out.println("Numéro de Série 3 est : " + numeroSerieValide3);
        System.out.println("Numéro de Série 4 est : " + numeroSerieValide4);

        String telephone1 = "(123)456-7890";
        String telephone2 = "5469809808";
        String telephone3 = "234-345-0879";
        String telephone4 = "234 435-1237";
        String telephone5 = "[514) 789-0123";
        String telephone6 = "[456] 689-3245";
        String telephone7 = "(1234) 567-8901";
        String telephone8 = "(12A) 456-7890";
        String telephone9 = "(123 567-8901";
        String telephone10 = "1245 456-7890";

        boolean telephoneValide1 = Validation.validerTelephone(telephone1);
        boolean telephoneValide2 = Validation.validerTelephone(telephone2);
        boolean telephoneValide3 = Validation.validerTelephone(telephone3);
        boolean telephoneValide4 = Validation.validerTelephone(telephone4);
        boolean telephoneValide5 = Validation.validerTelephone(telephone5);
        boolean telephoneValide6 = Validation.validerTelephone(telephone6);
        boolean telephoneValide7 = Validation.validerTelephone(telephone7);
        boolean telephoneValide8 = Validation.validerTelephone(telephone8);
        boolean telephoneValide9 = Validation.validerTelephone(telephone9);
        boolean telephoneValide10 = Validation.validerTelephone(telephone10);

        System.out.println("Téléphone 1 est : " + telephoneValide1);
        System.out.println("Téléphone 2 est : " + telephoneValide2);
        System.out.println("Téléphone 3 est : " + telephoneValide3);
        System.out.println("Téléphone 4 est : " + telephoneValide4);
        System.out.println("Téléphone 5 est : " + telephoneValide5);
        System.out.println("Téléphone 6 est : " + telephoneValide6);
        System.out.println("Téléphone 7 est : " + telephoneValide7);
        System.out.println("Téléphone 8 est : " + telephoneValide8);
        System.out.println("Téléphone 9 est : " + telephoneValide9);
        System.out.println("Téléphone 10 est : " + telephoneValide10);
    }
}
