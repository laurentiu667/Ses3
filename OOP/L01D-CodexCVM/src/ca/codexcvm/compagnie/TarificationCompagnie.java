package ca.codexcvm.compagnie;

import ca.codexcvm.succursale.Succursale;
import ca.codexcvm.succursale.TarificationSuccursale;

public class TarificationCompagnie {
    TarificationSuccursale tarificationSuccursale = new TarificationSuccursale();
    public double calculerPrixSuccursale(double prixCoutant) {
        Compagnie compagnie = new Compagnie();

        // Creez une variable pour la classe Compagnie pour ensuite utiliser getMargeProfit

        return prixCoutant * (1 + compagnie.getMargeProfit() );
    }
}