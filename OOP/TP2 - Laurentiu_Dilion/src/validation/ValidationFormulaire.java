package validation;

public class ValidationFormulaire {

    public static boolean validerNom(String nom) {
        return nom.matches("^[a-zA-Z\\-]+$");
    }

    public static boolean validerNumero(String num) {
        return num.matches("^[a-zA-Z0-9]+$");
    }

    public static boolean validerSalaireHoraire(double salaire) {
        return salaire >= 15.25;
    }

    public static boolean validerNbreHeuresSemaine(double nombre_dheure_semaine) {
        return nombre_dheure_semaine >= 1 && nombre_dheure_semaine <= 80;
    }

    public static boolean validerAnciennete(int anciennete) {
        return anciennete >= 0 ;
    }

    public static boolean validerEmploye(String nom, String numero, double salaireHoraire, double nbreHeuresSemaine, int anciennete) {

        boolean v1 = validerNom(nom);
        boolean v2 = validerNumero(numero);
        boolean v3 = validerSalaireHoraire(salaireHoraire);
        boolean v4 = validerNbreHeuresSemaine(nbreHeuresSemaine);
        boolean v5 = validerAnciennete(anciennete);

        boolean[] validation_total = {v1, v2, v3, v4 ,v5};

        for (int i = 0; i <= validation_total.length - 1; i++){

            if (!validation_total[i]){
                return false;
            }
        }
        return true;

    }

}
