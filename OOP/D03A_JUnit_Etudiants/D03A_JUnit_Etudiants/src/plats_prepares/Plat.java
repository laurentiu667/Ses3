package plats_prepares;

public class Plat {
    private String nom;
    private int nbGrammes;
    private int degresCuisson;
    private int minutesCuisson;
    private double cout;
    private double prix;
    private double profit;

    // Constructeurs
    public Plat() {}

    public Plat(String nom, int nbGrammes, int degresCuisson, int minutesCuisson, double cout, double prix){
        if (isNomValide(nom) && isNbGrammesValide(nbGrammes) && isMinutesCuissonValide(minutesCuisson) && isDegresCuissonValide(degresCuisson)) {
            this.nom = nom;
            this.nbGrammes = nbGrammes;
            this.degresCuisson = degresCuisson;
            this.minutesCuisson = minutesCuisson;
            this.cout = cout;
            this.prix = prix;
            this.profit = calculerProfit();
        }
        else{  // Si l'entrée des informations n'est pas valide, initialiser tous les champs à 0
            this.nom = "";
            this.nbGrammes = 0;
            this.degresCuisson = 0;
            this.minutesCuisson = 0;
            this.cout = 0.0;
            this.prix = 0.0;
            this.profit = calculerProfit();
        }
    }


    // Méthodes d'accès
    public String getNom() { return nom; }
    public int getNbGrammes() { return nbGrammes; }
    public int getDegresCuisson() { return degresCuisson; }
    public int getMinutesCuisson() { return minutesCuisson; }
    public double getPrix() { return prix; }

    // Méthode de mutation
    public void setPrix(double prix) { this.prix = prix; };

    // Méthodes de validation de champs
    public boolean isNomValide(String nom){
        return nom.length() <= 20;    }

    public boolean isNbGrammesValide(int nbGrammes){
        return (nbGrammes >= 100 && nbGrammes < 2000);    }

    public boolean isDegresCuissonValide(int degresCuisson){
        return (degresCuisson >= 200 && degresCuisson <= 500);    }

    public boolean isMinutesCuissonValide(int minutesCuisson){
        return (minutesCuisson >= 10 && minutesCuisson <= 60);    }


    // Méthodes de calculs de profit
    public double calculerProfit(){
        return this.prix - this.cout;    }

    public double calculerPrixPourProfit(double profitAttendu){
        return this.cout * (1 + profitAttendu);    }


    // Produit le texte pour les instructions de cuisson
    // Si la température ou la le temps de cuisson sont invalides, retourne une chaine vide
    // Si le code de langage n'est pas 1 ou 2, retoune une chaine vide
    // Si tout est valide, retourne une phrase d'instruction de cuisson dans le langage demandé
    public String instructionsCuisson(int codeLangage){  // codeLangage: 1 - Français, 2 = Anglais
        if (isDegresCuissonValide(this.degresCuisson) && isMinutesCuissonValide(this.minutesCuisson)){
            if(codeLangage == 1){
                return "Cuire à " + this.degresCuisson + " degrés F pour " + this.minutesCuisson + " minutes";
            }
            else if(codeLangage == 2){
                return "Cook at " + this.degresCuisson + " degrees for " + this.minutesCuisson + " minutes";
            }
            else{
                return "";
            }
        }
        else{
            return "";
        }
    }

    public void AfficherFichePlat(){
        System.out.println("========================================================================");
        System.out.println("Plat: " + this.nom + "          " + this.nbGrammes + " grammes");
        System.out.println("Cout: " + this.cout + " --- Prix: " + this.prix + "  =>  Profit: " + String.format("%.2f", this.profit));
        System.out.println("CUISSON:");
        System.out.println("FR: " + instructionsCuisson(1));
        System.out.println("EN: " + instructionsCuisson(2));
        System.out.println("========================================================================");
    }
}