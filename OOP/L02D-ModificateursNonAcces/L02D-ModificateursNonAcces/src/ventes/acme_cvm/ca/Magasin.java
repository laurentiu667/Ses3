package ventes.acme_cvm.ca;

public class Magasin {
    private static final String NOM_ENTREPRISE = "ACME CVM";
    private static final String ADRESSE_ENTREPRISE = "1 rue principale, Montréal, Québec H0H 0H0" ;
    private static final String NO_TPS = "123456789 RT 0001";
    private static final String NO_TVQ = "1234567890 TQ 0001";
    private static final double TAUX_TAXE_FED = 0.05;
    private static final double TAUX_TAXE_PROV = 0.09975;

    // Méthodes d'accès (getters)
    public static String getNomEntreprise() {
        return NOM_ENTREPRISE;    }
    public static String getAdresseEntreprise() {
        return ADRESSE_ENTREPRISE;    }
    public static String getNoTps() {
        return NO_TPS;    }
    public static String getNoTvq() {
        return NO_TVQ;    }
    public static double getTauxTaxeFed() {
        return TAUX_TAXE_FED;    }
    public static double getTauxTaxeProv() {
        return TAUX_TAXE_PROV;    }

}
