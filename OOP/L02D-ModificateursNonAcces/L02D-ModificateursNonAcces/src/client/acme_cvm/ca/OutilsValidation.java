package client.acme_cvm.ca;

public class OutilsValidation {

    public static boolean longueurNomComplet(String prenom, String nom){
        return prenom.length() + nom.length() + 1 <= 40;
    }

    public static boolean ageLegal(int age){
        return age >= 18 && age <= 110;
    }

    public static boolean nasValide(String nas){
        boolean isValide = true;
        if (nas.length() == 9 && nas != null)
            try {
                Integer.parseInt(nas);
            } catch (NumberFormatException nfe){
                isValide = false; }
        return isValide;
    }

    public static boolean codePostalValide(String codePostal){
        boolean isValide = false;

        if (codePostal != null){
            if (codePostal.length() == 6) {
                if(     Character.isLetter(codePostal.charAt(0))
                    &&  Character.isLetter(codePostal.charAt(2))
                    &&  Character.isLetter(codePostal.charAt(4))
                    &&  Character.isDigit(codePostal.charAt(1))
                    &&  Character.isDigit(codePostal.charAt(3))
                    &&  Character.isDigit(codePostal.charAt(5))     )  {
                        isValide = true;
                }
            }
        }
        return isValide;
    }


}
