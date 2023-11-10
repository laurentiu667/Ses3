package gestion_projet;

import projets.Activites;
import projets.Activites;
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
        Activites activite1 = new Activites("Linus Torvalds", "Planification", LocalDateTime.now(), LocalDateTime.now().plusMinutes(90));
        Activites activite2 = new Activites("Linus Torvalds", "Choix des classes et champs", LocalDateTime.now(), LocalDateTime.now().plusMinutes(360));
        Activites activite3 = new Activites("Bill Gates", "Graphique UML", LocalDateTime.now(), LocalDateTime.now().plusMinutes(240));

        monProjet.ajouterActivite(tache1.getNom(), activite1);
        monProjet.ajouterActivite(tache1.getNom(), activite2);
        monProjet.ajouterActivite(tache1.getNom(), activite3);

        // Codage - Classes
        Activites activite4 = new Activites("Linus Torvalds", "Planification", LocalDateTime.now(), LocalDateTime.now().plusMinutes(45));
        Activites activite5 = new Activites("Bill Gates", "Coder classe A - 2 méthodes", LocalDateTime.now(), LocalDateTime.now().plusMinutes(450));
        Activites activite6 = new Activites("Bill Gates", "Coder classe A - 1 méthode", LocalDateTime.now(), LocalDateTime.now().plusMinutes(150));
        Activites activite7 = new Activites("Steve Jobs", "Coder classe B", LocalDateTime.now(), LocalDateTime.now().plusMinutes(300));
        Activites activite8 = new Activites("Linus Torvalds", "Recherche problème - classe A", LocalDateTime.now(), LocalDateTime.now().plusMinutes(195));

        monProjet.ajouterActivite(tache2.getNom(), activite4);
        monProjet.ajouterActivite(tache2.getNom(), activite5);
        monProjet.ajouterActivite(tache2.getNom(), activite6);
        monProjet.ajouterActivite(tache2.getNom(), activite7);
        monProjet.ajouterActivite(tache2.getNom(), activite8);

        // Codage - Interface graphique
        Activites activite9 = new Activites("Linus Torvalds", "Coder classe B", LocalDateTime.now(), LocalDateTime.now().plusMinutes(180));
        Activites activite10 = new Activites("Elon Musk", "Recherche problème - classe A", LocalDateTime.now(), LocalDateTime.now().plusMinutes(555));

        monProjet.ajouterActivite(tache3.getNom(), activite9);
        monProjet.ajouterActivite(tache3.getNom(), activite10);

        monProjet.RapportProjet();
    }

}
