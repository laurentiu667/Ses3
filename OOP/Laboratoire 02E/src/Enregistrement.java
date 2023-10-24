public class Enregistrement {

    private String nomUsager;
    private String mdp;
    private String courriel;

    public Enregistrement(String nomUsager, String motDePasse, String courriel) {
        if (verifNom(nomUsager) && verifMdp(motDePasse) && verifCourriel(courriel)) {
            this.nomUsager = nomUsager;
            this.mdp = motDePasse;
            this.courriel = courriel;
            System.out.println("Enregistrement réussi.");
        } else {
            System.out.println("Échec de l'enregistrement. Veuillez fournir des données valides.");
        }
    }
    public String getNomUsager() {
        return nomUsager;
    }

    public String getMdp() {
        return mdp;
    }

    public String getCourriel() {
        return courriel;
    }



}
