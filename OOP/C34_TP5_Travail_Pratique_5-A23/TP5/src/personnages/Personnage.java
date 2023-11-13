package personnages;
import items.*;         // Pour Arme, Armure et Capacite

public class Personnage{

    // Champs
    private String nom;         // Nom du personnage
    private int sante;          // Nombre de points de vie du personnage, 0 = vaincu!
    private Arme arme;          // Cause des dommages, réduit par les points de défense de l'armure adverse
    private Armure armure;      // Réduit les dommages reçus par les attaques physiques
    private Capacite capacite;  // Attaque magique - n'est pas afffectée par l'armure adverse

    // Constructeur (constructeur par défaut non permis)
    public Personnage(String nom, int sante){
        this.nom = nom;
        this.sante = sante;
        // ******** Décommenter ci-dessous après que les items soient complétés ********
        //Arme sansArme = new Arme("Sans arme", 0, 0);
        //this.arme = sansArme;
        //Armure sansArmure = new Armure("Sans armure", 0, 0);
        //this.armure = sansArmure;
        //Capacite sansCapacite = new Capacite("Sans capacite", 0, 0);
        //this.capacite = sansCapacite;
    }

    // Méthodes d'accès (getters)
    public String getNom() { return nom; }
    public int getSante() { return sante; }
    public Arme getArme() { return arme; }
    public Armure getArmure() { return armure; }
    public Capacite getCapacite() { return capacite; }

    // Méthodes de mutation (setters)
    public void setSante(int sante) { this.sante = sante; }
    public void setArme(Arme arme) { this.arme = arme; }
    public void setArmure(Armure armure) { this.armure = armure; }
    public void setCapacite(Capacite capacite) { this.capacite = capacite; }

    // estVivant si santé > 0
    public boolean estVivant(){
        return sante > 0;
    }
}
