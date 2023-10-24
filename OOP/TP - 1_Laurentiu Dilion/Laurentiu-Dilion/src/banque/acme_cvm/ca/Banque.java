package banque.acme_cvm.ca;
public class Banque {

    private String nomBanque = "Banque Mondiale ACME CVM";

    private String adresseBanque = "1 rue Principae, Montreal, QC H0H0H0";

    private double tauxInteret = 0.015;

    public String getNomBanque(){
        return nomBanque;
    }

    public String getAdresseBanque(){
        return adresseBanque;
    }

    protected double getTauxInteret(){
        return tauxInteret;
    }

}
