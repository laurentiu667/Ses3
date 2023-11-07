package projets;

import java.time.LocalDateTime;

public class Taches {
    private final int TAILLE_TABLEAU_ACTIVITES = 10;
    private String nom;
    private long tempsDepense;
    private Activite[] listeDesActivites;

    public Taches(String nom) {
        this.nom = nom;
        this.tempsDepense = 0;
        this.listeDesActivites = new Activite[TAILLE_TABLEAU_ACTIVITES];
        for (int i = 0; i < TAILLE_TABLEAU_ACTIVITES; i++) {
            listeDesActivites[i] = new Activite("", "",
                    LocalDateTime.of(2000, 1, 1, 0, 0),
                    LocalDateTime.of(2000, 1, 1, 0, 0));
        }
    }

    public int nombreActivitesPresentes() {
        int increment = 0;
        for (Activite activite : listeDesActivites){
            if (!activite.getNom().isEmpty()){
                increment++;
            }
        }
        return increment;
    }

    public void ajouterActivites(Activite activite) {
        if (nombreActivitesPresentes() < TAILLE_TABLEAU_ACTIVITES) {
            for (int i = 0; i < listeDesActivites.length; i++) {
                if (listeDesActivites[i].getNom().isEmpty()) {
                    listeDesActivites[i] = activite;
                    break;
                }
            }
            tempsDepense = 0;
            for (Activite act : listeDesActivites) {
                tempsDepense += act.calculerMinutesActivite();
            }
        }
    }

    public String getNom() {
        return nom;
    }

    public long getTempsDepense() {
        return tempsDepense;
    }

    public Activite[] getListeDesActivites() {
        return listeDesActivites;
    }
}
