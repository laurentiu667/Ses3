package items;

// Tous les items du jeu héritent de cette classe
public abstract class Item {
    // Champs
    private String nom;

    // Constructeur
    public Item(String nom){
        this.nom = nom;
    }

    // Méthode d'accès (getter)
    public String getNom() {
        return nom;
    }
}
