package test_chaine;

import validations_speciales.Validation;

public class TestChaine {
    public static void main(String[] args) {

        String codeClient1 = "ABC12345678";
        String codeClient2 = "XYZ98765432#";

        String numeroSerie1 = "DEF567890-G";
        String numeroSerie2 = "PQR123456- ";

        String telephone1 = "0000000000";
        String telephone2 = "000-000-0000";
        String telephone3 = "000 000-0000";
        String telephone4 = "000 000 0000";
        String telephone5 = "(000)000-0000";
        String telephone6 = "(000) 000-0000";
        String telephone7 = "[000]000-0000";
        String telephone8 = "[456] 789-0123";


        boolean codeClientValide1 = Validation.validerCodeClient(codeClient1);
        boolean codeClientValide2 = Validation.validerCodeClient(codeClient2);

        boolean numeroSerieValide1 = Validation.validerNumeroDeSerie(numeroSerie1);
        boolean numeroSerieValide2 = Validation.validerNumeroDeSerie(numeroSerie2);

        boolean telephoneValide1 = Validation.validerTelephone(telephone1);
        boolean telephoneValide2 = Validation.validerTelephone(telephone2);
        boolean telephoneValide3 = Validation.validerTelephone(telephone3);
        boolean telephoneValide4 = Validation.validerTelephone(telephone4);
        boolean telephoneValide5 = Validation.validerTelephone(telephone5);
        boolean telephoneValide6 = Validation.validerTelephone(telephone6);
        boolean telephoneValide7 = Validation.validerTelephone(telephone7);
        boolean telephoneValide8 = Validation.validerTelephone(telephone8);

        System.out.println("Code Client 1 est : " + codeClientValide1);
        System.out.println("Code Client 2 est : " + codeClientValide2);

        System.out.println("Numéro de Série 1 est : " + numeroSerieValide1);
        System.out.println("Numéro de Série 2 est : " + numeroSerieValide2);

        System.out.println("Téléphone 1 est : " + telephoneValide1);
        System.out.println("Téléphone 2 est : " + telephoneValide2);
        System.out.println("Téléphone 3 est : " + telephoneValide3);
        System.out.println("Téléphone 4 est : " + telephoneValide4);
        System.out.println("Téléphone 5 est : " + telephoneValide5);
        System.out.println("Téléphone 6 est : " + telephoneValide6);
        System.out.println("Téléphone 7 est : " + telephoneValide7);
        System.out.println("Téléphone 8 est : " + telephoneValide8);
    }
}
