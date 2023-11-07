package projets;

public class Projets {

    private String nom;
    private long minutesAllouees;
    private long minutesDepensees;
    private Taches[] listeDesTaches;
    private final int TAILLE_TABLEAU_TACHES = 10;

    public Projets(String nom, long minutesAllouees) {
        this.nom = nom;
        this.minutesAllouees = minutesAllouees;
        this.minutesDepensees = 0;
        this.listeDesTaches = new Taches[TAILLE_TABLEAU_TACHES];
        for (int i = 0; i < TAILLE_TABLEAU_TACHES; i++) {
            listeDesTaches[i] = new Taches("");
        }
    }

    public int nombreTachesDansProjet() {
        int count = 0;
        for (Taches tache : listeDesTaches) {
            if (!tache.getNom().isEmpty()) {
                count++;
            }
        }
        return count;
    }
    public void ajouterTache(Taches tache) {
        for (int i = 0; i < listeDesTaches.length; i++) {
            if (listeDesTaches[i].getNom().isEmpty()) {
                listeDesTaches[i] = tache;
                i = listeDesTaches.length;
            }
        }
        mettreAJourMinutesDepensees();
    }
    public int trouverPositionTache(String nomTache) {
        for (int i = 0; i < listeDesTaches.length; i++) {
            if (listeDesTaches[i].getNom().equals(nomTache)) {
                return i;
            }
        }
        return -1;
    }
    public void ajouterActivitesProjet(String nomTache, Activite activite){
        int index = trouverPositionTache(nomTache);
        listeDesTaches[index].ajouterActivites(activite);
        mettreAJourMinutesDepensees();
    }

    public void mettreAJourMinutesDepensees() {
        long totalMinutes = 0;
        for (Taches tache : listeDesTaches) {
            totalMinutes += tache.getTempsDepense();
        }
        this.minutesDepensees = totalMinutes;
    }
    public void RapportProjet() {
        System.out.println("Rapport: " + nom);
        System.out.println("Temps alloué : " + (minutesAllouees / 60) + " heures");
        System.out.println("Temps dépensé : " + (minutesDepensees / 60) + " heures");
        if (minutesAllouees < minutesDepensees){
            System.out.println("\n ATTENTION : Vous avez dépensé beaucoup trop de temps sur le projet\n");
        }

        for (Taches tache : listeDesTaches) {
            if (!tache.getNom().isEmpty()) {
                System.out.println("\nTâche : " + tache.getNom());
                long tempsDepenseTache = tache.getTempsDepense();
                System.out.println("Temps dépensé sur la tâche : " + (tempsDepenseTache / 60) + " heures " + (tempsDepenseTache % 60) + " minutes");

                for (Activite activite : tache.getListeDesActivites()) {
                    if (!activite.getNom().isEmpty()) {
                        long dureeActivite = activite.calculerMinutesActivite();
                        System.out.println("Activité : " + activite.getNom() + " | Durée : " + (dureeActivite / 60) + " heures " + (dureeActivite % 60) + " minutes");
                    }
                }
            }
        }
    }

}
