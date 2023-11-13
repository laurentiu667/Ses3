package jeu;
import personnages.*;

public class Joueur {
    // Champs
    private String alias;
    private PeronnageAvatar avatar;

    // Constructeur
    public Joueur(String alias, PeronnageAvatar avatar){
        this.alias = alias;
        this.avatar = avatar;
    }

    // Méthodes d'accès (getters)
    public String getAlias() {
        return alias;
    }
    public PeronnageAvatar getAvatar() {
        return avatar;
    }

    // Méthodes de mutation (setters)
    public void setAlias(String alias) {
        this.alias = alias;
    }

}
