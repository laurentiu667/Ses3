package ca.codexcvm.livres;
import ca.codexcvm.compagnie.TarificationCompagnie;
import ca.codexcvm.succursale.TarificationSuccursale;

public class Livre {
    private String titre;
    private double prixCoutant;

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
        TarificationCompagnie tarificationCompagnie = new TarificationCompagnie();
        return tarificationCompagnie.calculerPrixSuccursale(this.prixCoutant);
    }

    public double prixVendant(){
        TarificationSuccursale tarificationSuccursale = new TarificationSuccursale();
        return tarificationSuccursale.calculerPrixVendant(prixSuccursale());
    }

}
