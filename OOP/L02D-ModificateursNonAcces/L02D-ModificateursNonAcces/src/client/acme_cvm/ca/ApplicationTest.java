package client.acme_cvm.ca;

public class ApplicationTest {
    public static void main(String[] args) {
        String prenom = "Patrick";
        String nom = "Webster";
        int age = 30;
        String nas = "123456789";
        String codePostal = "H0H0H0";


        if (OutilsValidation.longueurNomComplet(prenom, nom))
            System.out.println("Le nom complet " + prenom + " " + nom + " respecte la longueur maximale.");
        else
            System.out.println("Le nom complet " + prenom + " " + nom + " est trop long (max 40 caractères).");

        if (OutilsValidation.ageLegal(age))
            System.out.println("L'age, " + age + " ans, est valide.");
        else
            System.out.println("L'age, " + age + " ans, n'est pas valide (doit être entre 18 et 110 ans, inclusivement).");

        if (OutilsValidation.nasValide(nas))
            System.out.println("Le nas " + nas + " est valide");
        else
            System.out.println("Le nas " + nas + " n'est pas valide (doit être une suite de 9 chiffres sans espaces).");

        if (OutilsValidation.codePostalValide(codePostal))
            System.out.println("Le code postal " + codePostal + " est valide.");
        else
            System.out.println("Le code postal " + codePostal + " n'est pas valide (format A1A1A1, sans espaces).");
    }
}
