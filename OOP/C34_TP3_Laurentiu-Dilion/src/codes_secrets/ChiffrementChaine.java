package codes_secrets;

public class ChiffrementChaine {

    private int cleChiffrement;
    private String chaineAChiffrer;
    private String chaineADechiffrer;
    public int getCleChiffrement() {
        return cleChiffrement;
    }
    public String getChaineAChiffrer() {
        return chaineAChiffrer;
    }

    public String getChaineADechiffrer() {
        return chaineADechiffrer;
    }

    public void setCleChiffrement(int cleChiffrement) {
        this.cleChiffrement = cleChiffrement;
    }
    public void setChaineAChiffrer(String chaineAChiffrer) {
        this.chaineAChiffrer = chaineAChiffrer;
    }
    public void setChaineADechiffrer(String chaineADechiffrer) {
        this.chaineADechiffrer = chaineADechiffrer;
    }

    public ChiffrementChaine() {
        this.cleChiffrement = 10;
        this.chaineAChiffrer = "";
    }
    public ChiffrementChaine(int cleChiffrement) {
        if (cleChiffrement >= -10 && cleChiffrement <= 100) {
            this.cleChiffrement = cleChiffrement;
        } else {
            this.cleChiffrement = -1000;
        }
        this.chaineAChiffrer = "";
    }

    public static String chiffrer(String chaineAchiffrer, int cleChiffrement) {
        if (cleChiffrement < -10 || cleChiffrement > 100) {
            return "";
        }
        StringBuilder chaineChiffree = new StringBuilder();
        for (char caractere : chaineAchiffrer.toCharArray()) {
            char caractereDeChiffre = (char) ((int) caractere + cleChiffrement);
            chaineChiffree.append(caractereDeChiffre);
        }
        return chaineChiffree.toString();
    }

    public static String chiffrer(String chaineAChiffrer){
        int cle = 10;
        return chiffrer(chaineAChiffrer, cle);
    }

    public static String dechiffrer(String chaineADechiffrer, int cleChiffrement) {
        StringBuilder chaineDechiffrer = new StringBuilder();
        if (cleChiffrement >= -10 && cleChiffrement <= 100) {
            for (char caractere : chaineADechiffrer.toCharArray()) {
                char caractereDeChiffre = (char) ((int) caractere - cleChiffrement);
                chaineDechiffrer.append(caractereDeChiffre);
            }
            return chaineDechiffrer.toString();
        } else {
            return "";
        }
    }
    public static String dechiffrer(int cleChiffrement ,String chaineADechiffrer){
        return dechiffrer(chaineADechiffrer, cleChiffrement);
    }

}
