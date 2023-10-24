package ca.codexcvm.livres;

import ca.codexcvm.compagnie.TarificationCompagnie;
import ca.codexcvm.succursale.TarificationSuccursale;

public class Livre {
    TarificationCompagnie tarificationCompagnie = new TarificationCompagnie();
    TarificationSuccursale tarificationSuccursale = new TarificationSuccursale();
    private String titre;
    private double prixCoutant = 19.99;

    public String getTitre() {
        return titre;
    }

    public void setTitre(String titre) {
        this.titre = titre;
    }
    public void setPrixCoutant(double prixCoutant) {
        this.prixCoutant = prixCoutant;
    }

    public double prixSuccursale(){
        return tarificationCompagnie.calculerPrixSuccursale(this.prixCoutant);
    }

    public double prixVendant() {
        return  tarificationSuccursale.calculerPrixVendant(prixSuccursale());
    }


}
