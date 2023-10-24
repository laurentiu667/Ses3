package ca.codexcvm.succursale;

import ca.codexcvm.compagnie.TarificationCompagnie;
import ca.codexcvm.livres.Livre;

public class TarificationSuccursale {

    public double calculerPrixVendant(double prixSuccursale){
        Succursale succursale = new Succursale();

        return prixSuccursale * (1 + succursale.getMargeProfit());
    }
    
}
