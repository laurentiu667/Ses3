package projets;

public class Projets {

    private final int TAILLE = 10;

    private String nom;
    private long minuteAllouer;
    private long minutedepenser;

    private Taches[] listeTache;

    public Projets(String nom, long minuteAllouer){
        this.nom = nom;
        this.minuteAllouer = minuteAllouer;
        this.minutedepenser = 0;
        this.listeTache = new Taches[TAILLE];
        for (int i = 0; i < listeTache.length; i++){
            listeTache[i] = new Taches("");
        }
    }

    public int trouverNombreTaches(){
        int nombre = 0 ;
        for (Taches t : listeTache) {
            if (!t.getNom().isEmpty()){
                nombre++;
            }
        }
        return nombre;
    }

    public void ajouterTache(Taches taches){
        if (trouverNombreTaches() < TAILLE){
            for (int i = 0; i < listeTache.length; i++){
                if (listeTache[i].getNom().isEmpty()){
                    listeTache[i] = taches;
                    break;
                }
            }
        }
    }
    public int trouverPosTache(String tache){

        for (int i = 0; i < listeTache.length; i++){
            if (listeTache[i].getNom().equals(tache)){
                return i;
            }
        }
        return -1;
    }

    public void ajouterActivite(String nomTaches, Activites activites){
        int index = trouverPosTache(nomTaches);
        listeTache[index].ajouterActiviter(activites);
        mettreAjourTemps();
    }

    public void mettreAjourTemps(){
        long totalTemps = 0;
        for (Taches t : listeTache){
            totalTemps += t.getTempsDepenser();
        }
        this.minutedepenser = totalTemps;
    }
    public void RapportProjet() {
        System.out.println("Rapport: " + nom);
        System.out.println("Temps alloué : " + (minuteAllouer / 60) + " heures");
        System.out.println("Temps dépensé : " + (minutedepenser / 60) + " heures");
        if (minuteAllouer < minutedepenser){
            System.out.println("\n ATTENTION : Vous avez dépensé beaucoup trop de temps sur le projet\n");
        }

        for (Taches tache : listeTache) {
            if (!tache.getNom().isEmpty()) {
                System.out.println("\nTâche : " + tache.getNom());
                long tempsDepenseTache = tache.getTempsDepenser();
                System.out.println("Temps dépensé sur la tâche : " + (tempsDepenseTache / 60) + " heures " + (tempsDepenseTache % 60) + " minutes");

                for (Activites act : tache.getActivites()) {
                    if (!act.getNom().isEmpty()) {
                        long dureeActivite = act.minuteDepenser();
                        System.out.println("Activité : " + act.getNom() + " | Durée : " + (dureeActivite / 60) + " heures " + (dureeActivite % 60) + " minutes");
                    }
                }
            }
        }
    }
}
