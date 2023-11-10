package projets;
import com.sun.source.tree.NewArrayTree;

import java.time.*;
import java.util.List;

public class Taches {
    final private int TABLEAU_TAILLE = 10;

    private String nom;
    private long tempsDepenser;
    private Activites[] activites = new Activites[TABLEAU_TAILLE];

    public Taches(String nom){
        this.nom = nom;
        this.tempsDepenser = 0;
        for (int i = 0; i < activites.length; i++){
            activites[i] =  new Activites("", "",
                    LocalDateTime.of(2000,1,1,0,0),
                    LocalDateTime.of(2000,1,1,0,0));
        }
    }

    public int trouverNbrActiviter(){
        int count = 0;
        for (Activites a : activites){
            if (!a.getNom().isEmpty()){
                count++;
            }
        }
        return count;
    }
    public void ajouterActiviter(Activites activitesAjouter) {
        if (trouverNbrActiviter() < TABLEAU_TAILLE){
            for (int i = 0; i < activites.length; i++){
                if (activites[i].getNom().isEmpty()){
                    activites[i] = activitesAjouter;
                    break;
                }
            }
            tempsDepenser = 0;
            for (Activites act : activites){
                tempsDepenser += act.minuteDepenser();
            }
        }
    }

    public String getNom() {
        return nom;
    }

    public long getTempsDepenser() {
        return tempsDepenser;
    }

    public Activites[] getActivites() {
        return activites;
    }
}
