package employes.acme_cvm.ca;

public class Employe {
    private String nomComplet;
    private double salaire;
    private int anneeEmbauche;

    public void setNomComplet(String nomComplet) {
        this.nomComplet = nomComplet;
    }

    public void setSalaire(double salaire) {
        this.salaire = salaire;
    }

    public void setAnneeEmbauche(int anneeEmbauche) {
        this.anneeEmbauche = anneeEmbauche;
    }

    public String getNomComplet() {
        return nomComplet;
    }

    public double getSalaire() {
        return salaire;
    }

    public int getAnneeEmbauche() {
        return anneeEmbauche;
    }

    public int ancienneteParAnneeCible(int anneeCible){
        return anneeCible - this.anneeEmbauche;
    }

    public int anneeCiblePourAnciennete(int anciennete){
        return anneeEmbauche + anciennete;
    }



}
