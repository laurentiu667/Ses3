package banque.acme_cvm.ca;

public class CompteBancaire {

    private int noCompte;
    private String typeCompte;
    private int noClient;
    private double solde;
    private double limiteRetrait = 500;

    public int getNoCompte(){
        return noCompte;
    }
    public String getTypeCompte(){
        return typeCompte;
    }
    public int getNoClient(){
        return noClient;
    }
    public double getSolde(){
        return solde;
    }public double getLimiteRetrait(){
        return limiteRetrait;
    }

    public void setCompte(int noCompte, String typeCompte, int noClient, double solde, double limiteRetrait) {
        this.noCompte = noCompte;
        this.typeCompte = typeCompte;
        this.noClient = noClient;
        this.solde = solde;
        this.limiteRetrait = limiteRetrait;
    }

    public int retrait(double montant) {
        if (this.solde >= montant && montant < this.limiteRetrait && montant >= 0.0) {
            this.solde -= montant;
            return -1;
        } else {
            return 0;
        }
    }

    public int depot(double montant) {
        if (montant < 50000.0 && montant >= 0.0) {
            this.solde += montant;
            return -1;
        } else {

            return 0;
        }
    }

    public int versetInteret(){
        if (this.typeCompte != "Épargne") {
            return -1;
        }
        else {
            Banque banque = new Banque();
            this.solde += ((banque.getTauxInteret() / 12) * this.solde);
            return 0;
        }
    }
}
