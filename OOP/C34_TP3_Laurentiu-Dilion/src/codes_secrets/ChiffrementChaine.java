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

    public String chiffrer(String chaineAchiffrer, int cleChiffrement) {
        if (cleChiffrement < -10 || cleChiffrement > 100) {
            return "";
        }
        StringBuilder chaineChiffree = new StringBuilder();
        char[] caracteres = chaineAchiffrer.toCharArray();
        for (int i = 0; i < caracteres.length; i++) {
            char caractere = caracteres[i];
            // Conversion du char en ASCII
            int codeASCII = (int) caractere;
            // Ajouter la clé de chiffrement
            int nouveauCodeASCII = codeASCII + cleChiffrement;
            // Reconvertir en caractère
            char caractereChiffre = (char) nouveauCodeASCII;
            // Concaténer les caractères
            chaineChiffree.append(caractereChiffre);
        }
        return chaineChiffree.toString();
    }
    public String dechiffrer(String chaineADechiffrer, int cleChiffrement) {
        StringBuilder chaineDechiffrer = new StringBuilder();
        if (cleChiffrement >= -10 && cleChiffrement <= 100) {
            for (char caractere : chaineADechiffrer.toCharArray()) {
                // Conversion du char en ASCII
                int codeASCII = (int) caractere;
                // Retirer la clé de chiffrement
                int nouveauCodeASCII = codeASCII - cleChiffrement;
                // Reconvertir en caractère
                char caractereDeChiffre = (char) nouveauCodeASCII;
                chaineDechiffrer.append(caractereDeChiffre);
            }
            return chaineDechiffrer.toString();
        } else {
            return "";
        }
    }

}
