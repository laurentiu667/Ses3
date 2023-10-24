package ventes.acme_cvm.ca;

public class Facture {
    // Champs
    private static int nbreClients;
    private static double ventesCourantes;
    private static int noFactureCourant;
    private int noFacture;
    private double sousTotal;
    private double taxeFed;
    private double taxeProv;
    private double total;

    // Méthodes d'accès (getters)

    public static int getNbreClients() {
        return nbreClients;    }
    public static double getVentesCourantes() {
        return ventesCourantes;    }
    public static int getNoFactureCourant() {
        return noFactureCourant;    }
    public int getNoFacture() {
        return noFacture;    }
    public double getSousTotal() {
        return sousTotal;    }
    public double getTotal() {
        return total;   }
    public double getTaxeFed() {
        return taxeFed; }
    public double getTaxeProv() {
        return taxeProv;    }

    // Méthodes de mutation (setters)
    public static void setNbreClients(int nbreClients) {
        Facture.nbreClients = nbreClients;  }
    public static void setNoFactureCourant(int noFactureCourant) {
        Facture.noFactureCourant = noFactureCourant;    }
    public static void setVentesCourantes(double ventesCourantes) {
        Facture.ventesCourantes = ventesCourantes;    }

    public void setFacture(double sousTotal){
        this.sousTotal = sousTotal;
        this.taxeFed = sousTotal * Magasin.getTauxTaxeFed();
        this.taxeProv = sousTotal * Magasin.getTauxTaxeProv();
        this.total = sousTotal + this.taxeFed + this.taxeProv;
        this.noFacture = this.getNoFactureCourant();
        nbreClients += 1;
        ventesCourantes += this.total;
        noFactureCourant +=1;
    }

}
