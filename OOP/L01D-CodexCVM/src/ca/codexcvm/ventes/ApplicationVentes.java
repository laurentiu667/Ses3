package ca.codexcvm.ventes;

import ca.codexcvm.compagnie.Compagnie;
import ca.codexcvm.livres.Livre;
import ca.codexcvm.succursale.Succursale;
import ca.codexcvm.succursale.TarificationSuccursale;


public class ApplicationVentes {

    public static void main(String[] args) {

        // On créé un objet Compagnie et un objet livre
        Compagnie compagnie = new Compagnie();
        Livre livre = new Livre();
        Succursale succursale = new Succursale();
        TarificationSuccursale tarificationSuccursale = new TarificationSuccursale();

        System.out.println(compagnie.getNomCompagnie());
        livre.setTitre("L’intelligence artificielle");




        succursale.setNoSuccursale(123456);
        succursale.setNomSuccursale("Montreal");
        System.out.println( succursale.getNoSuccursale());
        System.out.println( succursale.getNomSuccursale());
        System.out.println(livre.getTitre());
        System.out.println(livre.prixVendant());



    }
}
