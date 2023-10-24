package client.acme_cvm.ca;

public class OutilsValidation {

    static boolean longueurNomComplet(String nom, String prenom){
        if ((nom.length() + prenom.length() + 1) == 40){
            return true;
        }
        return false;
    }

    static boolean ageLegal(int age){
        if (age >= 18 && age <= 100){
            return true;
        }
        return false;
    }

    static boolean nasValide(String nas){
        try {
            Integer.parseInt(nas);
            return true;
        } catch(NumberFormatException e){
            return false;
        }
    }

    static boolean codePostalValide(String codePostal){



    }




}
