package jeu;

public class Joueur {
    private String alias;  // Nom d'affichage du joueur
    private int credits;	// Monnaie du jeu, peut améliorer l'arme
    private int gemmes;		// Autre monnaie du jeu, peut améliorer l'armure
    private String nomArme;  // Nom de l'arme du joueur
    private int niveauArme;  // Niveau actuel de l'arme du joueur
    private String nomArmure;  // Nom de l'armure du joueur
    private int niveauArmure;  // Niveau actuel de l'armure du joueur

    // Constructeur par défaut
    public Joueur(){}

    // Constructeur - tous paramètres
    public Joueur(String alias, int credits, int gemmes, String nomArme, int niveauArme, String nomArmure, int niveauArmure){
        this.alias = alias;
        this.credits = credits;
        this.gemmes = gemmes;
        this.nomArme = nomArme;
        this.niveauArme = niveauArme;
        this.nomArmure = nomArmure;
        this.niveauArmure = niveauArmure;
    }

    // Méthodes d'accès
    public String getAlias() { return alias; }
    public int getCredits() { return credits; }
    public int getGemmes() { return gemmes; }
    public String getNomArme() { return nomArme; }
    public int getNiveauArme() { return niveauArme; }
    public String getNomArmure() { return nomArmure; }
    public int getNiveauArmure() { return niveauArmure; }

    // Méthodes de mutation
    public void setAlias(String alias) { this.alias = alias; }
    public void setCredits(int credits) { this.credits = credits; }
    public void setGemmes(int gemmes) { this.gemmes = gemmes; }
    public void setNomArme(String nomArme) { this.nomArme = nomArme; }
    public void setNiveauArme(int niveauArme) { this.niveauArme = niveauArme; }
    public void setNomArmure(String nomArmure) { this.nomArmure = nomArmure; }
    public void setNiveauArmure(int niveauArmure) { this.niveauArmure = niveauArmure; }

    // Cout en crédits pour améliorer l'arme d'un niveau
    // Reçoit en paramètre le niveau de départ
    public int coutAmeliorerArme(int niveau){
        return (int)(0.4 * niveau * niveau);
    }

    // Cout en gemmes pour améliorer l'armure d'un niveau
    // Reçoit en paramètre le niveau de départ
    public int coutAmeliorerArmure(int niveau){
        return (int)(0.3 * niveau * niveau);
    }

    // Améliore l'arme de 1 niveau avec des crédits
    // Si suffisamment de crédits, améliore arme, déduits crédits et retourne true, sinon retourne false
    public boolean ameliorerArme() {
        if (this.credits >= coutAmeliorerArme(this.niveauArme)) {
            this.credits -= coutAmeliorerArme(this.niveauArme);
            niveauArme++;
            return true;
        } else {
            return false;
        }
    }

    // Améliore l'armure de 1 niveau avec des gemmes
    // Si suffisamment de gemmes, améliore armure, déduits gemmes et retourne true, sinon retourne false
    public boolean ameliorerArmure(){
        if (this.gemmes >= coutAmeliorerArmure(this.niveauArmure)){
            this.gemmes -= coutAmeliorerArmure(this.niveauArmure);
            niveauArmure++;
            return true;
        }
        else{
            return false;
        }
    }
}
