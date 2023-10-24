package ca.codexcvm.ventes;

import ca.codexcvm.compagnie.Compagnie;
import ca.codexcvm.livres.Livre;
import ca.codexcvm.succursale.Succursale;

public class ApplicationVentes {
    public static void main(String[] args) {

        Compagnie compagnie = new Compagnie();
        Livre livre = new Livre();
        Succursale succursale = new Succursale();

        livre.setTitre("L'intelligence artificielle");
        livre.setPrixCoutant(19.99);

        succursale.setNoSuccursale(123456);
        succursale.setNomSuccursale("Montréal");


        System.out.println(compagnie.getNomCompagnie());
        System.out.println(succursale.getNoSuccursale());
        System.out.println(succursale.getNomSuccursale());
        System.out.println(livre.getTitre());
        System.out.println(livre.prixVendant());
    }
}
