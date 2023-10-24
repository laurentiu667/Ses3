package vehicule;

public class GestionnaireVehicule {

    public static void main(String[] args) {
        modele m1 = new modele();
        modele m2 = new modele();

        m1.idModel = "hocrv02";
        m1.marque = "Honda";
        m1.modeleMarque = "CRV-LX";

        m2.idModel = "hocrv02";
        m2.marque = "Hyundai";
        m2.modeleMarque = "Santa Fe-Urban ";
        ////////////////////////////////////
        ItemInventaire iv1 = new ItemInventaire();
        ItemInventaire iv2 = new ItemInventaire();

        iv1.idItemInventaire = "aut000011";
        iv1.idModel = "hocrv02";
        iv1.prixSuggerer = 34000;

        iv2.idItemInventaire = "aut320057";
        iv2.idModel = "husan04";
        iv2.prixSuggerer = 38000;


        ItemInventaire a = new ItemInventaire();
        System.out.println("LISTES DES MODELES");
        System.out.println("ID du modele = " + m1.idModel + ", Marque = " + m1.marque + ", Nom du modele = " + m1.modeleMarque);
        System.out.println("ID du modele = " + m2.idModel + ", Marque = " + m2.marque + ", Nom du modele = " + m2.modeleMarque);

        System.out.println("\nLISTES DES MODELES");
        System.out.println("ID de l inventaire = " + iv1.idItemInventaire + ", ID du modele = " + iv1.idModel + ", prix suggerer = " + iv1.prixSuggerer);
        System.out.println("ID de l inventaire = " + iv2.idItemInventaire + ", ID du modele = " + iv2.idModel + ", prix suggerer = " + iv2.prixSuggerer);
    }

}
