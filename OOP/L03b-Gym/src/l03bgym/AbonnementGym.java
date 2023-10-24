package l03bgym;

public class AbonnementGym {

    private String nomMembre;
    private double prix;
    private int nbJours;


    public AbonnementGym(String nomMembre){
        this.nomMembre = nomMembre;
        prix = 41.25;
        nbJours = 30;
    }

    public AbonnementGym(String nomMembre, int nbJours){
        this.nomMembre = nomMembre;
        this.nbJours = nbJours;
        prix = 8.25 * nbJours;
    }

    public AbonnementGym(String nomMembre, int nbJours, double prix){
        this.nomMembre = nomMembre;
        this.nbJours = nbJours;
        this.prix = prix;
    }

    public String getNomMembre()
    {
        return nomMembre;
    }

    public double getPrix()
    {
        return prix;
    }

    public int getNbJours()
    {
        return nbJours;
    }

    public void setPrix(double prix)
    {
        this.prix = prix;
    }
}
