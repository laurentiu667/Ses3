package gestion_projet;

import projets.Activite;
import projets.Projets;
import projets.Taches;

import java.time.*;

public class main {

    public static void main(String[] args) {

        Projets monProjet = new Projets("Création d'une page web dynamique", 12000); // 200 heures en minutes
        Taches tache1 = new Taches("Conception");
        Taches tache2 = new Taches("Codage - Classes");
        Taches tache3 = new Taches("Codage - Interface graphique");
        Taches tache4 = new Taches("Tests - Assurance Qualité");

        monProjet.ajouterTache(tache1);
        monProjet.ajouterTache(tache2);
        monProjet.ajouterTache(tache3);
        monProjet.ajouterTache(tache4);

        // Conception
        Activite activite1 = new Activite("Linus Torvalds", "Planification", LocalDateTime.now(), LocalDateTime.now().plusMinutes(90));
        Activite activite2 = new Activite("Linus Torvalds", "Choix des classes et champs", LocalDateTime.now(), LocalDateTime.now().plusMinutes(360));
        Activite activite3 = new Activite("Bill Gates", "Graphique UML", LocalDateTime.now(), LocalDateTime.now().plusMinutes(240));

        monProjet.ajouterActivitesProjet(tache1.getNom(), activite1);
        monProjet.ajouterActivitesProjet(tache1.getNom(), activite2);
        monProjet.ajouterActivitesProjet(tache1.getNom(), activite3);

        // Codage - Classes
        Activite activite4 = new Activite("Linus Torvalds", "Planification", LocalDateTime.now(), LocalDateTime.now().plusMinutes(45));
        Activite activite5 = new Activite("Bill Gates", "Coder classe A - 2 méthodes", LocalDateTime.now(), LocalDateTime.now().plusMinutes(450));
        Activite activite6 = new Activite("Bill Gates", "Coder classe A - 1 méthode", LocalDateTime.now(), LocalDateTime.now().plusMinutes(150));
        Activite activite7 = new Activite("Steve Jobs", "Coder classe B", LocalDateTime.now(), LocalDateTime.now().plusMinutes(300));
        Activite activite8 = new Activite("Linus Torvalds", "Recherche problème - classe A", LocalDateTime.now(), LocalDateTime.now().plusMinutes(195));

        monProjet.ajouterActivitesProjet(tache2.getNom(), activite4);
        monProjet.ajouterActivitesProjet(tache2.getNom(), activite5);
        monProjet.ajouterActivitesProjet(tache2.getNom(), activite6);
        monProjet.ajouterActivitesProjet(tache2.getNom(), activite7);
        monProjet.ajouterActivitesProjet(tache2.getNom(), activite8);

        // Codage - Interface graphique
        Activite activite9 = new Activite("Linus Torvalds", "Coder classe B", LocalDateTime.now(), LocalDateTime.now().plusMinutes(180));
        Activite activite10 = new Activite("Elon Musk", "Recherche problème - classe A", LocalDateTime.now(), LocalDateTime.now().plusMinutes(555));

        monProjet.ajouterActivitesProjet(tache3.getNom(), activite9);
        monProjet.ajouterActivitesProjet(tache3.getNom(), activite10);

        monProjet.RapportProjet();
    }

}
