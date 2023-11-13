package projetheritagemaison;

public class Chalet extends Maison{

    private boolean electricite;
    private boolean accesLac;

    public Chalet (int nbrePieces, double superficieTerrain, String noAdresse, String nomRue,  double prixVente, boolean electricite, boolean accesLac )
    {
        super ( nbrePieces, superficieTerrain, noAdresse, nomRue, prixVente);
        this.electricite = electricite ;
        this.accesLac = accesLac;
    }

    public boolean isElectricite() {
        return electricite;
    }

    public void setElectricite(boolean electricite) {
        this.electricite = electricite;
    }

    public boolean isAccesLac() {
        return accesLac;
    }



    public double valeur()
    {
        double valeur = super.valeur()*0.75;

        if ( electricite)
            valeur *=1.1;
        if ( accesLac )
            valeur+= 5000;
        return valeur;
    }

}
